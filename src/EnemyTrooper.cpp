#include "EnemyTrooper.h"

EnemyTrooper::EnemyTrooper(Player& player, Vector2f spawnPosition, const RenderWindow& renderWindowConstant , const float speed, const float rotationSpeed) : 
	Enemy(player, spawnPosition, renderWindowConstant),
	m_speed(speed),
	m_rotationSpeed(rotationSpeed)
{
	Texture& texture = AssetManager::GetTexture(ASSETS_PATH + "darkgrey_02.png");
	m_sprite.setTexture(texture);
	m_sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	m_hitbox.setSize(Vector2f(texture.getSize().x, texture.getSize().y));
	m_sprite.setPosition(spawnPosition);
	ToggleHitBox(true);
	m_hitbox.setPosition(m_sprite.getPosition());
	m_hitbox.setOrigin(m_hitbox.getSize().x / 2, m_hitbox.getSize().y / 2);
	m_hitbox.setFillColor(Color::Transparent);
	m_hitbox.setOutlineThickness(0.5f);
	m_hitbox.setOutlineColor(Color::Green);
}

EnemyTrooper::~EnemyTrooper()
{
	std::cout << "enemy trooper destructor" << endl;
}

void EnemyTrooper::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	FloatRect hitboxRect = m_player.GetHitboxPosition();
	Vector2f playerHitboxCenter(hitboxRect.left + hitboxRect.width / 2, hitboxRect.top + hitboxRect.height / 2);
	
	// movement logic
	float rotation = getAngleToTarget(playerHitboxCenter, m_sprite.getPosition());
	float target = rotation < 0 ? 360 + rotation : rotation;

	float cw_distance;
	float ccw_distance;
	float increment;
	float x = 0;
	float y = 0;
	float current = m_sprite.getRotation();
	if (current - target > 0)
	{
		cw_distance = abs(current - target);
		ccw_distance = 360 - cw_distance;
	}
	else
	{
		ccw_distance = abs(current - target);
		cw_distance = 360 - ccw_distance;
	}

	if (cw_distance < ccw_distance) //move clockwise
	{
		increment = (m_sprite.getRotation() - m_rotationSpeed * deltaTime.asSeconds());
		m_sprite.setRotation(increment);

		y = cosf(degreesToRadians(increment - 90)) * deltaTime.asSeconds() * m_speed;
		x = -sinf(degreesToRadians(increment - 90)) * deltaTime.asSeconds() * m_speed;
	}
	else
	{
		increment = m_sprite.getRotation() + m_rotationSpeed * deltaTime.asSeconds();
		m_sprite.setRotation(increment);

		y = cosf(degreesToRadians(increment - 90)) * deltaTime.asSeconds() * m_speed;
		x = -sinf(degreesToRadians(increment - 90)) * deltaTime.asSeconds() * m_speed;
	}

	m_sprite.move(x, y);

	// shooting logic
	if (totalTimeElapsed - m_firedTimeStamp >= seconds(0.4f))
	{
		m_firedTimeStamp = totalTimeElapsed;
		m_directionalProjectiles.push_back(
			DirectionalProjectile(
				m_sprite.getPosition(),
				*m_renderWindowConstant,
				totalTimeElapsed,
				150 + m_speed,
				increment - 90
			));
	}

	for (DirectionalProjectile& projectile : m_directionalProjectiles) 
	{
		projectile.Update(deltaTime, totalTimeElapsed);
		if (projectile.CheckForIntersection(m_player.GetHitboxPosition()))
			projectile.MarkForDespawn();

		View view = m_renderWindowConstant->getView();
		FloatRect floatRectWindow = FloatRect(0, 0, view.getSize().x, view.getSize().y);
		if (!projectile.CheckForIntersection(floatRectWindow))
			projectile.MarkForDespawn();
	}
}

void EnemyTrooper::draw(RenderTarget& target, RenderStates states) const
{
	for (const DirectionalProjectile& projectile : m_directionalProjectiles) projectile.draw(target, states);
	Enemy::draw(target, states);
}

void EnemyTrooper::DespawnProjectiles()
{
	std::erase_if(m_directionalProjectiles, [](DirectionalProjectile& projectile) {return projectile.MarkedForDespawn();});
}
