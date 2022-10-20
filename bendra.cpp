#include"bendra.h"
void bendra(string ivestis, int nd, int eilutes)
{
	auto start = std::chrono::high_resolution_clock::now();
	failo_kurimas(nd, eilutes);
	string duom_pav = to_string(eilutes) + ".txt";
	string v_pav = to_string(eilutes) + "v.txt";
	string k_pav = to_string(eilutes) + "k.txt";
	is_failo(ivestis, duom_pav, v_pav, k_pav);
	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
	cout << "visas programos vykdymo laikas: " << diff.count() << "s \n\n";
	system("PAUSE");
};