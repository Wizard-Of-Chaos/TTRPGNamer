#include <iostream>
#include <fstream>
#include <string>
#include "array_list.h"
#include <vector>
#include <stdlib.h>

using namespace std;

ArrayList getList(string name)
{
	ArrayList list;
	ifstream yoink(name);
	string madlib;
	while (getline(yoink, madlib, '\n')) {
		list.insert(madlib);
	}
	yoink.close();
	return list;
}

void printChoices()
{
	cout << "T - Tavern names. | C - Cult names." << endl;
	cout << "N - NPC names.    | R - Dave Ryder name." << endl;
	cout << "D - Dungeon names.| O - Orc." << endl;
	cout << "Q - Quit the program." << endl;
}

int main()
{
	ArrayList verbs = getList("verbs.txt");
	ArrayList animals = getList("animals.txt");
	ArrayList adjectives = getList("adjectives.txt");
	ArrayList daves = getList("daves.txt");
	ArrayList ryders = getList("ryders.txt");
	ArrayList groups = getList("groups.txt");
	ArrayList figures = getList("figures.txt");
	ArrayList dungeons = getList("dungeons.txt");
	ArrayList descriptors = getList("descriptors.txt");
	ArrayList firstnames = getList("firstnames.txt");
	ArrayList lastnames = getList("lastnames.txt");

	int counter = 0;
	char choice;
	cout << "Random number seed: ";
	string seed;
	getline(cin, seed);
	int sum = 0;
	for (char c: seed) {
        sum += c;
	}
	sum = (sum % 99999);
    srand(sum);
	bool running = true;
	while (running == true)  {
		printChoices();
		cin >> choice;
		cin.get();
		counter = 0;
		switch(choice)
		{
			case 'T':
			case 't':
				{
					while (counter < 10) {
						string tavern = "";
						tavern += verbs[(rand() % verbs.size())];
						tavern += "ing ";
						tavern += animals[(rand() % verbs.size())];
						cout << tavern << endl;
						++counter;
					}
					cout << endl;
					break;
				}
			case 'C':
			case 'c':
				{
					while (counter < 10) {
						string cult = "";
						cult += adjectives[(rand() % adjectives.size())];
						cult += " ";
						cult += groups[(rand() % groups.size())];
						cult += " of the ";
						cult += figures[(rand() % figures.size())];
						cout << cult << endl;
						++counter;
					}
					cout << endl;
					break;
				}
			case 'N':
			case 'n':
				{
					while (counter < 10) {
						string name = "";
						name += firstnames[(rand() % firstnames.size())];
						name += " ";
						name += lastnames[(rand() % lastnames.size())];
						int roll = (rand() % 18);
						if (roll >= 10) {
							name += " the ";
							name += adjectives[(rand() % adjectives.size())];
						}
						cout << name << endl;
						++counter;
					}
					cout << endl;
					break;
				}
			case 'R':
			case 'r':
				{
					while (counter < 10) {
						string daveryder = "";
						daveryder += daves[(rand() % daves.size())];
						daveryder += " ";
						daveryder += ryders[(rand() % ryders.size())];
						cout << daveryder << endl;
						++counter;
					}
					cout << endl;
					break;
				}
			case 'D':
			case 'd':
				{
					while (counter < 10) {
						string dungeon = "";
						dungeon += dungeons[(rand() % dungeons.size())];
						dungeon += " of ";
						dungeon += descriptors[(rand() % descriptors.size())];
						cout << dungeon << endl;
						++counter;
					}
					cout << endl;
					break;
				}
			case 'O':
			case 'o':
				{
					vector<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
					vector<char> letters = { 'a', 'b', 'c', 'd', 'e', 'h', 'i', 'k', 'l', 'm', 'n', 'o', 'r', 's', 't', 'u', 'v', 'w' }; // ORCS HAVE NO NEED FOR PUNY SOFT-SOUNDING CONSONANTS
					// seriously, though, I took out letters that would sound off in an orc name
					while (counter < 10) {
						string orc = "";
						orc += letters[(rand() % letters.size())];
						orc += vowels[(rand() % vowels.size())];
						int num = (rand() % 10);
						for (int i = 0; i < num; ++i) {
							orc += letters[(rand() % letters.size())];
						}
						orc += vowels[(rand() % vowels.size())];
						num = (rand() % 6);
						for (int i = 0; i < num; ++i) {
							orc += letters[(rand() % letters.size())];
						}
						cout << orc << endl;
						++counter;
					}
					cout << endl;
					break;
				}
			case 'Q':
			case 'q':
				{
					running = false;
					break;
				}
			default:
				{
					cout << "Not a valid choice. Try again." << endl;
					break;
				}
		} // end of switch

	}
}
