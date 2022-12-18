// Binarytree.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <ctime>
#include "binarytree.h"

char input;
int inputnumber;
int anzahl;
int number;
SearchTree<int> tree;


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
		cout << "Zahl ist in dem Tree nicht vorhanden und kann nicht gelöscht werden" << endl;
	}
	system("pause");
}

void start()
{
	cout << " Mit wie viele Zahlen soll der Baum erstellt werden" << endl;
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
			
			system("CLS");
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
					system("pause");
					break;
				case '9':
					cout << "Programm wird beendet";
					break;
				default:
					cout << "Menüpunkt nicht vorhanden" << endl;
					system("pause");
				}


				/*
				// Suchen:
				cout << "Searching 3, found: " << tree.search(3)->key << endl;
				cout << "Searching 21 (not in list), found: " << tree.search(21) << endl; // Falls element nicht in Liste: nullptr

				// Loeschen:
				/*std::cout << "removing 8\n";
				tree.deleteNode(tree.search(8));
				std::cout << tree << "\n";

				/*std::cout << "removing 10\n";
				tree.deleteNode(tree.search(10));
				std::cout << tree << "\n";

				// Sonderfall: Wurzel loeschen:
				std::cout << "removing 5 (root node)\n";
				tree.deleteNode(tree.search(5));
				std::cout << tree << endl;

				// Predecessor testen:
				std::cout << "removing element before 4 (3)\n";
				tree.deleteNode(tree.search(4)->predecessor());
				std::cout << tree << endl;

				// Successor testen:
				std::cout << "removing element after 4 (7)\n";
				tree.deleteNode(tree.search(4)->successor());
				std::cout << tree << endl;

				// <<--  Hier wird aufgrund des Scope-Endes automatisch der destruktor von tree aufgerufen

				std::cout << "deleted tree, no errors occurred\n"; // Falls dieser text NICHT erscheint, dann ist das Programm im Destruktor von tree abgestuerzt*/
				

		}

	return 0;
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
