#ifndef VSTRATEGY2_H_INCLUDED
#define VSTRATEGY2_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <time.h>
#include<iterator>

using namespace std;

string IntToStr(int n);
struct studentai
{
    string vardas, pavarde;
    double galutinis;
};

void rikiavimas(vector <studentai> mok, int failoSK);
bool lyginimas(const studentai& a, const studentai& b);

#endif // VSTRATEGY2_H_INCLUDED
