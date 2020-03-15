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

string IntToStr(int n)
{
    stringstream result;
    result << n;
    return result.str();
}
struct studentai
{
    string vardas, pavarde;
    double galutinis;
};
void rikiavimas(deque <studentai> mok, int failoSK); //rikiavimo funkcija
bool lyginimas(const studentai& a, const studentai& b);
int main ()
{
    ifstream InFile;
    ofstream outFile;
    int Number_of_files=5;
    string filename, nereikalingas;
    int failoSK=1000;
    int k, paz, egz, suma=0;
    studentai st;
    list <studentai> mok;

  for (int i=0;i<Number_of_files;i++)
  {
      clock_t startB, endB;
        startB = clock();
        filename="file_" + IntToStr(failoSK) +".txt";

        cout<< filename << "  \n";

        outFile.open(filename.c_str());
        outFile.width(15);
        outFile<<"Vardas";
        outFile.width(15);
        outFile<<"Pavarde";
        outFile.width(15);
        outFile<<"ND1";
        outFile.width(15);
        outFile<<"ND2";
        outFile.width(15);
        outFile<<"ND3";
        outFile.width(15);
        outFile<<"ND4";
         outFile.width(15);
        outFile<<"ND5";
         outFile.width(15);
        outFile<<"Egz."<<endl;;
        for(int i=0;i<failoSK;i++)
        {
            outFile.width(15);
            outFile<<"ARETAS"<<i+1;
            outFile.width(15);
            outFile<<"ZASIS"<<i+1;

            for(int i=0;i<5;i++)
            {
                k = rand()%11;
                outFile.width(15);
                outFile<<k;
            }
            k = rand()%11;
            outFile.width(15);
            outFile<<k;
            outFile<<endl;

        }

        outFile.close();
        InFile.open(filename.c_str());
        clock_t start, end;
        start = clock();
        InFile>>nereikalingas>>nereikalingas>>nereikalingas>>nereikalingas>>nereikalingas>>nereikalingas>>nereikalingas>>nereikalingas;
        for(int i=0;i<failoSK;i++)
        {
            InFile>>st.vardas>>st.pavarde;
           // cout<<mok[i].vardas<<endl;

            for(int t=0;t<5;t++)
            {
                InFile>>paz;
                suma+=paz;
            }
            InFile>>egz;
            st.galutinis=((1.0*suma/5)*0.4)+(0.6*egz);
           // cout<<mok[i].galutinis<<endl;
            suma=0;
            mok.push_back(st);

        }
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout <<failoSK<<" nuskaityti failus uztruko: "<< time_taken<< " s"<<endl;
        mok.sort(lyginimas);
        clock_t start1, end1;
        start1 = clock();
        filename="file_" + IntToStr(failoSK) +"kieti" + ".txt";
        outFile.open(filename.c_str());
        for(std::list<studentai>::iterator it = mok.begin(); it != mok.end(); it++)
        {


            //cout<<mok[i].vardas<<endl;
                if((it)->galutinis >=5.0)
                {
                    outFile.width(15);
                outFile<<(it)->vardas;
                //cout<<mok[i].vardas;
                outFile.width(15);
                outFile<<(it)->pavarde;
                outFile.width(15);
                outFile<<(it)->galutinis<<endl;
                //cout<<" "<<mok[i].galutinis<<endl;
                }

        }
        outFile.close();
        end1 = clock();
        double time_taken1 = double(end1 - start1) / double(CLOCKS_PER_SEC);
        cout <<failoSK<<" Isskirti i grupe kieti uztruko: "<< time_taken1<< " s"<<endl;
        clock_t start2, end2;
        start2 = clock();

        filename="file_" + IntToStr(failoSK) +"nepasisekeliai" + ".txt";
            outFile.open(filename.c_str());
        for(std::list<studentai>::iterator it = mok.begin(); it != mok.end(); it++)
        {

            //cout<<mok[i].vardas<<endl;
                if((it)->galutinis <5.0)
                {
                    outFile.width(15);
                outFile<<(it)->vardas;
                //cout<<mok[i].vardas;
                outFile.width(15);
                outFile<<(it)->pavarde;
                outFile.width(15);
                outFile<<(it)->galutinis<<endl;
                //cout<<" "<<mok[i].galutinis<<endl;
                }

        }
        outFile.close();
        end2 = clock();
        double time_taken2 = double(end2 - start2) / double(CLOCKS_PER_SEC);
        cout <<failoSK<<" Isskirti i grupe nepasisekeliai uztruko: "<< time_taken2<< " s"<<endl;
        failoSK=failoSK*10;
        cout<<"veikia"<<endl;

        InFile.close();
        endB = clock();
        double time_takenB = double(endB - startB) / double(CLOCKS_PER_SEC);
        cout <<failoSK<<" BENDRAS VEIKIMAS "<< time_takenB<< " s"<<endl;
  }


  return 0;
}
void rikiavimas(deque <studentai> mok, int failoSK) //rikiavimo funkcija
{

        for(int i=0;i<failoSK-1;i++)
        for(int j=i+1;j<failoSK;j++)
            if(mok[i].galutinis>mok[j].galutinis)
            {
                swap(mok[i], mok[j]);
            }
}
bool lyginimas(const studentai& a, const studentai& b){
    return a.galutinis > b.galutinis;
}
