// Final Group Project version 4
// Stewart Connick & Chris Sutterlin
// 5-28-16
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <memory>
#include <exception>
#include <string>
#include <windows.h>
#include <sys/stat.h>
#include <iomanip>

using namespace std;

void displayMenu();
void displayClass();
int charStats(int attackus, int defenseus, int magicus, int speedus, int level, int exp, int money);
void displayArmory();
void saveGame(string username, string nameus, int attackus, int defenseus, int magicus, int speedus, int level, int exp, int money);
void continueGame();
void newGame();
void startContinueError();
int randomEvent(int random, int a, int asuccess, int msuccess, int b, int opac);



int main()
{
	int option;
	fstream SaveGame;
	int person, opponent, atk, asuccess, msuccess, game = 1, counter1 = 1, level, atr, a, b, c = 0, d, decision, item;
	//opponent
	int attackop, defenseop, speedop, healthop = 100, opac, expo = 0, moneyo = 0;
	//user
	int magicus, attackus, defenseus, speedus, healthus = 100, exp = 0, money = 0, levelup = 200;
	//names
	string nameus, nameop, username;
	char quit;
	//classes
	int healus = 0;

	cout << endl;
	int main(void);
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		WORD wOldColorAttrs;
		CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

		/*
		* First save the current color information
		*/
		GetConsoleScreenBufferInfo(h, &csbiInfo);
		wOldColorAttrs = csbiInfo.wAttributes;

		/*
		* Set the new color information
		*/
		SetConsoleTextAttribute(h, 11);

		cout << setw(57) << ("/// Welcome to Defense Tactics! \\\\\\");
		cout << endl;

		/*
		* Restore the original colors
		*/
		SetConsoleTextAttribute(h, wOldColorAttrs);

	}

	cout << "*******************************************************************************" << endl;
	cout << endl;

	SaveGame.open("GameSave.txt");

	if (SaveGame.good())
	{

		continueGame();

		cin >> option;
		cout << endl;

	}

	else
	{
		newGame();
		cin >> option;
		cout << endl;
	}

	if (option > 3)
	{
		do
		{
			startContinueError();

			cin >> option;

		} while (option > 3);

	}
	switch (option)
	{
	case 1:
	{
		ifstream SaveGame("GameSave.txt");

		getline(SaveGame, username);
		getline(SaveGame, nameus);
		SaveGame >> attackus;
		SaveGame >> defenseus;
		SaveGame >> magicus;
		SaveGame >> speedus;
		SaveGame >> level;
		SaveGame >> exp;
		SaveGame >> money;
		SaveGame.close();

	break;
	}

	case 2:
	{

		cout << "What is your desired username?" << endl << endl;
		cout << "> ";
		cin.ignore();
		getline(cin, username);
		cout << endl;
		system("cls");
		cout << "Hello, " << username << ", the battle awaits you." << endl;
		
		system("pause");
		system("cls");

		do {

			displayClass();

			cin >> person;
			if (person > 4)
			{
				system("cls");
				cout << "You must enter an integer between 1 and 4\n\n";
				system("pause");
				system("cls");
			}
			switch (person)
			{
			case 1:
				attackus = 30, defenseus = 40, magicus = 60, speedus = 60, level = 1, nameus = "Wizard";
				break;
			case 2:
				attackus = 50, defenseus = 75, magicus = 40, speedus = 40, level = 1, nameus = "Chief";
				break;
			case 3:
				attackus = 60, defenseus = 50, magicus = 30, speedus = 50, level = 1, nameus = "Banshee";
				break;
			case 4: attackus = 40, defenseus = 90, magicus = 20, speedus = 20, level = 1, nameus = "Tank";
				break;


			default:
				cout << "No One";


			}


		} while (person > 4);
		break;
	}

	case 3:
	{

		cout << "Game now exiting." << endl;
		exit(0);

		break;
	}
	default:
		cout << "Please choose an option. (1) (2) (3). ";
	}

	system("cls");

	do {
		do {
		SecondMenu:
			system("cls");

			cout << "These are your current stats, " << username << "." << endl;
			cout << "|" << nameus << "|" << endl;

			charStats(attackus, defenseus, magicus, speedus, level, exp, money);

			displayMenu();
			
			cin >> decision;
			switch (decision)
			{
			case 1:
				int random3, random4, random5;
				srand((unsigned)time(0));
				random3 = (rand() % 4) + 1;
				random4 = (rand() % 4) + 1;
				random5 = (rand() % 4) + 1;
				if (healthop == 0)
					healthop = 100;
				system("cls");
				do {
					cout << "Welcome to the arena, " << username << ", which opponent would you like to face?" << endl << endl;
					d = (level * -1);
					switch (random3)
					{
					case 1:
						if (level == 1)
						{
							cout << "(" << d + 2 << ")\n***************\nThe Tree(lvl 1):\n attack - 0\n defense - 20\n speed - 0\n 40 exp\n***************\n";
							cout << endl;
						}
						break;
					case 2:
						if (level == 1)
						{
							cout << "(" << d + 2 << ")\n***************\nThe Rock(lvl 1):\n attack - 0\n defense - 30\n speed - 0\n 60 exp\n***************\n";
							cout << endl;
						}
						break;
					case 3:
						if (level == 1)
						{
							cout << "(" << d + 2 << ")\n***************\nThe Computer(lvl 1):\n attack - 0\n defense - 10\n speed - 0\n 20 exp\n***************\n";
							cout << endl;
						}
						break;
					case 4:
						if (level == 1)
						{
							cout << "(" << d + 2 << ")\n***************\nThe Book(lvl 1):\n attack - 0\n defense - 5\n speed - 0\n 10 exp\n***************\n";
							cout << endl;
						}
						break;
					default:
						cout << "Can't Happen";
					}
					switch (random4)
					{
					case 1:
						if (level <= 2 && level >= 1)
						{
							cout << "(" << d + 3 << ")\n***************\nThe Rat(lvl 2):\n attack - 30\n defense - 20\n speed - 30\n 160 exp\n***************\n";
							cout << endl;
						}
						break;
					case 2:
						if (level <= 2 && level >= 1)
						{
							cout << "(" << d + 3 << ")\n***************\nThe Cat(lvl 2):\n attack - 40\n defense - 20\n speed - 30\n 180 exp\n***************\n";
							cout << endl;
						}
						break;
					case 3:
						if (level <= 2 && level >= 1)
						{
							cout << "(" << d + 3 << ")\n***************\nThe Dog(lvl 2):\n attack - 45\n defense - 25\n speed - 30\n 200 exp\n***************\n";
							cout << endl;
						}
						break;
					case 4:
						if (level <= 2 && level >= 1)
						{
							cout << "(" << d + 3 << ")\n***************\nThe Bat(lvl 2):\n attack - 30\n defense - 20\n speed - 35\n 180 exp\n***************\n";
							cout << endl;
						}
						break;
					default:
						cout << "Can't Happen";
					}
					switch (random5)
					{
					case 1:
						if (level <= 3 && level >= 1)
						{
							cout << "(" << d + 4 << ")\n***************\nThe Mage(lvl 3):\n attack - 65\n defense - 35\n speed - 45\n 290 exp\n***************\n";
							cout << endl;
						}
						break;
					case 2:
						if (level <= 3 && level >= 1)
						{
							cout << "(" << d + 4 << ")\n***************\nThe Jackal(lvl 3):\n attack - 60\n defense - 50\n speed - 50\n 320 exp\n***************\n";
							cout << endl;
						}
						break;
					case 3:
						if (level <= 3 && level >= 1)
						{
							cout << "(" << d + 4 << ")\n***************\nThe Crusader(lvl 3):\n attack - 65\n defense - 55\n speed - 45\n 330 exp\n***************\n";
							cout << endl;
						}
						break;
					case 4:
						if (level <= 3 && level >= 1)
						{
							cout << "(" << d + 4 << ")\n***************\nThe Wolf(lvl 3):\n attack - 55\n defense - 45\n speed - 55\n 310 exp\n***************\n";
							cout << endl;
						}
						break;
					default:
						cout << "Can't Happen";
					}
					switch (random3)
					{
					case 1:
						if ((level <= 4) && (level >= 2))
						{
							cout << "(" << d + 5 << ")\n***************\nThe Assassin(lvl 4):\n attack - 75\n defense - 35\n speed - 55\n 330 exp\n***************\n";
							cout << endl;
						}
						break;
					case 2:
						if ((level <= 4) && (level >= 2))
						{
							cout << "(" << d + 5 << ")\n***************\nThe Pacman(lvl 4):\n attack - 65\n defense - 30\n speed - 60\n 310 exp\n***************\n";
							cout << endl;
						}
						break;
					case 3:
						if ((level <= 4) && (level >= 2))
						{
							cout << "(" << d + 5 << ")\n***************\nThe Man Eating Bunny(lvl 4):\n attack - 75\n defense - 35\n speed - 55\n 330 exp\n***************\n";
							cout << endl;
						}
						break;
					case 4:
						if ((level <= 4) && (level >= 2))
						{
							cout << "(" << d + 5 << ")\n***************\nThe Warlock(lvl 4):\n attack - 70\n defense - 40\n speed - 50\n 320 exp\n***************\n";
							cout << endl;
						}
						break;
					default:
						cout << "Can't Happen";
					}
					switch (random4)
					{
					case 1:
						if ((level <= 5) && (level >= 3))
						{
							cout << "(" << d + 6 << ")\n***************\nPoseidon(lvl 5):\n attack - 80\n defense - 45\n speed - 45\n 340 exp\n***************\n";
							cout << endl;
						}
						break;
					case 2:
						if ((level <= 5) && (level >= 3))
						{
							cout << "(" << d + 6 << ")\n***************\nMinitaur(lvl 5):\n attack - 65\n defense - 55\n speed - 50\n 350 exp\n***************\n";
							cout << endl;
						}
						break;
					case 3:
						if ((level <= 5) && (level >= 3))
						{
							cout << "(" << d + 6 << ")\n***************\nThe Cyclops(lvl 5):\n attack - 75\n defense - 45\n speed - 50\n 340 exp\n***************\n";
							cout << endl;
						}
						break;
					case 4:
						if ((level <= 5) && (level >= 3))
						{
							cout << "(" << d + 6 << ")\n***************\nThe Dragon(lvl 5):\n attack - 80\n defense - 55\n speed - 30\n 340 exp\n***************\n";
							cout << endl;
						}
						break;
					default:
						cout << "Can't Happen";
					}
					switch (random4)
					{
					case 1:
						if ((level <= 6) && (level >= 4))
						{
							cout << "(" << d + 7 << ")\n***************\nAthena(lvl 6):\n attack - 85\n defense - 55\n speed - 60\n 400 exp\n***************\n";
							cout << endl;
						}
						break;
					case 2:
						if ((level <= 6) && (level >= 4))
						{
							cout << "(" << d + 7 << ")\n***************\nZeus(lvl 6):\n attack - 90\n defense - 65\n speed - 55\n 420 exp\n***************\n";
							cout << endl;
						}
						break;
					case 3:
						if ((level <= 6) && (level >= 4))
						{
							cout << "(" << d + 7 << ")\n***************\nHades(lvl 6):\n attack - 75\n defense - 70\n speed - 50\n 390 exp\n***************\n";
							cout << endl;
						}
						break;
					case 4:
						if ((level <= 6) && (level >= 4))
						{
							cout << "(" << d + 7 << ")\n***************\nOsiris(lvl 6):\n attack - 70\n defense - 60\n speed - 55\n 370 exp\n***************\n";
							cout << endl;
						}
						break;
					default:
						cout << "Can't Happen";
					}
					if ((level <= 99) && (level >= 5))
					{
						cout << "(" << d + 8 << ")\n***************\nGod(lvl ?):\n attack - ??\n defense - ??\n speed - ??\n Infinite exp\n***************\n";
						cout << endl;
					}
					cout << "> ";
					cin >> opponent;
					if ((opponent > 3) || (opponent < 1))
					{
						system("cls");
						cout << "You must enter an integer between 1 and 3.\n\n";
						system("pause");
						system("cls");
					}
				} while ((opponent > 3) || (opponent < 1));
				system("cls");
				opponent = opponent + c;
				switch (opponent)
				{
				case 1:
					switch (random3)
					{
					case 1:
						attackop = 0, defenseop = 20, speedop = 0, nameop = "Tree", expo = 40, moneyo = 20;
						break;
					case 2:
						attackop = 0, defenseop = 30, speedop = 0, nameop = "Rock", expo = 60, moneyo = 30;
						break;
					case 3:
						attackop = 0, defenseop = 10, speedop = 0, nameop = "Computer", expo = 20, moneyo = 10;
						break;
					case 4:
						attackop = 0, defenseop = 5, speedop = 0, nameop = "Book", expo = 10, moneyo = 5;
						break;
					}
					break;
				case 2:
					switch (random4)
					{
					case 1:
						attackop = 30, defenseop = 20, speedop = 30, nameop = "Rat", expo = 160, moneyo = 80;
						break;
					case 2:
						attackop = 40, defenseop = 20, speedop = 30, nameop = "Cat", expo = 180, moneyo = 90;
						break;
					case 3:
						attackop = 45, defenseop = 25, speedop = 30, nameop = "Dog", expo = 200, moneyo = 100;
						break;
					case 4:
						attackop = 35, defenseop = 20, speedop = 35, nameop = "Bat", expo = 180, moneyo = 90;
						break;
					}
					break;
				case 3:
					switch (random5)
					{
					case 1:
						attackop = 65, defenseop = 35, speedop = 45, nameop = "Mage", expo = 290, moneyo = 145;
						break;
					case 2:
						attackop = 60, defenseop = 50, speedop = 50, nameop = "Jackal", expo = 320, moneyo = 160;
						break;
					case 3:
						attackop = 65, defenseop = 55, speedop = 45, nameop = "Crusader", expo = 330, moneyo = 165;
						break;
					case 4:
						attackop = 55, defenseop = 45, speedop = 55, nameop = "Wolf", expo = 310, moneyo = 155;
						break;
					}
					break;
				case 4:
					switch (random3)
					{
					case 1:
						attackop = 85, defenseop = 35, speedop = 65, nameop = "Assassin", expo = 330, moneyo = 165;
						break;
					case 2:
						attackop = 75, defenseop = 30, speedop = 70, nameop = "Pacman", expo = 310, moneyo = 155;
						break;
					case 3:
						attackop = 85, defenseop = 35, speedop = 85, nameop = "Man Eating Bunny", expo = 330, moneyo = 165;
						break;
					case 4:
						attackop = 80, defenseop = 40, speedop = 60, nameop = "Warlock", expo = 320, moneyo = 160;
						break;
					}
					break;
				case 5:
					switch (random4)
					{
					case 1:
						attackop = 90, defenseop = 45, speedop = 55, nameop = "Poseidon", expo = 340, moneyo = 170;
						break;
					case 2:
						attackop = 80, defenseop = 55, speedop = 60, nameop = "Minitaur", expo = 350, moneyo = 175;
						break;
					case 3:
						attackop = 85, defenseop = 45, speedop = 70, nameop = "Cyclops", expo = 340, moneyo = 170;
						break;
					case 4:
						attackop = 90, defenseop = 55, speedop = 45, nameop = "Dragon", expo = 340, moneyo = 170;
						break;
					}
					break;
				case 6:
					switch (random5)
					{
					case 1:
						attackop = 105, defenseop = 55, speedop = 70, nameop = "Athena", expo = 400, moneyo = 200;
						break;
					case 2:
						attackop = 110, defenseop = 65, speedop = 65, nameop = "Zeus", expo = 420, moneyo = 210;
						break;
					case 3:
						attackop = 95, defenseop = 70, speedop = 60, nameop = "Hades", expo = 390, moneyo = 195;
						break;
					case 4:
						attackop = 90, defenseop = 60, speedop = 65, nameop = "Osiris", expo = 370, moneyo = 185;
						break;
					}
					break;
				case 7:
					attackop = 110, defenseop = 90, speedop = 80, nameop = "God";
					break;
				default:
					cout << "No One";
				}
				//success rate
				asuccess = speedus - defenseop + 50;
				msuccess = speedus - defenseop + 50;
				cout << "First Round is: " << nameus << " vs. " << nameop << "!";

				//amount of damage dealt
				a = attackus - defenseop;
				b = magicus - defenseop;
				opac = 100 - defenseus;
				attackop = attackop - defenseus;
				if (attackop < 0)
					attackop = 0;
				else
					attackop = attackop;
				do {
					//Random Number Generator
					int random, random2;
					random = rand() % 100;
					random2 = rand() % 100;
					system("CLS");
					//limitation
					if (asuccess > 100)
						asuccess = 100;
					else
						asuccess = asuccess;
					if (msuccess > 100)
						msuccess = 100;
					else
						msuccess = msuccess;
					//options
					do {
						 randomEvent(random, a, asuccess, msuccess, b, opac);

						healus = attackop - 5;
						if (healus <= 0)
							healus = 10;
						cout << "What would you like to do?\n\n"
							<< "(1)\n***************\nattack: " << asuccess << "% chance of success\n***************\n\n"
							<< "(2)\n***************\nmagic: " << msuccess << "% chance of success\n***************\n\n"
							<< "(3)\n***************\nheal + " << healus << "hp\n***************\n\n"
							<< "(4)\n***************\nRetreat " << "\n***************\n\n";
						cout << "> ";
						cin >> atk;
						if (atk > 4)
						{
							system("cls");
							cout << "You MUST enter a number between 1 and 3.\n\n";
							system("pause");
							system("cls");
						}
					} while (atk > 4);
					system("CLS");
					cout << "Calculating results";
					for (int counter = 0; counter <= 6; counter++)
					{
						Sleep(00);
						cout << ".";
					}
					system("CLS");
					switch (atk)
					{
					case 1:
						if (random <= asuccess)
						{
							if (random <= 10)
							{
								cout << "CRITICAL!\n\n\a";
								a = a * 2;
							}
							if (a < 0)
								a = 5;
							cout << "You took away " << a << " health points from the " << nameop << "!\n\n";
							healthop = healthop - a;
							if (healthop < 0)
								healthop = 0;
							cout << "The " << nameop << "'s health is: " << healthop << endl << "Your health is: " << healthus << endl << endl;
							if (random <= 10)
								a = a / 2;
						}
						else
						{
							cout << "You missed!\n\n";
							cout << "The " << nameop << "'s health is: " << healthop << endl << "Your health is: " << healthus << endl << endl;
						}
						break;
					case 2:
						if (random <= msuccess)
						{
							if (random <= 10)
							{
								cout << "CRITICAL!\n\n\a";
								b = b * 2;
							}
							if (b < 0)
								b = 5;
							cout << "You took away " << b << " health points from the " << nameop << "!\n\n";
							healthop = healthop - b;
							if (healthop < 0)
								healthop = 0;
							cout << "The " << nameop << "'s health is: " << healthop << endl << "Your health is: " << healthus << endl << endl;
							if (random <= 10)
								b = b / 2;
						}
						else
						{
							cout << "You missed!\n\n";
							cout << "The " << nameop << "'s health is: " << healthop << endl << "Your health is: " << healthus << endl << endl;
						}
						break;
					case 3:
						if (healthus < 100)
						{
							healthus = healthus + healus;
							cout << "Your health rose from " << healthus - healus << ", to " << healthus << "!" << endl << endl;
						}
						else
							cout << "Your health is already 100%!" << endl << endl;
						break;
					case 4:
						cout << "You have left the arena." << endl;
						goto SecondMenu;
						break;
					default:
						cout << "Attack Not available";
					}
					system("pause");
					system("cls");
					if (healthop > 0)
					{
						cout << "Opponent is now attacking";
						for (int counter = 6; counter >= 0; counter--)
						{
							Sleep(00);
							cout << ".";
						}
						system("cls");
						if (opac <= random2)
						{
							if (random2 <= 5)
							{
								cout << "CRITICAL!\n\n\a";
								attackop = attackop + 15;
							}
							if (attackop <= 0)
								attackop = 5;
							if (opponent == 1)
								attackop = 0;
							cout << "The opponent took away " << attackop << " health points from you!\n\n";
							healthus = healthus - attackop;
							if (healthus < 0)
								healthus = 0;
							cout << "Opponent's health is: " << healthop << endl << "Your health is: " << healthus << endl << endl;
							if (random2 <= 5)
								attackop = attackop - 15;
						}
						else
						{
							cout << "The opponent missed!\n\n";
							cout << "Opponent's health is: " << healthop << endl << "Your health is: " << healthus << endl << endl;
						}
						system("pause");
					}
				} while ((healthop >= 1) && (healthus >= 1));
				system("cls");
				if (healthop >= 1)
				{
					system("cls");
					cout << "You were beat by the " << nameop << "!\n\n";
					healthus = 100;
					healthop = 100;
					cout << "You lost 100 experience points." << endl;
					exp = exp - 100;


				}
				else if (opponent != 7)
				{
					if (healthus > 0)
					{
						healthus = 100;
						cout << "You have gained " << expo << " experience, and " << moneyo << " money!\n\n";
						exp = exp + expo;
						money = money + moneyo;
						cout << "You have " << exp << " experience points!\n";
						if (levelup > exp)
							cout << "You need " << levelup - exp << " more exp points to level up.\n";
						cout << "You have $" << money << endl << endl;
						system("pause");
						system("cls");
					}
					if (exp >= levelup)
					{
						c++;
						level++;
						cout << "Congratulations on your victory! You have graduated to level " << level << "!\n\n";
						cout << "Which attribute would you like to increase by 5 points?\n";
						cout << endl << "(1)\n*****\nattack\n*****\n\n(2)\n*****\nmagic\n*****\n\n(3)\n*****\nspeed\n*****\n\n(4)\n*****\ndefense\n*****\n";
						cout << "> ";
						cin >> atr;
						switch (atr)
						{
						case 1:
							attackus = attackus + 5;
							break;
						case 2:
							magicus = magicus + 5;
							break;
						case 3:
							speedus = speedus + 5;
							break;
						case 4:
							defenseus = defenseus + 5;
							break;
						default:
							defenseus = defenseus;
							break;
						}
						cout << "Congratulations! You have increased by 5 points!" << endl;
						system("cls");
						cout << "Your current Stats are:\nattack - " << attackus << endl << "magic - " << magicus << endl << "speed - " << speedus << endl << "defense - " << defenseus << endl << endl;
						system("cls");
						levelup = levelup * 2;
					}
				}
				system("pause");
				break;
			case 2:
				do {
					do {
					ThirdMenu:
						system("cls");
						cout << "You have $" << money << " left.";
						displayArmory();


						cin >> item;
						system("cls");
					} while ((item > 13) || (item < 1));
					switch (item)
					{
					case 1:
						if (money >= 50)
						{
							cout << "You have gained 3 attack!\n\n";
							money = money - 50;
							attackus = attackus + 3;
							break;
						}
						else
						{
							system("cls");
							cout << "You do not have enough money!" << endl;
							system("pause");
							goto SecondMenu;
						}

					case 2:
						if (money >= 500)
						{
							cout << "You have gained 6 attack!\n\n";
							money = money - 500;
							attackus = attackus + 6;
							break;
						}
						else
						{
							system("cls");
							cout << "You do not have enough money!" << endl;
							system("pause");
							goto SecondMenu;
						}

					case 3:
						if (money >= 700)
						{
							cout << "You have gained 9 attack!\n\n";
							money = money - 700;
							attackus = attackus + 9;
							break;
						}
						else
						{

							system("cls");
							cout << "You do not have enough money!" << endl;
							system("pause");
							goto SecondMenu;
						}

					case 4:
						if (money >= 300)
						{
							cout << "You have gained 3 defense!\n\n";
							money = money - 300;
							defenseus = defenseus + 3;
							break;
						}
						else
						{
							system("cls");
							cout << "You do not have enough money!" << endl;
							system("pause");
							goto SecondMenu;
						}

					case 5:
						if (money >= 500)
						{
							cout << "You have gained 6 defense!\n\n";
							money = money - 500;
							defenseus = defenseus + 6;
							break;
						}
						else
						{
							system("cls");
							cout << "You do not have enough money!" << endl;
							system("pause");
							goto SecondMenu;
						}

					case 6:
						if (money >= 700)
						{
							cout << "You have gained 9 defense!\n\n";
							money = money - 700;
							defenseus = defenseus + 9;
							break;
						}
						else
						{
							system("cls");
							cout << "You do not have enough money!" << endl;
							system("pause");
							goto SecondMenu;
						}

					case 7:
						if (money >= 300)
						{
							cout << "You have gained 3 magic!\n\n";
							money = money - 300;
							magicus = magicus + 3;
							break;
						}
						else
						{
							system("cls");
							cout << "You do not have enough money!" << endl;
							system("pause");
							goto SecondMenu;
						}

					case 8:
						if (money >= 500)
						{
							cout << "You have gained 6 magic!\n\n";
							money = money - 500;
							magicus = magicus + 6;
							break;
						}
						else
						{
							system("cls");
							cout << "You do not have enough money!" << endl;
							system("pause");
							goto SecondMenu;
						}

					case 9:
						if (money >= 700)
						{
							cout << "You have gained 9 magic!\n\n";
							money = money - 700;
							magicus = magicus + 9;
							break;
						}
						else
						{
							system("cls");
							cout << "You do not have enough money!" << endl;
							system("pause");
							goto SecondMenu;
						}

					case 10:
						if (money >= 300)
						{
							cout << "You have gained 3 speed!\n\n";
							money = money - 300;
							speedus = speedus + 3;
							break;
						}
						else
						{
							system("cls");
							cout << "You do not have enough money!" << endl;
							system("pause");
							goto SecondMenu;
						}

					case 11:
						if (money >= 500)
						{
							cout << "You have gained 6 speed!\n\n";
							money = money - 500;
							speedus = speedus + 6;
							break;
						}
						else
						{
							system("cls");
							cout << "You do not have enough money!" << endl;
							system("pause");
							goto SecondMenu;
						}

					case 12:
						if (money >= 700)
						{
							cout << "You have gained 9 speed!\n\n";
							money = money - 700;
							speedus = speedus + 9;
							break;
						}
						else
						{
							system("cls");
							cout << "You do not have enough money!" << endl;
							system("pause");
							goto SecondMenu;
						}

					case 13:
					{
						system("cls");
						cout << "You have left the armory." << endl;
						system("pause");
						goto SecondMenu;
						break;
					}
					default:
						cout << "Error.";
					}
					//END Armory
					cout << "Would you like to exit? (y or n)" << endl << endl;
					cout << "> ";
					cin >> quit;
					if (quit == 'y') // just updated
					{
						goto SecondMenu;
					}
					else if (quit == 'n')
					{
						goto ThirdMenu;
					}
				} while (quit != 'y');

				break;
			case 3:
			{

				saveGame(username, nameus, attackus, defenseus, magicus, speedus, level, exp, money);


				goto SecondMenu;
			}
			case 4:
			{
				system("cls");
				cout << "Goodbye!" << endl;
				exit(0);
			}


			default:
				cout << "Please select 1, 2, 3, or 4";
			}
		} while ((healthus > 0) && (opponent != 7));
	} while ((healthus >= 1) && (opponent != 7));
	if (healthus >= 1)
	{
		cout << "Congratulations, you won!";

	}
	else if (healthus <= 0)
	{
		cout << "Sorry, you lost." << endl;
	}
}

