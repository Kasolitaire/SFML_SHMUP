#include "Squadron.h"

Squadron::Squadron(const Time timeStamp, const float count, const float spawnHeight, const float horizontalDistanceApart) :
	m_timeStamp(timeStamp),
	m_count(count),
	m_spawnHeight(spawnHeight),
	m_horizontalDistanceApart(horizontalDistanceApart)
{
}
