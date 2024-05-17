#include "EnemyManager.h"
#include "PickupManager.h"
#include "random"

EnemyManager::EnemyManager(Player& player, const RenderWindow& renderWindowConstant, PickupManager& pickupManager) : 
	m_player(player),
	m_renderWindowConstant(renderWindowConstant),
	m_pickupManager(&pickupManager),
	m_timer(seconds(0))
{
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
	Spawner(deltaTime, totalTimeElapsed);
	Trackable* closestTrackable = nullptr;
	float smallestDistance = 0;
	auto homingMissiles = m_player.GetNonTrackingHomingMissiles();
 	for (HomingMissile* homingMissile : homingMissiles)
	{
		for (Enemy* enemy : m_enemies) 
		{
			float distance = getDistanceBetweenVectors(homingMissile->GetHitboxPosition().getMiddlePosition(), enemy->GetTrackablePosition().getMiddlePosition());
			if (!enemy->MarkedAsTracked() && (distance < smallestDistance || smallestDistance == 0)) 
			{
				closestTrackable = enemy;
				smallestDistance = distance;
			}
		}
		if (homingMissile->TrackingStatus() == false && closestTrackable != nullptr)
		{
			bool t = homingMissile->TrackingStatus();
			closestTrackable->MarkAsTracked();
			homingMissile->SetTrackable(closestTrackable);
		}
		closestTrackable = nullptr;
	}
	
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
		if (enemy->MarkedAsDead() && !enemy->MarkedAsIgnore()) 
		{
			enemy->MarkAsIgnore();
			m_pickupManager->CreatePickup(PickupType::BATTERY, enemy->GetHitboxPosition().getMiddlePosition());
		}
		AssignTrackables(enemy);
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
	
	for (int index = 0; index < squadron.m_count; index++) 
	{
		switch (squadron.m_enemyType)
		{
		case EnemyType::Grunt:
			m_enemies.push_back(new EnemyGrunt(m_player, Vector2f(squadron.m_spawnPosition.x + squadron.m_horizontalDistanceApart * index, squadron.m_spawnPosition.y), m_renderWindowConstant));
			break;
		case EnemyType::Trooper: // should really have it's own squadron type this is very messy
			float trooperSpeed = 100;
			float trooperRotationSpeed = 100;
			Vector2f f = Vector2f(squadron.m_spawnPosition.x + squadron.m_horizontalDistanceApart * index, squadron.m_spawnPosition.y);
			//m_enemies.push_back(new EnemyTrooper(m_player, f, m_renderWindowConstant, trooperSpeed, trooperRotationSpeed));
			break;
		}
	}
}

void EnemyManager::Despawn()
{
	DespawnEnemies();
	DespawnEnemyProjectiles();
}
void EnemyManager::AssignTrackables(Enemy* enemy)
{
	
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

void EnemyManager::Spawner(const Time deltaTime, const Time totalTimeElapsed)
{
	std::random_device rd;
	uniform_int_distribution<int> distHeight(100, 200);
	uniform_real_distribution<float> distTime(0, 3);
	uniform_real_distribution<float> distCount(2, 4);
	uniform_int_distribution<int> distType(0, 1);
	uniform_int_distribution<int> distDistance(40, 60);
	float height = distHeight(rd);
	float time = distTime(rd);
	float distance = distDistance(rd);
	float count = distCount(rd);
	EnemyType type;
	if (distType(rd) == 1)
	{
		type = EnemyType::Trooper;
	}
	else
		type = EnemyType::Grunt;
	m_squadrons.push(Squadron(type, seconds(time), count, Vector2f(600, height), distance));
}

