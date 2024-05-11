#include "EnemyManager.h";

EnemyManager::EnemyManager(Player& player) : 
	m_player(player),
	m_timer(Time())

{
	m_squadrons.push(Squadron(Time(), 5, 100, 100));
	m_squadrons.push(Squadron(seconds(2.5), 2, 60, 100));
	m_squadrons.push(Squadron(seconds(6), 5, 50, 100));
	m_squadrons.push(Squadron(seconds(6), 5, 75, 100));
}

EnemyManager::~EnemyManager()
{
	for (Enemy* enemy : m_enemies) 
	{
		delete enemy;
	}
}

void EnemyManager::Update(const Time deltaTime, const Time totalTimeElapsed)
{
	m_timer += deltaTime;

	if (!m_squadrons.empty() && m_timer >= m_squadrons.front().m_timeStamp)
	{
		SpawnSquadron(m_squadrons.front());
		m_squadrons.pop();
		if(m_squadrons.empty()) m_timer = seconds(0);
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
		m_enemies.push_back(new EnemyGrunt(m_player, Vector2f(x + squadron.m_horizontalDistanceApart * index, squadron.m_spawnHeight)));
	}
}

void EnemyManager::Despawn()
{
	std::erase_if(m_enemies, [](Enemy* x) 
		{
			if (x->MarkedForDespawn()) 
			{
				delete x;
				return true;
			}
			return false;
		});
} 
