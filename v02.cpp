#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<random>
#include <numeric>      
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::rand;
using std::left;
using std::ifstream;

struct studentas {
	string Vard = "", Pav = "", ivestis = "";
	int  egz;
	vector<int>nd;
	float GP = 0, med;
};

bool Tvarkymas(const studentas& pirmas, const studentas& antras) {
	return pirmas.Vard < antras.Vard;
}

int main()
{
	vector<studentas> grupe;
	studentas stud;
	string pasirinkimas;
	cout << "jei norite skaityti duomenis is failo spauskite 0, jei ne spauskite 1:  ";
	cin >> pasirinkimas;
	if (pasirinkimas != "0") {
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
			stud.nd.reserve(20);
			cout << "Iveskite varda: ";
			cin >> stud.Vard;
			cout << "pavarde: ";
			cin >> stud.Pav;
			string generuoja;
			cout << "jei norite ivesti pazymius pats spauskite 0 ar sugeneruoti 1 ";
			cin >> generuoja;
			if (generuoja != "0") {
				cout << "egzamino pazimys: ";
				srand(time(0));
				stud.egz = 1 + rand() % 10;
				cout << stud.egz << "\n";
				string x = "x";
				cout << "studento nd pazymiai, kai noresite sustoti, irasykite 0: \n";

				while (x != "0") {
					int a = 1 + rand() % 10;
					cout << a << "		";
					stud.nd.push_back(a);
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
					stud.nd.push_back(x);
					cin >> x;
					while (cin.fail() || x < 0 || x>10) {
						cout << "klaida, iveskite teigiama skaiciu, mazesni uz 10 (arba 0) ";
						cin.clear();
						cin.ignore(256, '\n');
						cin >> x;
					}
				}
			}
			sort(stud.nd.begin(), stud.nd.end());
			int c;
			c = stud.nd.size();
			float mediana;
			if (c != 0) {
				if (c % 2 != 0)	mediana = stud.nd[c / 2 + 0.5];
				else    			mediana = ((float)stud.nd[c / 2 - 1] + (float)stud.nd[c / 2]) / 2;
			}
			stud.med = mediana;
			if (c == 0) stud.GP = 0.6 * stud.egz;
			else {
				float suma = 0;
				suma = accumulate(stud.nd.begin(), stud.nd.end(), 0);
				float vid = suma / c;
				stud.GP = vid * 0.4 + 0.6 * stud.egz;
			}
			cout << "ka norite kad isvestu vidurki (0) ar mediana (1)?";
			string ivestis;
			cin >> ivestis;
			stud.ivestis = ivestis;

			grupe.push_back(stud);
			stud.nd.clear();
		}
		cout << left << setw(20) << "vardas" << setw(20) << "pavarde" << "galutinis          mediana \n";
		cout << "-------------------------------------------------------------------\n";
		for (auto& tt : grupe) {
			cout << setw(20) << tt.Vard << setw(20) << tt.Pav;

			if (tt.ivestis != "0") {
				if (tt.nd.size() != 0)
					cout << setw(20) << "----" << setw(20) << setprecision(2) << fixed << tt.med << "\n";
				else
					cout << setw(20) << "----" << setw(20) << "nera" << "\n";
			}
			else 	cout << setw(20) << setprecision(2) << fixed << tt.GP << setw(20) << "----" << "\n";
		}
	}
	else {
		string pav = "";
		string vardai, pavardes, temp, egzaminas;
		vector<string> nd;
		int m;
		ifstream file("kursiokai.txt");
		if (file.good()) {
			file >> vardai >> pavardes >> temp;
			while (temp != "Egz.") {
				nd.push_back(temp);
				file >> temp;
			}
			egzaminas = temp;
			m = nd.size();
			stud.nd.reserve(m);
			while (!file.eof()) {
				studentas stud;
				file >> stud.Vard >> stud.Pav;
				double studpaz;
				for (int i = 0; i < m; i++) {
					file >> studpaz;
					stud.nd.push_back(studpaz);
				}
				file >> stud.egz;
				if (m != 0) {
					if (m % 2 == 1)
						stud.med = stud.nd[m / 2];
					else
						stud.med = (stud.nd[m / 2 - 1] + stud.nd[m / 2]) / 2;
				}
				if (m == 0) {
					stud.GP = stud.egz * 0.6;
				}
				else {
					float bendras = 0;
					bendras = accumulate(stud.nd.begin(), stud.nd.end(), 0);
					stud.GP = bendras / m;
					stud.GP = stud.GP * 0.4 + 0.6 * stud.egz;
				}
				grupe.reserve(grupe.capacity() + 1);
				grupe.push_back(stud);
				stud.nd.clear();
			}
		}

		else cout << "Ivestas failas nebuvo rastas" << endl;

		sort(grupe.begin(), grupe.end(), Tvarkymas);
		string ivestis = "";
		cout << "ka norite kad isvestu vidurki (0) ar mediana (1)? ";
		cin >> ivestis;

		cout << left << setw(20) << "Vardas " << setw(20) << "Pavarde"
			<< setw(20) << "Galutinis (vid) " << setw(20) << "Galutinis (med)";
		cout << "\n-------------------------------------------------------------------------------\n";

		{
			for (auto& d : grupe) {
				cout << left << setw(20) << d.Vard << setw(20) << d.Pav;
				if (ivestis == "0")	cout << setw(20) << setprecision(2) << fixed << d.GP << "----\n";
				else  cout << setw(20) << "----" << setw(20) << setprecision(2) << fixed << d.med << "\n";
			}
		}
	}
	cout << endl;
	grupe.clear();
	char a;
	cin >> a;




	ifstream readFile;
	readFile.exceptions(ifstream::failbit | ifstream::badbit);
	try {
		readFile.open("kursiokai.txt");
		readFile.close();
	}
	catch (std::ifstream::failure& readErr) {
		std::cerr << "\n\nException occured when reading a file\n" << readErr.what() << endl;

		return 0;
	}


}