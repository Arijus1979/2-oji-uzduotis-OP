#pragma once

#include "Strukturos.h"

using namespace std;
ifstream in("kursiokai.txt");

bool skaitymasisfailo = false; //tikrinimas



void skaicius(int& a) //funkcija neleidzianti ivesti raides ten kur reikia skaiciaus
{
    cin >> a;
    while (!cin)
    {
        cin.clear(); // reset failbit
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //praleidziame neteisinga ivesti
        cout << "Prasome ivesti skaiciu: ";
        cin >> a;
    }
}

void skaiciavimai(vector<stud>& studentas, int j, int pazsum, int i) //skaiciavimo funkcijos
{
    float mediana;
    sort(studentas[i].nd.begin(), studentas[i].nd.end());
    studentas[i].nd.erase(studentas[i].nd.begin());
    if (j == 1)
        mediana = studentas[i].nd[j];
    else if (j % 2 == 0) //medianos skaiciavimas jei nariu skaicius yra lyginis
    {
        mediana = (studentas[i].nd[j / 2] + studentas[i].nd[j / 2 - 1]) / 2.0;
    }
    else        //medianos skaiciavimas jei nariu skaicius nelyginis
        mediana = (studentas[i].nd[j / 2]);

    studentas[i].med = mediana;


    studentas[i].gal = (0.4 * (pazsum / (float)j)) + (0.6 * studentas[i].egz);
    studentas[i].med = (0.4 * (pazsum / (float)j)) + (0.6 * studentas[i].med);
}

void ivedimas(vector<stud>& studentas, int& i)
{
    studentas.push_back(stud());
    string v, p;
    int a = 1;
    float pazsum = 0; // pazymiu suma
    int j = 0;
    int u;
    char A;

    while (true)
    {
        cout << "Iveskite studento varda ir pavarde: ";
        cin >> v >> p;
        studentas[i].vardas = v;
        studentas[i].pavarde = p;
        cout << "Ar norite atsitiktinai sugeneruoti mokinio namu darbu ir egzamino pazymius? (Y/N) ";
        while (true)
        {
            cin >> A;
            if (A != 'y' && A != 'n' && A != 'Y' && A != 'N')
                cout << "Y/N ";
            else break;
        }
        if (A == 'Y' || A == 'y')
        {
            cout << "Iveskite norimu sugeneruoti pazymiu skaiciu: ";
            skaicius(u);
            for (int p = 0; p < u; p++)
            {
                a = rand() % 10 + 1;
                studentas[i].nd.push_back(a);
                pazsum += a;
                j++;
            }
            j++;
            a = rand() % 10 + 1;
            studentas[i].egz = a;
            a = 1;
        }
        else
        {
            cout << "Veskite studento pazymius, baige vesti, iveskite 0: ";
            while (true)
            {

                if (a != 0)
                {
                    skaicius(a);
                    while (a < 0 || a>10)
                    {
                        cout << "Prasome ivesti pazymi intervale [1, 10]: ";
                        skaicius(a);
                    }
                    studentas[i].nd.push_back(a);
                    pazsum += a;
                    j++;
                }
                else
                {
                    if (pazsum == 0)
                    {
                        cout << "prasome ivesti bent viena pazymi: ";
                        skaicius(a);
                        pazsum += a;
                    }
                    else
                        break;
                }

            }
            cout << "Iveskite egzamino rezultata: ";
            skaicius(a);
            while (a < 0 || a>10)
            {
                cout << "Prasome ivesti pazymi intervale [0, 10]: ";
                skaicius(a);
            }
            studentas[i].egz = a;
            a = 1;
        }

        j--;

        skaiciavimai(studentas, j, pazsum, i);

        cout << "Ar norite ivesti kita mokini? (Y/N) ";
        while (true)
        {
            cin >> A;
            if (A != 'y' && A != 'n' && A != 'Y' && A != 'N')
                cout << "Y/N ";
            else break;
        }
        if (A == 'n' || A == 'N')
        {
            break;
        }
        j = 0;
        i++;
        pazsum = 0;
        studentas.push_back(stud());
    }
}

bool rusiavimasvard(stud& a, stud& b)
{
    return a.vardas < b.vardas;
}

bool rusiavimaspavard(stud& a, stud& b)
{
    return a.pavarde < b.pavarde;
}

void isvedimas(int i, vector<stud> studentas)  //duomenu isvedimo funkcija
{
    char A;
    cout << "Ar rezultatus norite rusiuoti pagal varda ar pavarde? [V/P] ";
    while (true)
    {
        cin >> A;
        if (A != 'v' && A != 'p' && A != 'V' && A != 'P')
            cout << "V/P ";
        else break;
    }
    if (A == 'V' || A == 'v')
    {
        sort(studentas.begin(), studentas.end(), rusiavimasvard);
    }
    else
        sort(studentas.begin(), studentas.end(), rusiavimaspavard);


    stringstream my_buffer;
    my_buffer << "|" << left << setw(20) << "Vardas" << "|" << left << setw(20) << "Pavarde" << "|" << left << setw(20) << "Galutinis (Vid.)" << "|" << left << setw(20) << "Galutinis (Med.)" << endl;

    if (skaitymasisfailo == false)
    {
        for (int k = 0; k <= i; k++)
        {
            my_buffer << "|" << left << setw(20) << studentas[k].vardas << "|" << left << setw(20) << studentas[k].pavarde << "|" << left << setw(20) << fixed << setprecision(2) << studentas[k].gal << "|" << left << setw(20) << fixed << setprecision(2) << studentas[k].med << endl;
        }
    }
    else
    {
        for (int k = 1; k <= i; k++)
        {
            my_buffer << "|" << left << setw(20) << studentas[k].vardas << "|" << left << setw(20) << studentas[k].pavarde << "|" << left << setw(20) << fixed << setprecision(2) << studentas[k].gal << "|" << left << setw(20) << fixed << setprecision(2) << studentas[k].med << endl;
        }
    }

    cout << my_buffer.str();
    my_buffer.clear();
}


int ndkiekis()
{

    string a;
    int q = 0;
    while (true)
    {
        in >> a;
        q++;
        if (a == "Egz.")
        {
            break;
        }

    }
    return q - 3;
}

void nuskaitymas(vector<stud>& studentas, int& i)
{
    float pazsum = 0; // pazymiu suma
    int ndpaz;
    int kieknd = ndkiekis();
    studentas.push_back(stud());
    while (!in.eof())
    {
        in >> studentas[i].vardas >> studentas[i].pavarde;
        for (int q = 0; q < kieknd; q++)
        {
            in >> ndpaz;
            studentas[i].nd.push_back(ndpaz);
            pazsum += ndpaz;
        }
        in >> studentas[i].egz;

        skaiciavimai(studentas, kieknd, pazsum, i);

        i++;
        pazsum = 0;
        studentas.push_back(stud());
    }
    skaitymasisfailo = true;
}