#pragma once

#include "Strukturos.h"


void ar_egzistuoja(const string& name)
{
    ifstream jin(name);
    if (!jin)
    {
        jin.close();
        throw "Failas neegzistuoja";
    }
    jin.close();
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
                        throw "Prasome ivesti bent viena pazymi: ";
                        //cout << "prasome ivesti bent viena pazymi: ";
                        try {
                            skaicius(a);
                            pazsum += a;
                        }
                        catch (const char* msg) {
                            cerr << msg << endl;
                        }
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
    ifstream in ("kursiokai.txt");


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
    
    int kieknd = ndkiekis();
    float pazsum = 0; // pazymiu suma
    int ndpaz;
    
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

    in.close();
    
}

void failogeneracija(string& filename, int a, int b)
{
    string vardas, pavarde;
    ofstream out1 (filename.c_str());
    auto startTime = high_resolution_clock::now();
    for (int i = 1; i <= b; i++)
    {
        //printf(out1, "Vardas %d Pavarde %d", i, i);
        vardas = "Vardas" + to_string(i);
        pavarde = "Pavarde" + to_string(i);
        out1 << left << setw(20) << vardas;
        out1 << left << setw(20) << pavarde;
        for (int j = 0; j < a; j++)
        {
            //fprintf(out1, "%d", rand() % 10 + 1);
            out1 << left << setw(20) << rand() % 10 + 1;
        }
        //fprintf(out1, "%d \n", rand() % 10 + 1);
        out1 << rand() % 10 + 1 << left << setw(20) << endl;

    }
    auto endTime = high_resolution_clock::now();
    out1.close();
    duration<double> diff = endTime - startTime; // Skirtumas (s)
    cout << b << " mokiniu ir ju pazymiu generavimo i faila laikas: " << diff.count() << endl;
}

void fruspagalpaz(string& ivedimas, string& kietekai, string& nuskriaustukai, int a, int b)
{
    int paz, egz, sum = 0;
    float gal;
    string vardas, pavarde;
    ifstream in(ivedimas.c_str());
    ofstream out1(nuskriaustukai.c_str());
    ofstream out2(kietekai.c_str());
    auto rusiavimasTime = high_resolution_clock::now();

    auto startTime = high_resolution_clock::now();
    for (int i = 0; i < b; i++)
    {
        in >> vardas >> pavarde;
        for (int j = 0; j < a; j++)
        {
            in >> paz;
            sum += paz;
        }
        in >> egz;
        gal = (0.4 * (sum / (float)a)) + (0.6 * (float)egz);
        if (gal < 5)
        {
            out1 << left << setw(20) << vardas;
            out1 << left << setw(20) << pavarde;
            out1 << left << setw(20) << gal << endl;
        }
        sum = 0;
    }
    auto endTime = high_resolution_clock::now();
    in.close();
    out1.close();
    duration<double> diff = endTime - startTime; // Skirtumas (s)
    cout << b << " vargseliu dalijimo i faila laikas: " << diff.count() << endl;

    ifstream in2(ivedimas.c_str());
    startTime = high_resolution_clock::now();
    for (int i = 0; i < b; i++)
    {
        in2 >> vardas >> pavarde;
        for (int j = 0; j < a; j++)
        {
            in2 >> paz;
            sum += paz;
        }
        in2 >> egz;
        gal = (0.4 * (sum / (float)a)) + (0.6 * (float)egz);
        if (gal >= 5)
        {
            out2 << left << setw(20) << vardas;
            out2 << left << setw(20) << pavarde;
            out2 << left << setw(20) << gal << endl;
        }
        sum = 0;
    }
    endTime = high_resolution_clock::now();
    in2.close();
    out2.close();
    diff = endTime - startTime; // Skirtumas (s)
    cout << b << " kieteku dalijimo i faila laikas: " << diff.count() << endl;
    diff = endTime - rusiavimasTime; // Skirtumas (s)
    cout << b << " dalijimo i dvi grupes laikas: " << diff.count() << endl;

}

