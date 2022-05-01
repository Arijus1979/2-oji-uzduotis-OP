#include <bits/stdc++.h>


using namespace std;

struct stud {                //struktura studento duomenims saugoti
    string vardas;
    string pavarde;
    int kiekis;
    int* nd = new int[2];
    float egz;
    float gal;
    float med;
};

void resize(stud* studentas, int& size) 
{
    stud* resize_arr = new stud[size + 1];
    for (int i = 0; i < size; i++)
        resize_arr[i] = studentas[i];
    size++;
    studentas = resize_arr;
    delete[] resize_arr;
}

void resize_nd(int* studentas, int& size) 
{
    int* resize_arr = new int[size + 1];
    for (int i = 0; i < size; i++)
        resize_arr[i] = studentas[i];
    size++;
    studentas = resize_arr;
    delete[] resize_arr;
}


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

void skaiciavimai(stud* studentas, int j, int pazsum, int i) //skaiciavimo funkcijos
{
    float mediana;
    
    sort(studentas[i].nd, studentas[i].nd + j);

    if (j == 1)
        mediana = studentas[i].nd[j];
    else if (j % 2 == 0) //medianos skaiciavimas jei nariu skaicius yra lyginis
    {
        mediana = (studentas[i].nd[j/2] + studentas[i].nd[j/2 - 1]) / 2.0;
    }
    else        //medianos skaiciavimas jei nariu skaicius nelyginis
        mediana = (studentas[i].nd[j / 2]);

    studentas[i].med = mediana;


    studentas[i].gal = (0.4 * (pazsum / (float)j)) + (0.6 * studentas[i].egz);
    studentas[i].med = (0.4 * (pazsum / (float)j)) + (0.6 * studentas[i].med);
}

void ivedimas(stud* studentas, int& i)
{
    string v, p;
    int a = 1;
    float pazsum = 0; // pazymiu suma
    int j = 0;
    int u;
    while (true)
    {
        cout << "Iveskite studento varda ir pavarde: ";
        cin >> v >> p;
        studentas[i].vardas = v;
        studentas[i].pavarde = p;
        char A;
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
            studentas[i].kiekis = u;
            resize_nd(studentas[i].nd, studentas[i].kiekis);
            for (int p = 0; p < u; p++)
            {
                a = rand() % 10 + 1;
                studentas[i].nd[p] = a;
                pazsum += a;d
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
                    studentas[i].nd[j] = a;
                    resize_nd(studentas[i].nd, j);
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
        resize(studentas, i);
        
        
        pazsum = 0;
        
    }
}

void isvedimas(int i, stud* studentas)  //duomenu isvedimo funkcija
{
    cout << "|" << left << setw(20) << "Vardas" << "|" << left << setw(20) << "Pavarde" << "|" << left << setw(20) << "Galutinis (Vid.)" << "|" << left << setw(20) << "Galutinis (Med.)" << endl;
    for (int k = 0; k <= i; k++)
    {
        cout << "|" << left << setw(20) << studentas[k].vardas << "|" << left << setw(20) << studentas[k].pavarde << "|" << left << setw(20) << fixed << setprecision(2) << studentas[k].gal << "|" << left << setw(20) << studentas[k].med << endl;
    }
}

int main()
{
    srand(time(0));
    stud* studentas = new stud[4];
    int i = 0;

    ivedimas(studentas, i);

    isvedimas(i, studentas);

}
