#include "header.h"

string IntToStr(int n)
{
    stringstream result;
    result << n;
    return result.str();
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
    return a.galutinis < b.galutinis;
}
