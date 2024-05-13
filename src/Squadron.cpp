#include "Squadron.h"

Squadron::Squadron(EnemyType enemyType, const Time timeStamp, const float count, const Vector2f spawnPosition, const float horizontalDistanceApart) :
	m_enemyType(enemyType),
	m_timeStamp(timeStamp),
	m_count(count),
	m_spawnPosition(spawnPosition),
	m_horizontalDistanceApart(horizontalDistanceApart)
{
}
