#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<random>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::rand;

struct studentas {
	string Vard = "", Pav = "", isved = "";
	int nd[30], egz;
	float GP = 0, med;
};

int main()
{
	vector<studentas> grupe;
	studentas stud;
	cout << "iveskite studentu skaiciu: ";
	int n;
	cin >> n;
	while (cin.fail()) {
		cout << "klaida, iveskite skaiciu  ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> n;
	}
	grupe.reserve(n);
	for (int i = 0; i < n; i++) {
		stud.GP = 0;
		cout << "Iveskite varda: ";
		cin >> stud.Vard;
		cout << "iveskite pavarde: ";
		cin >> stud.Pav;
		cout << "jei norite ivesti pazymius pats spauskite 0 ar sugeneruoti 1  ";
		string generuoja;
		cin >> generuoja;

		int j = 0;

		if (generuoja == "1") {
			cout << "egzamino pazimys: ";
			srand(time(0));
			stud.egz = (rand() % 10) + 1;
			cout << stud.egz << "\n";
			string x = "x";
			cout << "studento nd pazymiai, kai noresite sustoti, irasykite 0: \n";
			while (x != "0") {
				int a = 1 + rand() % 10;
				cout << a << "		";
				stud.nd[j] = a;
				stud.GP = stud.GP + (float)stud.nd[j];
				j++;
				cin >> x;
			}
		}
		else {
			cout << "egzamino pazimys: ";
			int egzaminas;
			cin >> egzaminas;
			while (cin.fail() || egzaminas < 1 || egzaminas>10) {
				cout << "klaida, iveskite skaiciu ne didesni uz 10  ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> egzaminas;
			}
			stud.egz = egzaminas;

			cout << "studento nd pazymiai, kai noresite sustoti, irasykite 0: \n";
			int x = 1;
			cin >> x;
			while (cin.fail() || x < 0 || x>10) {
				cout << "klaida, iveskite teigiama skaiciu, mazesni uz 10 (arba 0) ";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> x;
			}
			while (x != 0) {
				stud.nd[j] = x;
				stud.GP = stud.GP + (float)stud.nd[j];
				j++;
				cin >> x;
				while (cin.fail() || x < 0 || x>10) {
					cout << "klaida, iveskite teigiama skaiciu, mazesni uz 10 (arba 0) ";
					cin.clear();
					cin.ignore(256, '\n');
					cin >> x;
				}
			}

		}
		std::sort(stud.nd, stud.nd + j);
		for (int i = 0; i < j; i++)	cout << stud.nd[i] << "  "; cout << "\n";
		float mediana;
		if (j % 2 == 0)
			mediana = ((float)stud.nd[j / 2 - 1] + (float)stud.nd[j / 2]) / 2;
		else {
			int laik = j / 2 + 0.5;
			mediana = stud.nd[laik];
		}
		stud.med = mediana;
		if (j == 0) stud.GP = 0.6 * stud.egz;
		else {
			stud.GP = stud.GP / j;
			cout << '\n' << stud.GP << '\n';
			stud.GP = stud.GP * 0.4 + 0.6 * stud.egz;
		}
		cout << "ka norite kad isvestu vidurki (0) ar mediana (1)? ";
		string pasirinkimas;
		cin >> pasirinkimas;
		stud.isved = pasirinkimas;
		grupe.push_back(stud);
	}

	cout << std::left << setw(20) << "vardas" << setw(20) << "pavarde" << "galutinis          mediana \n";
	cout << "-------------------------------------------------------------------\n";

	for (auto& tt : grupe) {
		cout << setw(20) << tt.Vard << setw(20) << tt.Pav;

		if (tt.isved != "0") 	cout << setw(20) << "----" << setw(20) << setprecision(2) << fixed << tt.med << "\n";
		else   cout << setw(20) << setprecision(2) << fixed << tt.GP << "\n";
	}
	grupe.clear();
	char a;
	cin >> a;
};