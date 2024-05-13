#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
enum EnemyType {Grunt, Trooper, Commander}; // idk just made up for now !!!
struct Squadron 
{
	Squadron(EnemyType enemyType, const Time timeStamp, const float count, const Vector2f spawnPosition, const float horizontalDistanceApart);
	const Time m_timeStamp;
	const float m_count;
	const Vector2f m_spawnPosition;
	const float m_horizontalDistanceApart;
	const EnemyType m_enemyType;
};
