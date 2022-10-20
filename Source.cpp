#include"bendra.h"

int main()
{
	string a = "";
	cout << "norint skaiciuoti galutini pazymi su vidurkiu spauskite (0), jei su mediana (1): ";
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

	bendra(a, b, 1000);
	bendra(a, b, 10000);
	bendra(a, b, 100000);
	bendra(a, b, 1000000);
	bendra(a, b, 10000000);
}
