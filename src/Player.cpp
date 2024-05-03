#include "Player.h"

Player::Player(const Vector2f& spawnPosition, const RenderWindow& renderWindowConstant) : HitboxEntity(renderWindowConstant), m_speed(5) // refactor !!!
{
	m_hitbox.setFillColor(Color::Transparent);
	m_hitbox.setOutlineColor(Color::Green);
	m_hitbox.setOutlineThickness(0.5);
	m_hitbox.setSize(Vector2f(28, 12));

	Texture& texture = AssetManager::GetTexture(ASSETS_PATH + "ship.png");
	m_sprite.setTexture(texture);
	m_sprite.setScale(0.9, 0.9);
	//m_sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
	m_sprite.setPosition(spawnPosition);
	
}

void Player::HandleInputs()
{	
	m_mousePosition = Vector2f(m_renderWindowConstant->mapPixelToCoords(Mouse::getPosition(*m_renderWindowConstant)));
}

void Player::Update(const Time& deltaTime, const Time& totalTimeElapsed)
{
	Vector2f viewSizeVec = m_renderWindowConstant->getView().getSize();
	Vector2f vec = VectorLerp(m_sprite.getPosition(), m_mousePosition, m_speed * deltaTime.asSeconds());
	if(!(vec.x >= viewSizeVec.x || vec.y >= viewSizeVec.y || vec.x <= 0|| vec.y <= 0)) // doesnt work very well !!!
		m_sprite.setPosition(vec);
	
	//consoleVector2f(m_sprite.getPosition());
	m_hitbox.setPosition(vec.x, vec.y+5);

	// update projectiles

	for (auto& projectile : m_projectiles) projectile.Update(deltaTime, totalTimeElapsed);
}

void Player::HandleEvents(const Event& event)
{
	if (event.key.code == Keyboard::Space && event.KeyReleased == Event::KeyReleased)
		m_projectiles.push_back(Projectile(Vector2f(m_sprite.getPosition()), 500, *m_renderWindowConstant));
}

void Player::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(m_sprite);
	if(m_hitboxVisible) target.draw(m_hitbox);
	for (auto& projectile : m_projectiles) projectile.draw(target, states);
}

void Player::SpawnProjectile()
{
}