void displayMenu()
{
	cout << setw(34) << "(1)" << endl << setw(47) << "****************" << endl << setw(46) << "Go to the Arena" << setw(81) << "****************" << endl;
	cout << setw(34) << "(2)" << endl << setw(47) << "****************" << endl << setw(47) << "Go to the Armory" << setw(80) << "****************" << endl;
	cout << setw(34) << "(3)" << endl << setw(47) << "****************" << endl << setw(44) << "Save the Game" << setw(83) << "****************" << endl;
	cout << setw(34) << "(4)" << endl << setw(47) << "****************" << endl << setw(44) << "Quit the Game" << setw(83) << "****************" << endl << endl;
	cout << "> ";
}

void displayClass()
{
	cout << "(1)\n***************\nThe Wizard:\n attack - 30\n defense - 40\n magic - 60\n speed - 60\n***************" << endl << endl;
	cout << "(2)\n***************\nThe Chief:\n attack - 50\n defense - 75\n magic - 40\n speed - 30\n***************" << endl << endl;
	cout << "(3)\n***************\nThe Banshee:\n attack - 60\n defense - 50\n magic - 30\n speed - 50\n***************" << endl;
	cout << "(4)\n***************\nThe Tank:\n attack - 40\n defense - 90\n magic - 20\n speed - 20\n***************" << endl;

	cout << "Which Class would you like to be?" << endl << endl;
	cout << "> ";
}

