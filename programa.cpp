#include <bits/stdc++.h>

using namespace std;

struct stud{
    string vardas;
    string pavarde;
    vector<int> nd;
    float egz;
    float gal;
    float med;
};

int main()
{
    vector<stud> studentas;
    studentas.push_back(stud());
    string v, p;
    int a=1;
    float pazsum=0; // pazymiu suma
    int i=0;
    int j=0;
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
        j--;
        float mediana;
        sort(studentas[i].nd.begin(), studentas[i].nd.end());
        studentas[i].nd.erase(studentas[i].nd.begin());
        for(int q=0; q<j; q++)
        {
            cout << studentas[i].nd[q] << " ";
        }
        cout << endl;
        cout << endl;
        
        if(j%2==0)
        {
            mediana=(studentas[i].nd[j/2]+studentas[i].nd[j/2 - 1])/2.0;
        }
        else
            mediana=(studentas[i].nd[j/2]);
        studentas[i].med = mediana;
        cout << "Iveskite egzamino rezultata: ";
        cin >> a;
        studentas[i].egz = a;
        a=1;
        
        studentas[i].gal = (0.4*(pazsum/(float)j)) + (0.6*studentas[i].egz);
        studentas[i].med = (0.4*(pazsum/(float)j)) + (0.6*studentas[i].med);

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
        cout << "|"<< left << setw(20) << studentas[k].vardas << "|" << left << setw(20) << studentas[k].pavarde << "|" << left << setw(20) << fixed << setprecision(2) << studentas[k].gal << "|" << left << setw(20) << studentas[k].med << endl;;
    }

}
