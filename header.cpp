#include "header.h"
void rikiavimas(mokinys studentas[], int zmones) //rikiavimo funkcija
{
    for(int z=0;z<zmones;z++)
    {
        for(int i=0;i<studentas[z].n-1;i++)
        for(int j=i+1;j<studentas[z].n;j++)
            if(studentas[z].v[i]>studentas[z].v[j])
            {
                std::swap(studentas[z].v[i], studentas[z].v[j]);

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
    try{
        char a;
    if(failas != " " && fd.is_open())
        throw(a);
    }
    catch(char)
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
