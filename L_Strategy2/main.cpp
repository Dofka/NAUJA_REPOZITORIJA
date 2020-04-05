#include "header.h"

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
    list <studentai> kietiakai;

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
            outFile<<"Vardas"<<i+1;
            outFile.width(15);
            outFile<<"Pavarde"<<i+1;

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
        int sk;
        for(std::list<studentai>::iterator it = mok.begin(); it != mok.end(); it++)
        {
                if((it)->galutinis >= 5.0)
                {
                    kietiakai.push_back(*it);
                    outFile.width(15);
                outFile<<(it)->vardas;
                outFile.width(15);
                outFile<<(it)->pavarde;
                outFile.width(15);
                outFile<<(it)->galutinis<<endl;
                sk++;
                }

        }
        outFile.close();
        end1 = clock();
        double time_taken1 = double(end1 - start1) / double(CLOCKS_PER_SEC);
        cout <<failoSK<<" Isskirti i grupe kieti uztruko: "<< time_taken1<< " s"<<endl;
        clock_t start2, end2;
        start2 = clock();
       mok.resize(mok.size()-kietiakai.size());
        filename="file_" + IntToStr(failoSK) +"nepasisekeliai" + ".txt";
            outFile.open(filename.c_str());
            cout<<"veikia"<<endl;
        for(std::list<studentai>::iterator it = mok.begin(); it != mok.end(); it++)
        {
                    outFile.width(15);
                outFile<<(it)->vardas;
                outFile.width(15);
                outFile<<(it)->pavarde;
                outFile.width(15);
                outFile<<(it)->galutinis<<endl;
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
