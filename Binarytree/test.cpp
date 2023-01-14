#include <iostream>
#include <ctime>
#include <string>
#include "binarytree.h"

char input;
int inputnumber;
int anzahl;
int number;
int maxnumber;
string news = "";
SearchTree<int> tree;

void clear()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void pause()
{

	//aktuelle Lösung 
#ifdef _WIN32
	system("pause");
#else
	char a;
	while (a != '9')
	{
		cout << "Taste 9 und Enter Drücken . . ." << endl;
		cin >> a;
	}
#endif
}

void insertRandomNumber(int afrn) //afr: anzahlforrandomnumber
{
	for (int i = 0; i < afrn; i++)
	{
		number = 1 + rand() + 1;
		if (number > maxnumber)
		{
			maxnumber = number;
		}
		tree.insert(number);
	}
}

void testdeletetree()
{
	for (int i = 0; i <= maxnumber; i++) // besser ist eine Liste, in der die eingefügten Zahlen gespeichert sind!!!
	{
		while (tree.search(i))
		{
			tree.deleteNode(tree.search(i));
		}
	}
	maxnumber = 0;
}

void test()
{
	clear();
	clock_t start;
	clock_t end;
	double elapsed_time;
	int counter = 10000;

	while (counter != 1e7 + 1)
	{
		cout << "Das einfuegen von " << counter << " Zahlen hat ";
		start = clock();
		insertRandomNumber(counter);
		end = clock();
		elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
		cout << elapsed_time << " ms gedauert." << endl;

		cout << "Das Suchen von der Zahl " << (0.75 * counter) << " hat ";
		start = clock();
		tree.search(0.75 * counter);
		end = clock();
		elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
		cout << elapsed_time << " ms gedauert." << endl;

		cout << "Benoetigte Zeit um den Baum zu loeschen: ";
		start = clock();
		testdeletetree();
		end = clock();
		elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
		cout << elapsed_time << " ms" << endl;
		if (counter <= 10000)
		{
			counter = 100000;
		}
		else
		{
			counter += 100000;
		}
		cout << endl;
	}
	pause();
}