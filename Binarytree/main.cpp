// Binarytree.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <ctime>
#include "binarytree.h"

char input;
int inputnumber;
int anzahl;

void randomnumber()
{
	
}

int main(int argc, char** argv)
{
	try
	{
		// TreeNode<int> tree(5);
		SearchTree<int> tree;

		// Einfuegen:
		randomnumber;
		/*
			Zufallgenerator funktioniert noch nicht ganz
		*/

		
		int number;
		
		srand(time(0));
		/*for (int i = 0; i < 10; i++)
		{
			number = 1+(rand()% 15)+1;
			tree.insert(number);
		}*/


		tree.insert(5);
		tree.insert(3);
		tree.insert(7);
		tree.insert(4);
		tree.insert(4);
		tree.insert(5);
		tree.insert(12);
		tree.insert(400);




		// Ausdrucken:
		cout << "Tree:" << tree << endl; // erwartet: 2, 3, 4, 5, 7, 8, 9, 10,


		/*
		* Menue wird noch bearbeitet
		*/
		do
		{
			
			system("CLS");
			cout
				<< tree << endl
				<< "Binarysearchtree" << endl
				<< "1. Neue Zahl einfügen" << endl
				<< "2. Zahl löschen" << endl
				<< "3. Zahl suchen" << endl
				<< "9. Beenden" << endl;
			cout << "Searching 21 (not in list), found: " << tree.search(21) << endl; // Falls element nicht in Liste: nullptr


			cin >> input;
			while (cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
				cin >> input;
			}

			try
			{

				switch (input)
				{
				case '1':
					cout << " Wie viele Zahlen sollen hinzugefügt werden" << endl;
					cin >> anzahl;
					cout << "1 Zufaellige?" << endl;
					cout << "2 Eigene" << endl;
					cin >> input;
					try {
						switch (input)
						{
						case '1':
							for (int i = 0; i < anzahl; i++)
							{
								number = 1 + (rand() % 15) + 1;
								tree.insert(number);
							}
							break;
						case '2':
							for (int i = 0; i < anzahl; i++)
							{
								cout << "Zahl eingeben" << endl;
								cin >> number;
								tree.insert(number);
							}
							break;
						}
					}
					catch (int& e)
					{

					}
					break;

				case '2':
					cout << "Zuloeschende Zahl:" << endl;
					cin >> inputnumber;
					tree.deleteNode(tree.search(inputnumber));
					break;
				case '3':
					cout << "Gesuchte Zahl:" << endl;
					cin >> number;
					if (tree.search(number) != nullptr)
					{
						cout << "Die Zahl"<<number << "ist vorhanden" << endl;
					}
					else
					{
						cout << "Die Zahl"<<number << "ist NICHT vorhanden" << endl;
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
			catch (int& e)
			{
				string error;
				switch (e) {

				case 4:
					error = "nicht vorhanden";
				}
			}
		} while (input != '9');

	}
	catch (const char* err)
	{
		cout << err << endl;
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
