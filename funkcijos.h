#pragma once
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<random>
#include <numeric>      
#include <fstream>
#include <chrono>
#include<list>

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::list;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::rand;
using std::left;
using std::ifstream;
using std::ofstream;
using std::to_string;

struct studentas {
	string Vard = "", Pav = "";
	int  egz;
	vector<int>nd;
	float GP = 0, med;
};
void V_is_failo(string ivestis, string duomenys, string isvedimas1, string isvedimas2);

void L_is_failo(string ivestis, string duomenys, string isvedimas1, string isvedimas2);