// ClassGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


// PROTOTYPES
void createPlayerCharacter();


// PARENT CLASS
class Character
{
protected: // Protected members are accessible within the class and by derived classes
	std::string name;
	int health;
	int damage;
	int armor;
	bool isAlive;

public: // public members are accessable to all
	Character() = default;
	Character(std::string mainName, int mainHealth, int mainDamage, int mainArmor, bool mainIsAlive)
	{
		name = mainName;
		health = mainHealth;
		damage = mainDamage;
		armor = mainArmor;
		isAlive = mainIsAlive;
	}

	void displayStatus() {
		std::cout << "Name: " << name << "\nHealth: " << health << "\nAttack: " << damage << "\nArmor" << armor << "\nIsAlive" << isAlive << std::endl;
	}

	//HEAL
	void healHealth(int mainHealth)
	{
		health = mainHealth;
	}

	//TAKE DAMAGE
	void takeDamage(int mainDamage)
	{
		health -= (armor - mainDamage);
		if (health <= 0) {
			isAlive = false;
			std::cout << name << " has died." << std::endl;
		}
	}

	//ATTACK
	void attack(Character& target)
	{
		if (isAlive) {
			std::cout << name << " attacks " << target.name << " for " << damage << " damage!" << std::endl;
			target.takeDamage(damage);
		}
		else {
			std::cout << name << " cannot attack because they are dead." << std::endl;
		}
	}

};

// CHILD CLASS
class Warrior : public Character
{
	Warrior() : Character("Warrior", 200, 30, 100, 1) {}
};

// CHILD CLASS
class Mage : public Character
{
	Mage() : Character("Mage", 120, 70, 50, 1) {}
};

// CHILD CLASS
class Archer : public Character
{
	Archer() : Character("Archer", 150, 50, 70, 1) {}
};


int main()
{
	//creating player
	//How do I save this function to be equal to the playerCharacter = CreatePlayerCharacter??
	createPlayerCharacter();

	//creating enemy
	Character enemy("Enemy", 200, 100, 50, 1);

	//attack
	enemy.attack(enemy);
	enemy.attack(enemy);
	enemy.attack(enemy);

	system("pause");
	return 0;
}

void createPlayerCharacter()
{
	//Variables
	std::string name;
	int health;
	int damage;
	int armor;
	bool isAlive;

	//IO stream
	std::cout << "Enter character name: ";
	std::cin >> name;
	std::cout << "Enter character health: ";
	std::cin >> health;
	std::cout << "Enter character attack damage: ";
	std::cin >> damage;
	std::cout << "Enter character armor value: ";
	std::cin >> armor;
	std::cout << "Is the character alive? (1 for yes, 0 for no): ";
	std::cin >> isAlive;

	//creating the new character
	Character newCharacter(name, health, damage, armor, isAlive);

	//Display Stats
	std::cout << "\n";
	newCharacter.displayStatus();
}