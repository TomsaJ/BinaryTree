#include "test.cpp"

void insertRangeRandomNumber(int afrn)
{
	int min;
	int max;
	clear();
	if (news != "")
	{
		cout << news << endl;
	}
	cout << "Was soll die kleinste Zahl sein" << endl;
	cin >> min;
	cout << "Was soll die groesste Zahl sein" << endl;
	cin >> max;
	if (min > max)
	{
		news = "Kleinere Zahl ist groesser als die groessere Zahl";
		insertRangeRandomNumber(afrn);
		news = "";
		return;
	}
	if (max > maxnumber)
	{
		maxnumber = max;
	}
	clock_t start = clock();
	for (int i = 0; i < afrn;)
	{
		number = 1 + rand() + 1;
		if (number >= min && number <= max)
		{
			tree.insert(number);
			i++;
		}
	}
	clock_t end = clock();
	double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "Benoetigte Zeit zum Loeschen des Baums: " << elapsed_time << "ms" << std::endl;
	pause();
}

void insertownNumber(int afon) //afon: anzahlforownnumber
{
	if (afon > maxnumber)
	{
		maxnumber = afon;
	}

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
		cout << "Zahl ist in dem Tree nicht vorhanden und kann nicht geloescht werden" << endl;
	}

	pause();

}

void deletetree()
{
	int count = 0;
	clock_t start = clock();
	for (int i = 0; i <= maxnumber; i++) // besser ist eine Liste, in der die eingefügten Zahlen gespeichert sind!!!
	{
		while (tree.search(i))
		{
			tree.deleteNode(tree.search(i));
			count++;
		}
	}
	clock_t end = clock();
	double elapsed_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "Benoetigte Zeit um den Baum mit " << count << " Knoten zu loeschen: " << elapsed_time << "ms" << std::endl;
	maxnumber = 0;
}



void start()
{
	cout << "Fuer die Test-Funktion gebe T ein " << endl;
	cout << "Mit wie viele Knoten soll der Baum erstellt werden" << endl;
	cin >> anzahl;
	clear();
	cout << "Wie sollen die " << anzahl << " Knoten erstellt werden" << endl;
	cout << "1. Mit zufaelligen Zahlen" << endl;
	cout << "2. Mit eigene Zahlen" << endl;
	cin >> input;
	switch (input)
	{
	case '1':
		insertRangeRandomNumber(anzahl);
		break;
	case '2':
		insertownNumber(anzahl);
		break;
	default:
		cout << "Menuepunkt nicht vorhanden" << endl;
		pause();
		break;
	}
}
