#include"bendra.h"
void bendra(string ivestis, int nd, int eilutes)
{
	failo_kurimas(nd, eilutes);
	string duom_pav = to_string(eilutes) + ".txt";
	string v_pav = to_string(eilutes) + "v.txt";
	string k_pav = to_string(eilutes) + "k.txt";
	V_is_failo(ivestis, duom_pav, v_pav, k_pav);
	system("PAUSE");
	L_is_failo(ivestis, duom_pav, v_pav, k_pav);
	system("PAUSE");
};