int charStats(int attackus, int defenseus, int magicus, int speedus, int level, int exp, int money)
{
	cout << "|" << "Attack = " << attackus << "|" << endl;
	cout << "|" << "Defense = " << defenseus << "|" << endl;
	cout << "|" << "Magic = " << magicus << "|" << endl;
	cout << "|" << "Speed = " << speedus << "|" << endl;
	cout << "|" << "Level = " << level << "|" << endl;
	cout << "|" << "Experience = " << exp << "|" << endl;
	cout << "|" << "Money = $" << money << "|" << endl;

	

	return attackus, defenseus, magicus, speedus, level, exp, money;
}

void displayArmory()
{
	cout << endl;
	cout << "Which Item would you like to buy?\n\n";
	cout << "(1)\n**********\nRusty Sword(+3 attack) - 50$\n**********\n";
	cout << "(2)\n**********\nSteel Sword(+6 attack) - 500$\n**********\n";
	cout << "(3)\n**********\nGreat Sword(+9 attack) - 700$\n**********\n\n";
	cout << "(4)\n**********\nWooden Shield(+3 defense) - 300$\n**********\n";
	cout << "(5)\n**********\nSmall Shield(+6 defense) - 500$\n**********\n";
	cout << "(6)\n**********\nGaurdian's Shield(+9 defense) - 700$\n**********\n\n";
	cout << "(7)\n**********\nWooden Staff(+3 magic) - 300$\n**********\n";
	cout << "(8)\n**********\nCurved Staff(+6 magic) - 500$\n**********\n";
	cout << "(9)\n**********\nWarlock's Staff(+9 magic) - 700$\n**********\n\n";
	cout << "(10)\n**********\nPatched Loafers(+3 speed) - 300$\n**********\n";
	cout << "(11)\n**********\nRegular Sneakers(+6 speed) - 500$\n**********\n";
	cout << "(12)\n**********\nRunning Shoes(+9 speed) - 700$\n**********\n";
	cout << "(13)\n**********\nExit\n**********\n" << endl;
	cout << "> ";
}

