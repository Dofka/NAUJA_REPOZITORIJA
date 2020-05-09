#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
#include <time.h>
#include<iterator>
#include<vector>

using namespace std;


class zmones
{
    protected:
    string vardas_;
    string pavarde_;

    public:
        void virtual SetVardas(string s){vardas_ = s;}
        string virtual GetVardas()const{return vardas_;}
        void virtual SetPavarde(string a){pavarde_ = a;}
        string virtual GetPavarde()const{return pavarde_;}



};
class studentai : public zmones
{
    private:
        double galutinis_;
    public:
        void SetGalutinis(double d){galutinis_ = d;}
        double GetGalutinis()const{return galutinis_;}
        studentai& operator=(const studentai& mok);
};
string IntToStr(int n);
void rikiavimas(vector <studentai> mok, int failoSK); //rikiavimo funkcija
bool lyginimas( studentai& a,  studentai& b);
ofstream& operator << (ofstream& os, const studentai& mok);

#endif // HEADER_H_INCLUDED
