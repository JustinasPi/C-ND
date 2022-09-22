#include<iostream>
#include <iomanip>
#include<cstdio>
#include<vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct duom {
    double sum = 0;
    double vidurkis, galutinis, mediana;
    char ats;
    string vardai[20];
    string  pavardes[20];
    int pazymiai;
    int kiekis;
    string var;
    string pav;
    int paz[20];
    int egz;
};
duom ivedimas(int& n);
void isvedimas(duom temp, int n);

int main() {
    duom asmuo1, masyvas[25];
    int sum;
    int n, m;
    cout << "Iveskite studentu kieki: "; cin >> n;
    for (int i = 0; i < n; i++) {
        masyvas[i] = ivedimas(m);
        isvedimas(masyvas[i], m);
    }

}


duom ivedimas(int& n) {
    duom asmuo;
    cout << "Iveskite varda: "; cin >> asmuo.var;
    cout << "Iveskite pavarde: "; cin >> asmuo.pav;

    cout << "ar norite random(r) pazimiu ar ivesite patys(m)?"; cin >> asmuo.ats;

    //su ivestais skaiciais

    if (asmuo.ats == 'm') {
        cout << "Iveskite egzamino paz.: "; cin >> asmuo.egz;
        cout << "Iveskite semestro pazymiu kieki:"; cin >> n;
        if (n < 0 || n >= 20) cin >> n;
        for (int kint = 0; kint < n; kint++)
        {
            cout << "Iveskite " << kint + 1 << " pazymi: ";
            cin >> asmuo.paz[kint];
            //skaiciavimai

            asmuo.sum = asmuo.sum + asmuo.paz[kint];
            asmuo.vidurkis = asmuo.sum / n;
            asmuo.galutinis = asmuo.vidurkis * 0.4 + asmuo.egz * 0.6;

        }

        //su random skaiciais

    }
    else if (asmuo.ats == 'r') {
        srand(time(0));
        for (int i = 0; i < 10; i++) {
            asmuo.egz = (rand() % 10) + 1;
        }

        for (int i = 0; i < 10; i++) {
            asmuo.kiekis = (rand() % 10) + 1;
        }


        for (int i = 0; i < asmuo.kiekis; i++) {
            asmuo.paz[i] = (rand() % 10) + 1;
            //skaiciavimai
            asmuo.sum = asmuo.sum + asmuo.paz[i];
            asmuo.vidurkis = asmuo.sum / asmuo.kiekis;
            asmuo.galutinis = asmuo.egz * 0.6 + asmuo.vidurkis * 0.4;



            /*int arr[] = {asmuo.paz[i]};
            int n = sizeof(arr) / sizeof(arr[0]);

            sort(arr, arr + n);

            for (int i = 0; i < n; ++i) {
                cout << arr[i] << " " << endl;
            }*/
        }

    }
    else {
        cout << "IVEDET NE TA RAIDE!!!! " << endl;
    }
    /*for (int i = 0; i < 10; i++) {
        asmuo.vardai[i] = asmuo.var;
        asmuo.pavardes[i] = asmuo.pav;
        asmuo.pazymiai[i] = asmuo.paz;
    }*/

    return asmuo;
}



void isvedimas(duom temp, int n) {
    /*cout << std::left << std::setw(20) << temp.var << std::left << std::setw(20) << temp.pav;
    for (int a=0;a<n;a++) cout<<std::right<<std::setw(5)<<temp.paz[a];
    cout<<std::right<<std::setw(5)<<temp.egz<<endl;*/

    //printf("|%-20s|%-20s|", temp.var.c_str(), temp.pav.c_str());
    //for (int a = 0; a < n; a++) printf("%5d|", temp.paz[a]);
    //printf("%*d|\n", 5, temp.egz);
    printf("|vardas              |pavarde\n");
    printf("------------------------------\n");
    printf("|%-20s|%-20s|\n", temp.var.c_str(), temp.pav.c_str());
    printf("galutinis pazimys yra: % .2f\n", temp.galutinis);
}