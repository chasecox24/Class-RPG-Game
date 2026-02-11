// NOTES:
// Use : for each of the private, protected, and public
// Constructor: asets all the variables found inside the class and children classes
// Inside the constructor, we initialize all the member variables.

#include <iostream>

class Character
{
private: // dont touch my privates NOOB DEV

protected:// my kids need my money when I die
	int maxHealth;
	int health;
	int armor;
	int damage;
	int gold;

public:// everyone can have some
	Character(int mh, int ar, int dmg, int gd) // CONSTRUCTOR
	{
		maxHealth = mh;
		health = maxHealth; // start full of HP
		armor = ar;
		damage = dmg;
		gold = gd;
	}

	void takeDamage(int damageAmount)
	{
		if (armor > damageAmount)
			return;
		else
		health = health - (damageAmount - armor);
		if (health <= 0)
			gold += 2;
	}

	void healHealth(int healAmount)
	{
		health += healAmount;
		if (health > maxHealth)
				health = maxHealth;
	}
};

//WARRIOR
class Warrior : public Character
{
public:
	Warrior() : Character(150, 50, 20, 5) {} // : Character(150, 50, 20) calls the base constructor to initialize Character’s stats
};

//MAGE
class Mage : public Character
{
public:
	Mage() : Character(100, 10, 35, 10) {}
};

//ARCHER
class Archer : public Character
{
public:
	Archer() : Character(125, 30, 25, 15) {}
};

int main()
{
	return 0;
}
