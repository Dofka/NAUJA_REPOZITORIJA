#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <deque>
#include <list>
using namespace std;

string IntToStr(int n);
struct studentai
{
    string vardas, pavarde;
    double galutinis;
};
void rikiavimas(deque <studentai> mok, int failoSK); //rikiavimo funkcija
bool lyginimas(const studentai& a, const studentai& b);

#endif // HEADER_H_INCLUDED
