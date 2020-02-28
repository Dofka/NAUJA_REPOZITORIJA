#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

struct mokinys{
std::string vardas,pavarde;
std::vector<int> v={};
int n=0;
int egz;
int suma=0;
float vidurkis;
float mediana;
double galutinis;
};
void rikiavimas(mokinys studentas[], int zmones);
void rikiavimas1(vector <int> M, int nd);
bool lyginimas(const mokinys& a, const mokinys& b);
double mediana(vector<int>M, int masyvod);
void skaitymas(vector <mokinys> mok);



