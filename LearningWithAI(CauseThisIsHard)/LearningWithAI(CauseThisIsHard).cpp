// NOTES:
// Use : for each of the private, protected, and public
// Constructor: asets all the variables found inside the class and children classes
// Inside the constructor, we initialize all the member variables.

#include <iostream>
#include <ctime>
#include <conio.h>  // Windows-only for _kbhit() and _getch()

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

	void printStats()
	{
		std::cout << "Health: " << health << "/" << maxHealth
			<< " | Armor: " << armor
			<< " | Damage: " << damage
			<< " | Gold: " << gold << std::endl;

	}

	void attack(Character &target) // Character &target, passes another character by reference so we can modify their stats directly.
	{
		int actualDamage = damage - target.armor; //function looks like warrior.attack(mage) this is passing a copy of the damage value from warrior into this funciton
		if (actualDamage < 0) // prevents healing the enemy
			actualDamage = 0;

		target.health -= actualDamage;

		if (target.health < 0)
			target.health = 0; //just capping it

		std::cout << "Attacked for " << actualDamage
			<< " damage! Target health is now "
			<< target.health << "/" << target.maxHealth << std::endl;
	}

	void takeDamage(int damageAmount)
	{
		int actualDamage = damageAmount - armor; // this int will check if real damage has accured
		if (actualDamage < 0)
			health -= actualDamage;

		if (health <= 0) health = 0; // this clamps the health to 0
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

//MAIN
int main()
{
	// Declaration
	int choice;
	char action;
	int floor = 0;

	Character* player = nullptr; //Character* allows us to store any subclass in one variable. This is polymorphism
	choice;

	std::cout << "Choose your class:\n";
	std::cout << "1. Warrior\n2. Mage\n3. Archer\n";
	std::cin >> choice;

	//if else chain
	if (choice == 1)
		player = new Warrior();
	else if (choice == 2)
		player = new Mage();
	else if (choice == 3)
		player = new Archer();
	else {
		std::cout << "Invalid choice. Defaulting to Warrior.\n";
		player = new Warrior();
	}
	std::cout << "\nClass chosen!\n";

	std::cout << "Press 'w' to walk, 'q' to quit:\n";
	while (true)
	{
		//since we handle input we do not need to tell the user invalid key entered // unless you want
		//actions will happen immeditaily after key pressed feeling more responcive
		if (_kbhit())  // check if a key was pressed
		{
			action = _getch();  // read key immediately

			if (action == 'w')
			{
				floor++;
				std::cout << "You walked to floor " << floor << std::endl;
			}
			else if (action == 'q')
			{
				std::cout << "Exiting game.\n";
				break;
			}
		}
	}


	delete player; // frees the memory
	return 0;
}