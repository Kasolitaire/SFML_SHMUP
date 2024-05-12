#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
enum EnemyType {Grunt, Trooper, Commander}; // idk just made up for now !!!
struct Squadron 
{
	Squadron(EnemyType enemyType, const Time timeStamp, const float count, const float spawnHeight, const float horizontalDistanceApart);
	const Time m_timeStamp;
	const float m_count;
	const float m_spawnHeight;
	float m_horizontalDistanceApart;
	EnemyType m_enemyType;
};