void generacija(vector<stud>& studentas, int& i)
{
    int a;
    string out1 = "kursiokai1000.txt";
    string out2 = "kursiokai10000.txt";
    string out3 = "kursiokai100000.txt";
    string out4 = "kursiokai1000000.txt";
    string out5 = "kursiokai10000000.txt";

    string out1000k = "1000k.txt";
    string out1000n = "1000n.txt";
    string out10000k = "10000k.txt";
    string out10000n = "10000n.txt";
    string out100000k = "100000k.txt";
    string out100000n = "100000n.txt";
    string out1000000k = "1000000k.txt";
    string out1000000n = "1000000n.txt";
    string out10000000k = "10000000k.txt";
    string out10000000n = "10000000n.txt";
   

    cout << "Kiek pazymiu turi mokiniai? ";
    skaicius(a);

    auto startTime = high_resolution_clock::now();
    failogeneracija(out1, a, 1000);
    fruspagalpaz(out1, out1000k, out1000n, a, 1000);
    auto endTime = high_resolution_clock::now();
    duration<double> diff = endTime - startTime; // Skirtumas (s)
    cout << "1000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
    system("pause");

    startTime = high_resolution_clock::now();
    failogeneracija(out2, a, 10000);
    fruspagalpaz(out2, out10000k, out10000n, a, 10000);
    endTime = high_resolution_clock::now();
    diff = endTime - startTime; // Skirtumas (s)
    cout << "10000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
    system("pause");

    startTime = high_resolution_clock::now();
    failogeneracija(out3, a, 100000);
    fruspagalpaz(out3, out100000k, out100000n, a, 100000);
    endTime = high_resolution_clock::now();
    diff = endTime - startTime; // Skirtumas (s)
    cout << "100000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
    system("pause");

    startTime = high_resolution_clock::now();
    failogeneracija(out4, a, 1000000);
    fruspagalpaz(out4, out1000000k, out1000000n, a, 1000000);
    endTime = high_resolution_clock::now();
    diff = endTime - startTime; // Skirtumas (s)
    cout << "1000000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
    system("pause");

    startTime = high_resolution_clock::now();
    failogeneracija(out5, a, 10000000);
    fruspagalpaz(out5, out10000000k, out10000000n, a, 10000000);
    endTime = high_resolution_clock::now();
    diff = endTime - startTime; // Skirtumas (s)
    cout << "10000000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
    system("pause");
    
    //#pragma warning(suppress : 4996) FILE* out1 = fopen("kursiokai1000.txt", "w");

    
    /*auto startTime = high_resolution_clock::now();
    for (int i = 1; i <= 1000; i++)
    {
        //printf(out1, "Vardas %d Pavarde %d", i, i);
        vardas = "Vardas" + to_string(i);
        pavarde = "Pavarde" + to_string(i);
        out1 << left << setw(20) << vardas;
        out1 << left << setw(20) << pavarde;
        for (int j = 0; j < a; j++)
        {
            //fprintf(out1, "%d", rand() % 10 + 1);
            out1 << left << setw(20) << rand() % 10 + 1;
        }
        //fprintf(out1, "%d \n", rand() % 10 + 1);
        out1 << rand() % 10 + 1 << left << setw(20) << endl;

    }
    auto endTime = high_resolution_clock::now();
    duration<double> diff = endTime - startTime; // Skirtumas (s)
    cout << diff.count();

    //fclose(out1);
    
    startTime = high_resolution_clock::now();
    for (int i = 1; i <= 10000; i++)
    {
        vardas = "Vardas" + to_string(i);
        pavarde = "Pavarde" + to_string(i);
        ss << left << setw(20) << vardas;
        ss << left << setw(20) << pavarde;
        for (int j = 0; j < a; j++)
        {
            ss << left << setw(20) << rand() % 10 + 1;
        }
        ss << rand() % 10 + 1 << left << setw(20) << endl;
    }
    out2 << ss.str() << endl;
    ss.clear();


    for (int i = 1; i <= 100000; i++)
    {
        vardas = "Vardas" + to_string(i);
        pavarde = "Pavarde" + to_string(i);
        ss << left << setw(20) << vardas;
        ss << left << setw(20) << pavarde;
        for (int j = 0; j < a; j++)
        {
            ss << left << setw(20) << rand() % 10 + 1;
        }
        ss << rand() % 10 + 1 << left << setw(20) << endl;
    }
    out3 << ss.str() << endl;
    ss.clear();


    startTime = high_resolution_clock::now();
    for (int i = 1; i <= 1000000; i++)
    {
        vardas = "Vardas" + to_string(i);
        pavarde = "Pavarde" + to_string(i);
        ss << left << setw(20) << vardas;
        ss << left << setw(20) << pavarde;
        for (int j = 0; j < a; j++)
        {
            ss << left << setw(20) << rand() % 10 + 1;
        }
        ss << rand() % 10 + 1 << left << setw(20) << endl;
    }
    out4 << ss.str() << endl;
    ss.clear();

    for (int i = 1; i <= 10000000; i++)
    {
        vardas = "Vardas" + to_string(i);
        pavarde = "Pavarde" + to_string(i);
        ss << left << setw(20) << vardas;
        ss << left << setw(20) << pavarde;
        for (int j = 0; j < a; j++)
        {
            ss << left << setw(20) << rand() % 10 + 1;
        }
        ss << rand() % 10 + 1 << left << setw(20) << endl;
    }
    out5 << ss.str() << endl;
    ss.clear();*/
}


