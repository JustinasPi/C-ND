#include"bendra.h"
void letas(string ivestis, int nd, int eilutes)
{
	cout << "\n \n L E T A S \n (kuriami 2 nauji konteineriai)\n \n";

	string duom_pav = to_string(eilutes) + "L.txt";
	failo_kurimas(nd, eilutes, duom_pav);
	string v_pav = to_string(eilutes) + "Lv.txt";
	string k_pav = to_string(eilutes) + "Lk.txt";
	auto start = std::chrono::high_resolution_clock::now();
	V_letas(ivestis, duom_pav, v_pav, k_pav);
	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
	cout << "\n VISAS LAIKAS: " << diff.count() << "\n";
	system("PAUSE");
	auto startl = std::chrono::high_resolution_clock::now();
	L_letas(ivestis, duom_pav, v_pav, k_pav);
	std::chrono::duration<double> diffl = std::chrono::high_resolution_clock::now() - startl;
	cout << "\n VISAS LAIKAS: " << diffl.count() << "\n";
	system("PAUSE");
};

void greitas(string ivestis, int nd, int eilutes)
{
	cout << "\n \n G R E I T A S \n (kuriamas tik 1 naujas konteineris)\n \n";

	string duom_pav = to_string(eilutes) + "G.txt";
	failo_kurimas(nd, eilutes, duom_pav);
	string v_pav = to_string(eilutes) + "Gv.txt";
	string k_pav = to_string(eilutes) + "Gk.txt";
	auto start = std::chrono::high_resolution_clock::now();
	V_greitas(ivestis, duom_pav, v_pav, k_pav);
	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
	cout << "\n VISAS LAIKAS: " << diff.count() << "\n";
	system("PAUSE");
	auto startl = std::chrono::high_resolution_clock::now();
	L_greitas(ivestis, duom_pav, v_pav, k_pav);
	std::chrono::duration<double> diffl = std::chrono::high_resolution_clock::now() - startl;
	cout << "\n VISAS LAIKAS: " << diffl.count() << "\n";
	system("PAUSE");
};