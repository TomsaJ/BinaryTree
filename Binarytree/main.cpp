// Binarytree.cpp : Diese Datei enth�lt die Funktion "main". Hier beginnt und endet die Ausf�hrung des Programms.
//

#include <iostream>
#include <ctime>
#include "binarytree.h"

char input;
int inputnumber;
int anzahl;
int number;
SearchTree<int> tree;


void pause()
{
	//aktuelle Lösung 
	string a;
	cout << "Taste 9 und enter zum fortfahren drücken" << endl;
	cin >> a ;
	
}

void insertRandomNumber(int afrn) //afr: anzahlforrandomnumber
{
	for (int i = 0; i < afrn; i++)
	{
		number = 1 + (rand() % 15) + 1;
		tree.insert(number);
	}
}

void insertownNumber(int afon) //afon: anzahlforownnumber
{
	for (int i = 0; i < afon; i++)
	{
		cout << "Zahl eingeben" << endl;
		cin >> number;
		tree.insert(number);
	}
}

void deletenode()
{
	cout << "Aktueller Baum:" << tree << endl;
	cout << "Zuloeschende Zahl:";
	cin >> inputnumber;
	if (tree.search(inputnumber) != nullptr)
	{
		cout << "Alter Tree:" << tree << endl;
		tree.deleteNode(tree.search(inputnumber));
		cout << "Neuer Tree:" << tree << endl;

	}
	else
	{
		cout << "Zahl ist in dem Tree nicht vorhanden und kann nicht gel�scht werden" << endl;
	}

	#ifdef _WIN32
		system("pause");
	#else
		pause();
	#endif
	
}



void start()
{
	cout << "Mit wie viele Zahlen soll der Baum erstellt werden" << endl;
	cin >> anzahl;
	cout << "1. Zufaellige Zahlen" << endl;
	cout << "2. Eigene Zahlen" << endl;
	cin >> input;
		switch (input)
		{
		case '1':
			insertRandomNumber(anzahl);
			break;
		case '2':
			insertownNumber(anzahl);
			break;
		}
}

int main(int argc, char** argv)
{
	
		// TreeNode<int> tree(5);

		// Einfuegen:
		/*
			Zufallgenerator funktioniert noch nicht ganz
		*/

		
		srand(time(0));
		/*for (int i = 0; i < 10; i++)
		{
			number = 1+(rand()% 15)+1;
			tree.insert(number);
		}*/

		start();
		

		// Ausdrucken:
		cout << "Tree:" << tree << endl; // erwartet: 2, 3, 4, 5, 7, 8, 9, 10,


		/*
		* Menue wird noch bearbeitet
		*/
		while (input != '9')
		{
			
		#ifdef _WIN32
			system("cls");
		#else
			system ("clear");
		#endif
			cout
				<< tree << endl
				<< "Binarysearchtree" << endl
				<< "1. Neue Zahl einfuegen" << endl
				<< "2. Zahl loeschen" << endl
				<< "3. Zahl suchen" << endl
				<< "9. Beenden" << endl;


			cin >> input;
			while (cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
				cin >> input;
			}


				switch (input)
				{
				case '1':
					cout << "Wie viele Zahlen sollen hinzugefuegt werden" << endl;
					cin >> anzahl;
					cout << "1 Zufaellige?" << endl;
					cout << "2 Eigene" << endl;
					cin >> input;
					try {
						switch (input)
						{
						case '1':
							insertRandomNumber(anzahl);
							break;
						case '2':
							insertownNumber(anzahl);
							break;
						}
					}
					catch (int& e)
					{

					}
					break;

				case '2':
					deletenode();
					break;
				case '3':
					cout << "Gesuchte Zahl:" << endl;
					cin >> number;
					if (tree.search(number) != nullptr)
					{
						cout << "Die Zahl "<<number << " ist vorhanden" << endl;
					}
					else
					{
						cout << "Die Zahl "<<number << " ist NICHT vorhanden" << endl;
					}
					#ifdef _WIN32
						system("pause");
					#else
						pause();
					#endif
					break;
				case '9':
					cout << "Programm wird beendet";
					break;
				default:
					cout << "Menuepunkt nicht vorhanden" << endl;
					#ifdef _WIN32
						system("pause");
					#else
						pause();
					#endif
				}
		}

	return 0;
}

// Programm ausf�hren: STRG+F5 oder Men�eintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Men� "Debuggen starten"

// Tipps f�r den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzuf�gen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzuf�gen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzuf�gen", um dem Projekt vorhandene Codedateien hinzuzuf�gen.
//   6. Um dieses Projekt sp�ter erneut zu �ffnen, wechseln Sie zu "Datei" > "�ffnen" > "Projekt", und w�hlen Sie die SLN-Datei aus.
