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


class studentai
{
    private:
    string vardas_;
    string pavarde_;
    double galutinis_;
    public:
        void SetVardas(string s){
            vardas_ = s;
        }
        string GetVardas()const{
            return vardas_;
        }
        void SetPavarde(string a){
            pavarde_ = a;
        }
        string GetPavarde()const{
            return pavarde_;
        }
        void SetGalutinis(double d){
            galutinis_ = d;
        }
        double GetGalutinis()const{
            return galutinis_;
        }
studentai& operator=(const studentai& mok);

};
string IntToStr(int n);
void rikiavimas(vector <studentai> mok, int failoSK); //rikiavimo funkcija
bool lyginimas( studentai& a,  studentai& b);
ofstream& operator << (ofstream& os, const studentai& mok);

#endif // HEADER_H_INCLUDED
