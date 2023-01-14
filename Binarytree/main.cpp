// Binarytree.cpp : Diese Datei enth�lt die Funktion "main". Hier beginnt und endet die Ausf�hrung des Programms.
//

#include "funktion.cpp"

int main()
{

		
		srand(time(0));

		cout << "Welcher Modus soll gestartet werden?" << endl;
		cout << "1. Testmodus" << endl << "2. Normalmodus" << endl;
		cin >> input;
		switch (input)
		{
		case '1':
			test();
			break;
		case '2':
			start();
			break;
		default:
			cout << "Menuepunkt nicht vorhanden" << endl;
			pause();
		}

		while (input != '9')
		{
			clear();
			cout
				<< "Binarysearchtree" << endl
				<< "Tree:" << tree << endl
				<< "1. Neue Zahl einfuegen" << endl
				<< "2. Zahl loeschen" << endl
				<< "3. Zahl suchen" << endl
				<< "4. Baum loeschen" << endl
				<< "9. Beenden" << endl;
			//cout<< "n. Neustart" << endl; //nur zum debuggen
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
					insertRangeRandomNumber(anzahl);
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
				pause();
				break;
			case '4':
				deletetree();
				pause();
				break;
			case '9':
				cout << endl;
				cout << "Erstellt von " << endl
					 << "Laureen Roccotelli, Hendrik Lange und Julian Tomsa" << endl;
				break;
			/*case 'n':
				deletetree();
				clear();
				main();
				break;*/
			default:
				cout << "Menuepunkt nicht vorhanden" << endl;
				pause();
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