void saveGame(string username, string nameus, int attackus, int defenseus, int magicus, int speedus, int level, int exp, int money)
{

	ofstream SaveGame("GameSave.txt");

	SaveGame << username << endl;
	SaveGame << nameus << endl;
	SaveGame << attackus << endl;
	SaveGame << defenseus << endl;
	SaveGame << magicus << endl;
	SaveGame << speedus << endl;
	SaveGame << level << endl;
	SaveGame << exp << endl;
	SaveGame << money << endl;
	SaveGame.close();

	system("cls");
	cout << "Your game has been saved. " << endl;
	system("pause");

}

void continueGame()
{
	cout << setw(43) << "(1) Continue" << endl;
	cout << setw(39) << "(3) Quit" << endl << endl;

	cout << "> ";
}

void newGame()
{
	cout << setw(47) << "(2) Start New Game" << endl;
	cout << setw(37) << "(3) Quit" << endl;
	cout << endl;

	cout << "> ";
}

void startContinueError()
{
	system("cls");
	cout << "You must enter an integer between 1 and 3.\n\n";
	cout << setw(42) << "(1) Continue" << endl;
	cout << setw(49) << "(2) Start New Game" << endl;
	cout << setw(39) << "(3) Quit." << endl;
	cout << endl;
	cout << "> ";
}

