#include <bits/stdc++.h>

using namespace std;

struct stud{
    string vardas;
    string pavarde;
    vector<int> nd;
    float egz;
    float gal;
};

int main()
{
    vector<stud> studentas;
    studentas.push_back(stud());
    string v, p;
    int a=1;
    float pazsum=0; // pazymiu suma
    int i=0;
    float j=0;
    while(true)
    {
        
        cout << "Iveskite studento varda ir pavarde: ";
        cin >> v >> p;
        studentas[i].vardas = v;
        studentas[i].pavarde = p;
        cout << "Veskite studento pazymius, baige vesti, iveskite 0: ";
        while(true)
        {
            if(a!=0)
            {
                cin >> a;
                studentas[i].nd.push_back(a);
                pazsum += a;
                j++;
            }
            else
                break;
        }
        cout << "Iveskite egzamino rezultata: ";
        cin >> a;
        studentas[i].egz = a;
        a=1;
        j--;
        studentas[i].gal = (0.4*(pazsum/j)) + (0.6*studentas[i].egz);

        cout << "Ar norite ivesti kita mokini? (Y/N) ";
        char A;
        

        while(true)
        {
            cin >> A;
            if (A != 'y' && A != 'n' && A != 'Y' && A != 'N')
                cout << "Y/N ";
            else break;
        }
        if(A == 'n' || A == 'N')
        {
            break;
        }
        j=0;
        i++;
        pazsum=0;
        studentas.push_back(stud());
    }

    for(int k=0; k <= i; k++)
    {
        cout << studentas[k].vardas << " " << studentas[k].pavarde << " " << studentas[k].gal << endl;
    }

    cout << "|"<< left << setw(20) << "Vardas" << "|" << left << setw(20) << "Pavarde" << "|" << left << setw(20) << "Galutinis (Vid.)"<< "|" << left << setw(20) << "Galutinis (Med.)" << endl;
    for(int k=0; k <= i; k++)
    {
        cout << "|"<< left << setw(20) << studentas[k].vardas << "|" << left << setw(20) << studentas[k].pavarde << "|" << left << setw(20) << fixed << setprecision(2) << studentas[k].gal << "|" << endl;
    }

}
