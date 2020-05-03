#include "Game.h"
#include <fstream>
#include <iostream>

Settings::Settings(const std::string& filename)
{
	std::ifstream inFile(filename);

	for (std::string line; std::getline(inFile, line);)
	{
		if (line == "[Spawn Humans]")
		{
			inFile >> m_spawnHumans;
		}
		else if (line == "[Humans health]")
		{
			inFile >> m_humanHealth;
		}
		else if (line == "[Humans attack damage]")
		{
			inFile >> m_humanAttackDamage;
		}
		else if (line == "[Spawn Zombies]")
		{
			inFile >> m_spawnZombie;
		}
		else if (line == "[Zombies health]")
		{
			inFile >> m_ZombieHealth;
		}
		else if(line == "[Zombies attack damage]")
		{
			inFile >> m_ZombieAttackDamage;
		}
	}

}

Game::Game()
	:m_settings("config.txt")
{
	m_humans.resize(m_settings.m_spawnHumans);
	m_zombies.resize(m_settings.m_spawnZombie);

	for (auto& e : m_humans)
	{
		e = Humans(m_settings.m_humanHealth, m_settings.m_humanAttackDamage);
	}

	for (auto& i : m_zombies)
	{
		i = Zombie(m_settings.m_ZombieHealth, m_settings.m_ZombieAttackDamage);
	}

}

void Game::Fight()
{
	while (!m_humans.empty() && !m_zombies.empty())
	{
		for (unsigned i = 0; i < m_humans.size() && i < m_zombies.size(); i++)
		{
			//Humans hit first!
			std::cout << "There are: " << m_humans.size() << " humans. There are: " << m_zombies.size() << " zombies." << '\n';
			std::cout << i + 1 << " human hit the " << i + 1 << " zombie for " << m_humans[i].GetAttackDamage() << " damage!\n";
			m_zombies[i].SetHealth(m_humans[i].GetAttackDamage());
			std::cout << "The zombie health is now " << m_zombies[i].GetHealth() << "!\n";

			//zombies hit second
			std::cout << "The zombies take a strike at the human! The zombie hits human for " << m_zombies[i].GetAttackDamage() << '\n';
			m_humans[i].SetHealth(m_zombies[i].GetAttackDamage());
			std::cout << "The human health is now " << m_humans[i].GetHealth() << '\n';


			//Health at zero? get rid of them!
			if (m_humans[i].GetHealth() <= 0)
			{
				m_humans.erase(m_humans.begin() + i);
			}

			if (m_zombies[i].GetHealth() <= 0)
			{
				m_zombies.erase(m_zombies.begin() + i);
			}

			std::cout << "Press [Enter] to continue...\n";
			std::cin.ignore();
			system("cls");
		}
	}

	if (!m_humans.empty())
	{
		std::cout << "Humans won!\n";
	}
	else
	{
		std::cout << "Zombies won!\n";
	}


	std::cout << "Press [Enter] to continue...\n";
	std::cin.ignore();
	system("cls");
}
