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

using namespace std;

string IntToStr(int n);
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
        string GetVardas(){
            return vardas_;
        }
        void SetPavarde(string a){
            pavarde_ = a;
        }
        string GetPavarde(){
            return pavarde_;
        }
        void SetGalutinis(double d){
            galutinis_ = d;
        }
        double GetGalutinis(){
            return galutinis_;
        }


};
void rikiavimas(deque <studentai> mok, int failoSK); //rikiavimo funkcija
bool lyginimas( studentai& a,  studentai& b);

#endif // HEADER_H_INCLUDED
