
#include <bits/stdc++.h>
#include <vector>

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
using namespace std;
void rikiavimas(mokinys studentas[], int zmones);
void skaitymas(vector <mokinys> mok);
bool lyginimas(const mokinys& a, const mokinys& b);
double mediana(vector<int>M, int masyvod);
int main()
{
    vector<mokinys> mok;
    double zmone, egz,paza;
    int zmones;
    int pasirinkimas, pasirinkimas_spausdinimo;
    int randas;
    int paz;
    int skaic;
    int medsk;
    int medvid;
    string tuscia;
    std::cout<<"Norite skaityti failą(1) ar ivesti ranka(0)"<<endl;
    std::cin>>pasirinkimas_spausdinimo;
        while(std::cin.fail())
        {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Blogas pasirinkimas. Bandykite dar karta ";
        std::cin >> pasirinkimas_spausdinimo;
        }
        //Is failo
        //*****************************************************************************************************8
        if(pasirinkimas_spausdinimo==1)
        {

            skaitymas(mok);
        }









        //*********************************************************************************************************************************************
        //Is failo pabaiga
        else
        {
            std::cout<<"Iveskite mokiniu skaiciu"<<std::endl;
                                std::cin>>zmone;
                                while(std::cin.fail() || zmone==0 || zmone!=(int)zmone)
                                {
                                    std::cin.clear();
                                    std::cin.ignore(10000,'\n');
                                    std::cout << "Ivyko klaida.  Iveskite skaiciu: ";
                                    std::cin >> zmone;
                                }
                                zmones = (int)zmone;
                                mokinys studentas[zmones];
                                std::cout<<"galutini skaiciuoti palei mediana(iveskite 1) ar palei namu darbus (iveskite 0)"<<std::endl;
                                std::cin>>pasirinkimas;
                                while(std::cin.fail() || pasirinkimas>1 || pasirinkimas<0)
                            {
                                std::cin.clear();
                                std::cin.ignore(10000,'\n');
                                std::cout << "Blogas pasirinkimas. Bandykite dar karta ";
                                std::cin >> zmones;
                            }
                                for(int i=0;i<zmones;i++)
                                {
                                    std::cout<<"Mokinio vardas:"<<std::endl;
                                    std::cin>>studentas[i].vardas;
                                    std::cout<<"Mokinio pavarde:"<<std::endl;
                                    std::cin>>studentas[i].pavarde;
                                    std::cout<<"Random(1) ar ne(0)"<<std::endl;
                                    std::cin>>randas;
                                    while(randas!=1 && randas!=0)
                                    {
                                        std::cin.clear();
                                        std::cin.ignore(10000,'\n');
                                        std::cout<<"Blogas pasirinkimas"<<std::endl;
                                        std::cin>>randas;
                                    }
                                    if(randas==1)
                                    {
                                        studentas[i].egz=rand() % 11;
                                        int kiek=rand() % 101;
                                        for(int u=0;u<kiek;u++)
                                        {
                                            paz=rand()%11;
                                            skaic=studentas[i].n;
                                            studentas[i].v.push_back(paz);
                                            studentas[i].suma=studentas[i].suma+paz;
                                            studentas[i].n++;
                                        }
                                    }
                                    else
                                    {
                                        std::cout<<"Egzamino ivertinimas:"<<std::endl;
                                        std::cin>>egz;
                                    while(std::cin.fail() || egz>10 || egz<0 || egz!=(int)egz)
                                    {
                                    std::cin.clear();
                                    std::cin.ignore(10000,'\n');
                                    std::cout << "Ivyko klaida.  Iveskite skaiciu(0-10): ";
                                    std::cin >> egz;
                                    }
                                    studentas[i].egz=(int)egz;
                                    std::cout<<"Iveskite namu darbu ivertinimus (jei baigete rasykite -1)"<<std::endl;
                                    while(true)
                                    {
                                        std::cin>>paza;
                                        while(std::cin.fail()||paza>10||paza<-1, paza!=(int)paza)
                                        {
                                            std::cin.clear();
                                            std::cin.ignore(10000,'\n');
                                            std::cout << "Blogai. Iveskite namu darbu ivertinimus (jei baigete rasykite -1)";
                                            std::cin >> paza;
                                        }
                                      if(paza==-1)
                                            break;
                                      else
                                      {
                                          skaic=studentas[i].n;
                                          studentas[i].v.push_back(paza);
                                          studentas[i].suma=studentas[i].suma+paza;
                                          studentas[i].n++;
                                      }

                                    }
                                    }

                                    studentas[i].vidurkis=studentas[i].suma/studentas[i].n;
                                    if(pasirinkimas == 0)
                                    {
                                        studentas[i].galutinis=(0.4*studentas[i].vidurkis)+(0.6*studentas[i].egz);
                                    }
                                    else
                                    {
                                        rikiavimas(studentas,zmones);
                                        if(studentas[i].n%2==0)
                                        {
                                            medvid=studentas[i].n/2;
                                            studentas[i].galutinis = 0.4*(1.0*(studentas[i].v[medvid-1]+studentas[i].v[medvid])/2)+0.6*studentas[i].egz;
                                        }
                                        else
                                        {
                                            medvid=studentas[i].n/2+1;
                                            studentas[i].galutinis = 0.4*(studentas[i].v[medvid-1])+0.6*(studentas[i].egz);

                                        }
                                    }


                                }






                                std::cout<<"Vardas                 Pavarde              Galutinis Ivertinimas"<<std::endl;
                                for(int i=0;i<zmones;i++)
                                {
                                    std::cout<<studentas[i].vardas<<"           "<<studentas[i].pavarde<<"             "<<std::fixed<<std::setprecision(2)<<studentas[i].galutinis<<std::endl;
                                }
        }



return 0;
}
void rikiavimas(mokinys studentas[], int zmones) //rikiavimo funkcija
{
    for(int z=0;z<zmones;z++)
    {
        for(int i=0;i<studentas[z].n-1;i++)
        for(int j=i+1;j<studentas[z].n;j++)
            if(studentas[z].v[i]>studentas[z].v[j])
            {
                swap(studentas[z].v[i], studentas[z].v[j]);

            }
    }


}
void rikiavimas1(vector <int> M, int nd) //rikiavimo funkcija
{

        for(int i=0;i<nd-1;i++)
        for(int j=i+1;j<nd;j++)
            if(M[i]>M[j])
            {
                swap(M[i], M[j]);

            }



}
bool lyginimas(const mokinys& a, const mokinys& b){
    return a.pavarde < b.pavarde;
}
double mediana(vector<int>M, int masyvod){
    double ats;
    ats = masyvod%2==0 ? (double)(((M[(masyvod/2)-2]) + (M[(masyvod/2)]))/2.0) : M[(masyvod/2)];
    return ats;
}
void skaitymas(vector <mokinys> mok)
{
    ifstream fd;
    ofstream fr ("kursiokai.txt");
    int kiek=0;
    vector <int> M;
    stringstream ss;
    string failas;
    string nereikalinga;
    int pazy, pasirinkimas, medvid;
    int nd=0;
    cout<<"Iveskite duomenu failo pavadinima"<<endl;
    cin>>failas;
    cout<<"pasirinkite ar pagal vidurki(0) ar pagal mediana skaiciuoti galutini bala(1)"<<endl;
    cin>>pasirinkimas;

    fd.open(failas);
    if(fd.is_open())
            {

                ss << fd.rdbuf();
                fd.close();
            }

    ss >> nereikalinga >>nereikalinga;
    while(true)
    {
        ss>>nereikalinga;
        if(nereikalinga == "Egz.")
        {
            break;
        }
        else
        {
            nd++;
        }
    }
    while(!ss.eof())
    {
        mok.push_back(mokinys());
        ss>>mok[kiek].vardas>>mok[kiek].pavarde;
        for(int i=0;i<nd;i++)
        {
            ss>>pazy;
            M.push_back(pazy);
            mok[kiek].suma=mok[kiek].suma+pazy;
            mok[kiek].n++;
        }
        mok[kiek].vidurkis=mok[kiek].suma/mok[kiek].n;
        ss>>mok[kiek].egz;
                                    if(pasirinkimas == 0)
                                    {
                                        mok[kiek].galutinis=(0.4*mok[kiek].vidurkis)+(0.6*mok[kiek].egz);
                                    }
                                    else
                                    {
                                        rikiavimas1(M,nd);
                                        if(mok[kiek].n%2==0)
                                        {
                                            medvid=mok[kiek].n/2;
                                            mok[kiek].galutinis = 0.4*(1.0*(M[medvid-1]+M[medvid])/2)+0.6*mok[kiek].egz;
                                        }
                                        else
                                        {
                                            medvid=mok[kiek].n/2+1;
                                            mok[kiek].galutinis = 0.4*(M[medvid-1])+0.6*(mok[kiek].egz);

                                        }
                                    }
                                    M.clear();


        kiek++;





    }
    sort(mok.begin(),mok.end(),lyginimas);
    for(int i=0;i<kiek;i++)
    {
        fr.width(21);
        fr<<mok[i].vardas;
        fr.width(21);
        fr<<mok[i].pavarde;
        fr.width(21);
        fr<<mok[i].galutinis;
        fr<<endl;
    }


}
