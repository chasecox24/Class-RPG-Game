// NOTES:
// Use : for each of the private, protected, and public
// Constructor: asets all the variables found inside the class and children classes
// Inside the constructor, we initialize all the member variables.

#include <iostream>
#include <ctime>
#include <conio.h>  // Windows-only for _kbhit() and _getch()

//this is spart... heirarchy!!
//since the base character class contains all the stats and functions
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

	void attack(Character& target) // Character &target, passes another character by reference so we can modify their stats directly.
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
		{
			actualDamage = 0;
			health -= actualDamage;
		}
		if (health < 0) health = 0; // this clamps the health to 0
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
	std::string className;

	//nullptr means “This pointer doesn’t point to anything.”
	//nullptr is a safe way to initialize pointers before they are assigned a real object.
	//without it 1/2 = At this point, player could point anywhere in memory.
	//without it 2/2 = Using it without assigning an object can crash your program.
	Character* player = nullptr; //Character* allows us to store any subclass in one variable. This is polymorphism
	choice;

	std::cout << "Choose your class:\n";
	std::cout << "1. Warrior\n2. Mage\n3. Archer\n";

	while (true)//waits for input(will run forever)
	{
		if (_kbhit()) // a key was pressed
		{
			choice = _getch(); // read it immediately
			//using the choice to set the player as a class and saving a class name that will be used later
			if (choice == '1') { player = new Warrior(); className = "Warrior"; break; }
			else if (choice == '2') { player = new Mage(); className = "Mage"; break; }
			else if (choice == '3') { player = new Archer(); className = "Archer"; break; }
			// ignore other keys
		}
	}
	//DISPLAY CLASS
	std::cout << "\nClass chosen!\n";
	std::cout << "You have chosen the " << className << " class!\n";


	//GAME LOGIC
	std::cout << "Press 'w' to walk, 'q' to quit:\n";
	while (true) // waits for the player to press a valid key
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
				break;//exits loop
			}
		}
	}
	//If we don’t delete it, that memory stays allocated even after main() ends — this is called a memory leak.
	//delete also calls the destructor for the object
	//Every time you use new, you should eventually use delete.
	delete player; // frees the memory//memory management
	player = nullptr; // avoid dangling pointer // points to nothing
	return 0;
}