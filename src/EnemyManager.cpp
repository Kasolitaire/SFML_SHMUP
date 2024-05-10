#include "EnemyManager.h";

EnemyManager::EnemyManager(Player& player) : m_player(player)
{
	m_squadrons.push(Squadron(Time(), 5, 100, 100));
	m_squadrons.push(Squadron(seconds(7), 5, 100, 100));
	m_squadrons.push(Squadron(seconds(7), 5, 100, 100));
}

void EnemyManager::Update(const Time deltaTime, const Time totalTimeElapsed)
{
	m_timer += deltaTime;

	if (!m_squadrons.empty() && m_timer >= m_squadrons.back().m_timeStamp)
	{
		SpawnSquadron(m_squadrons.back());
		m_squadrons.pop();
		m_timer = Time();
	}

	for (Enemy& enemy : m_enemies) 
	{
		enemy.Update(deltaTime, totalTimeElapsed);
	}
}

void EnemyManager::draw(RenderTarget& target, RenderStates states) const
{
	for (auto& enemy : m_enemies)
	{
		enemy.draw(target, states);
	}
}

void EnemyManager::SpawnSquadron(Squadron squadron)
{
	float x = 500; // placeholder !!!
	for (int index = 0; index < squadron.m_count; index++) 
	{
		m_enemies.push_back(Enemy(m_player, Vector2f(x + squadron.m_horizontalDistanceApart * index, squadron.m_spawnHeight)));
	}
}
