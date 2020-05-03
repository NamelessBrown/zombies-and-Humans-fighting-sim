#pragma once

class Zombie
{
public:
	Zombie() = default;
	Zombie(const int health, const int attackDamage)
		:m_health(health), m_attackDamage(attackDamage)
	{
	}

	void SetHealth(int health) { m_health -= health; } //Substracts from the orignal

	const int& GetHealth() const { return m_health; }
	const int& GetAttackDamage() const { return m_attackDamage; }

private:
	int m_health;
	int m_attackDamage;
};

