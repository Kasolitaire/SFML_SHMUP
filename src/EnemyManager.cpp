#include "EnemyManager.h";

EnemyManager::EnemyManager(Player& player, const RenderWindow& renderWindowConstant) : 
	m_player(player),
	m_renderWindowConstant(renderWindowConstant),
	m_timer(Time())

{
	m_squadrons.push(Squadron(EnemyType::Trooper, seconds(0), 5, Vector2f(0, 60), 100));
	m_squadrons.push(Squadron(EnemyType::Grunt, Time(), 5, Vector2f(0, 50), 100));
	m_squadrons.push(Squadron(EnemyType::Grunt, seconds(2.5), 2, Vector2f(0, 60), 100));
	m_squadrons.push(Squadron(EnemyType::Grunt, seconds(6), 5, Vector2f(0, 75), 100));
	m_squadrons.push(Squadron(EnemyType::Grunt, seconds(6), 5, Vector2f(0, 60), 100));
	m_squadrons.push(Squadron(EnemyType::Trooper, seconds(6), 5, Vector2f(0, 20), 100));
	m_squadrons.push(Squadron(EnemyType::Grunt, seconds(6), 5, Vector2f(0, 60), 100));

}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::Update(const Time deltaTime, const Time totalTimeElapsed)
{
	m_timer += deltaTime;
	if (!m_squadrons.empty() && m_timer >= m_squadrons.front().m_timeStamp)
	{
		SpawnSquadron(m_squadrons.front());
		m_squadrons.pop();
		m_timer = seconds(0);
	}

	for (Enemy* enemy : m_enemies) 
	{
		enemy->Update(deltaTime, totalTimeElapsed);
	}
}

void EnemyManager::draw(RenderTarget& target, RenderStates states) const
{
	for (Enemy* enemy : m_enemies)
	{
		enemy->draw(target, states);
	}
}

void EnemyManager::SpawnSquadron(Squadron squadron)
{
	float x = 500; // placeholder !!!
	for (int index = 0; index < squadron.m_count; index++) 
	{
		switch (squadron.m_enemyType)
		{
		case EnemyType::Grunt:
			m_enemies.push_back(new EnemyGrunt(m_player, Vector2f(x + squadron.m_horizontalDistanceApart * index, squadron.m_spawnPosition.y), m_renderWindowConstant));
			break;
		case EnemyType::Trooper: // should really have it's own squadron type this is very messy
			float trooperSpeed = 100;
			float trooperRotationSpeed = 100;
			Vector2f f = Vector2f(x + squadron.m_horizontalDistanceApart * index, squadron.m_spawnPosition.y);
			m_enemies.push_back(new EnemyTrooper(m_player, f, m_renderWindowConstant, trooperSpeed, trooperRotationSpeed));
			break;
		}
	}
}

void EnemyManager::Despawn()
{
	DespawnEnemies();
	DespawnEnemyProjectiles();
}
void EnemyManager::DespawnEnemies()
{
	std::erase_if(m_enemies, [](Enemy* enemy)
		{
			if (enemy->MarkedForDespawn())
			{
				delete enemy;
				return true;
			}
			return false;
		});
}

void EnemyManager::DespawnEnemyProjectiles()
{
	for (Enemy* enemy : m_enemies)
	{
		if (typeid(*enemy) == typeid(EnemyTrooper))
			dynamic_cast<EnemyTrooper*>(enemy)->DespawnProjectiles();
	}
}

