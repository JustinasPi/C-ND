#include"bendra.h"

int main()
{
	string a = "";
	cout << "norint skaiciuoti galutini pazymi su vidurkiu spauskite 0, jei su mediana bet kuri kita mygtuma: ";
	cin >> a;
	int b;
	cout << "kiek namu darbu turi studentai? ";
	cin >> b;
	while (cin.fail() || b < 0)
	{
		cout << "klaida, iveskite skaiciu  ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> b;
	}

	letas(a, b, 1000);
	greitas(a, b, 1000);
	letas(a, b, 10000);
	greitas(a, b, 10000);
	letas(a, b, 100000);
	greitas(a, b, 100000);
	letas(a, b, 1000000);
	greitas(a, b, 1000000);
	letas(a, b, 10000000);
	greitas(a, b, 10000000);
	system("PAUSE");
}