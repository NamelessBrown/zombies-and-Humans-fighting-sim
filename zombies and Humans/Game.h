#pragma once

#include <string>
#include <vector>
#include "Humans.h"
#include "Zombie.h"

struct Settings
{
public:
	Settings(const std::string& filename);
public:
	int m_spawnHumans = 0;
	int m_humanHealth = 0;
	int m_humanAttackDamage = 0;
	int m_spawnZombie = 0;
	int m_ZombieHealth = 0;
	int m_ZombieAttackDamage = 0;
};

class Game
{
public:
	Game();

	void Fight();
private:
	Settings m_settings;

	std::vector<Humans> m_humans;
	std::vector<Zombie> m_zombies;
};