int randomEvent(int random, int a, int asuccess, int msuccess, int b, int opac)
{
	if ((random < 80) && (random > 75))
	{
		system("cls");
		cout << "Incredible..a mythical sword has fallen from the sky and into your fist.\nYour attack has rose an additional 5 points!\n(only used on THIS round.)\n\n";
		a = a + 5;
		system("pause");
		system("cls");
	}
	if ((random < 76) && (random > 70))
	{
		system("cls");
		cout << "You have just returned from the shoe store, with sneakers faster than lightning!\nYour Speed rose an additional 5 points!\n(only used on THIS round.)\n\n";
		asuccess = asuccess + 5;
		msuccess = msuccess + 5;
		system("pause");
		system("cls");
	}
	if ((random < 71) && (random > 65))
	{
		system("cls");
		cout << "An ancient wizard visited you in your sleep, and gave you a new spell.\nYour magic has rose an additional 5 points!\n(only used on THIS round.)\n\n";
		b = b + 5;
		system("pause");
		system("cls");
	}
	if ((random < 66) && (random > 60))
	{
		system("cls");
		cout << "Athena has just granted you a new sheild!\nYour defense has rose an additional 5 points!\n(only used on THIS round.)\n\n";
		opac = opac - 5;
		system("pause");
		system("cls");
	}
	return random, asuccess, msuccess, opac;
}
