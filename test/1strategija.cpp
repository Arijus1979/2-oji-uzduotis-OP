#pragma once

#include "Strukturos.h"
ifstream in("kursiokai.txt");
bool skaitymasisfailo = false;

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

bool rusiavimas(stud& a, stud& b)
{
    return a.gal < b.gal;
}
bool rusiavimas2(stud& a, stud& b)
{
    return a.gal > b.gal;
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
    ifstream in("kursiokai.txt");
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
    ofstream out1(filename);

    out1 << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde";
    for (int i = 1; i <= a; i++)
    {
        out1 << left << setw(20) << "ND" + to_string(i);
    }
    out1 << left << setw(20) << "Egz." << endl;

    stringstream buffer;
    auto startTime = high_resolution_clock::now();
    for (int i = 1; i <= b; i++)
    {
        //printf(out1, "Vardas %d Pavarde %d", i, i);
        vardas = "Vardas" + to_string(i);
        pavarde = "Pavarde" + to_string(i);
        buffer << left << setw(20) << vardas;
        buffer << left << setw(20) << pavarde;
        for (int j = 0; j < a; j++)
        {
            //fprintf(out1, "%d", rand() % 10 + 1);
            buffer << left << setw(20) << rand() % 10 + 1;
        }
        //fprintf(out1, "%d \n", rand() % 10 + 1);
        buffer << rand() % 10 + 1 << left << setw(20) << endl;
    }

    out1 << buffer.str();
    buffer.str("");
    auto endTime = high_resolution_clock::now();
    out1.close();
    duration<double> diff = endTime - startTime; // Skirtumas (s)
    cout << b << " mokiniu ir ju pazymiu generavimo i faila laikas: " << diff.count() << endl;
}

void fruspagalpaz_vector(string& ivedimas, string& kietekai, string& nuskriaustukai, int a, int b)
{
    int paz, egz, sum = 0;
    float gal;
    string vardas, pavarde;
    ifstream in(ivedimas.c_str());
    ofstream out1(nuskriaustukai.c_str());
    ofstream out2(kietekai.c_str());

    string q;
    a = 0;
    while (true)
    {
        in >> q;
        a++;
        if (q == "Egz.")
        {
            break;
        }

    }
    a = a - 3;
    cout << a << endl;

    vector<stud> studentas;
    stringstream buffer;
    auto startTime = high_resolution_clock::now();
    for (int i = 0; i < b; i++)
    {
        studentas.push_back(stud());
        in >> studentas[i].vardas >> studentas[i].pavarde;
        for (int j = 0; j < a; j++)
        {
            in >> paz;
            sum += paz;
        }
        in >> studentas[i].egz;
        studentas[i].gal = (0.4 * (sum / (float)a)) + (0.6 * (float)studentas[i].egz);
        sum = 0;
    }
    auto endTime = high_resolution_clock::now();
    duration<double> diff = endTime - startTime; // Skirtumas (s)
    cout << "nuskaitymas uztruko: " << diff.count() << endl;

    vector <stud> vargseliai;
    vector <stud> kietiakai;
    startTime = high_resolution_clock::now();
    for (int i = 0; i < b; i++) //for(auto &kint:studentas)
    {
        if (studentas[i].gal < 5)
        {
            vargseliai.push_back(studentas[i]);
        }
        else
            kietiakai.push_back(studentas[i]);
    }
    endTime = high_resolution_clock::now();
    diff = endTime - startTime; // Skirtumas (s)
    cout << b << " dalijimo i dvi grupes laikas: " << diff.count() << endl;

    studentas.clear();
    vargseliai.shrink_to_fit();
    kietiakai.shrink_to_fit();

    startTime = high_resolution_clock::now();

    for (int i = 0; i < vargseliai.size(); i++)
    {
        buffer << left << setw(20) << vargseliai[i].vardas;
        buffer << left << setw(20) << vargseliai[i].pavarde;
        buffer << left << setw(20) << vargseliai[i].gal << endl;
    }

    out1 << buffer.str() << endl;
    buffer.str("");
    endTime = high_resolution_clock::now();
    in.close();
    out1.close();
    diff = endTime - startTime; // Skirtumas (s)
    cout << b << " vargseliu dalijimo i faila laikas: " << diff.count() << endl;

    ifstream in2(ivedimas.c_str());
    a = 0;
    while (true)
    {
        in2 >> q;
        a++;
        if (q == "Egz.")
        {
            break;
        }

    }
    a = a - 3;

    startTime = high_resolution_clock::now();
    for (int i = 0; i < kietiakai.size(); i++)
    {
        buffer << left << setw(20) << kietiakai[i].vardas;
        buffer << left << setw(20) << kietiakai[i].pavarde;
        buffer << left << setw(20) << kietiakai[i].gal << endl;
    }
    endTime = high_resolution_clock::now();

    studentas.clear();
    kietiakai.clear();
    vargseliai.clear();
    out2 << buffer.str() << endl;
    buffer.str("");

    in2.close();
    out2.close();
    diff = endTime - startTime; // Skirtumas (s)
    cout << b << " kieteku dalijimo i faila laikas: " << diff.count() << endl;

}

void fruspagalpaz_deque(string& ivedimas, string& kietekai, string& nuskriaustukai, int a, int b)
{
    int paz, egz, sum = 0;
    float gal;
    string vardas, pavarde;
    ifstream in(ivedimas.c_str());

    string q;
    a = 0;
    while (true)
    {
        in >> q;
        a++;
        if (q == "Egz.")
        {
            break;
        }

    }
    a = a - 3;

    deque<stud> studentas;
    auto startTime = high_resolution_clock::now();
    for (int i = 0; i < b; i++)
    {
        studentas.push_back(stud());
        in >> studentas[i].vardas >> studentas[i].pavarde;
        for (int j = 0; j < a; j++)
        {
            in >> paz;
            sum += paz;
        }
        in >> studentas[i].egz;
        studentas[i].gal = (0.4 * (sum / (float)a)) + (0.6 * (float)studentas[i].egz);
        sum = 0;
    }
    auto endTime = high_resolution_clock::now();
    duration<double> diff = endTime - startTime; // Skirtumas (s)
    cout << "nuskaitymas uztruko: " << diff.count() << endl;
    in.close();
    deque <stud> vargseliai;
    deque <stud> kietiakai;

    startTime = high_resolution_clock::now();
    for (int i = 0; i < b; i++)
    {
        if (studentas[i].gal < 5)
        {
            vargseliai.push_back(studentas[i]);
        }
        else
            kietiakai.push_back(studentas[i]);
    }
    endTime = high_resolution_clock::now();
    diff = endTime - startTime; // Skirtumas (s)
    cout << b << " dalijimo i dvi grupes laikas: " << diff.count() << endl;

    studentas.clear();
    kietiakai.clear();
    vargseliai.clear();
}

void fruspagalpaz_list(string& ivedimas, string& kietekai, string& nuskriaustukai, int a, int b)
{
    int paz, egz, sum = 0;
    float gal;
    string vardas, pavarde;
    ifstream in(ivedimas.c_str());

    string q;
    a = 0;
    while (true)
    {
        in >> q;
        a++;
        if (q == "Egz.")
        {
            break;
        }

    }
    a = a - 3;

    list<stud> studentas;
    stud s;
    auto startTime = high_resolution_clock::now();
    for (int i = 0; i < b; i++)
    {
        in >> s.vardas >> s.pavarde;
        for (int j = 0; j < a; j++)
        {
            in >> paz;
            sum += paz;
        }
        in >> s.egz;
        s.gal = (0.4 * (sum / (float)a)) + (0.6 * (float)s.egz);
        sum = 0;
        studentas.push_back(s);
    }
    auto endTime = high_resolution_clock::now();
    duration<double> diff = endTime - startTime; // Skirtumas (s)
    cout << "nuskaitymas uztruko: " << diff.count() << endl;
    in.close();
    list <stud> vargseliai;
    list <stud> kietiakai;

    startTime = high_resolution_clock::now();
    for (int i = 0; i < b; i++)
    {
        if (s.gal < 5)
        {
            vargseliai.push_back(s);
        }
        else
            kietiakai.push_back(s);
    }
    endTime = high_resolution_clock::now();
    diff = endTime - startTime; // Skirtumas (s)
    cout << b << " dalijimo i dvi grupes laikas: " << diff.count() << endl;

    studentas.clear();
    kietiakai.clear();
    vargseliai.clear();
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

    failogeneracija(out1, a, 1000);
    failogeneracija(out2, a, 10000);
    failogeneracija(out3, a, 100000);
    failogeneracija(out4, a, 1000000);
    failogeneracija(out5, a, 10000000);
}

void greicioskaiciavimai()
{
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

    int a = 0;
    char A;
    cout << "Ar norite naudoti 1 studentu dalijimo i dvi kategorijas strategija? [Y/N] ";
    while (true)
    {
        cin >> A;
        if (A != 'y' && A != 'n' && A != 'Y' && A != 'N')
            cout << "Y/N ";
        else break;
    }
    if (A == 'Y' || A == 'y')
    {
        //--------------------------------------------------------------------------------------
        cout << "Ar norite naudoti vector konteineri? [Y/N] ";
        while (true)
        {
            cin >> A;
            if (A != 'y' && A != 'n' && A != 'Y' && A != 'N')
                cout << "Y/N ";
            else break;
        }
        if (A == 'Y' || A == 'y')
        {
            auto startTime = high_resolution_clock::now();
            fruspagalpaz_vector(out1, out1000k, out1000n, a, 1000);
            auto endTime = high_resolution_clock::now();
            duration<double> diff = endTime - startTime; // Skirtumas (s)
            cout << "1000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
            system("pause");
            //--------------------------------------------------------------------------------------
            startTime = high_resolution_clock::now();
            fruspagalpaz_vector(out2, out10000k, out10000n, a, 10000);
            endTime = high_resolution_clock::now();
            diff = endTime - startTime; // Skirtumas (s)
            cout << "10000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
            system("pause");
            //--------------------------------------------------------------------------------------
            startTime = high_resolution_clock::now();

            fruspagalpaz_vector(out3, out100000k, out100000n, a, 100000);
            endTime = high_resolution_clock::now();
            diff = endTime - startTime; // Skirtumas (s)
            cout << "100000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
            system("pause");
            //--------------------------------------------------------------------------------------
            startTime = high_resolution_clock::now();
            fruspagalpaz_vector(out4, out1000000k, out1000000n, a, 1000000);
            endTime = high_resolution_clock::now();
            diff = endTime - startTime; // Skirtumas (s)
            cout << "1000000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
            system("pause");
            //--------------------------------------------------------------------------------------
            startTime = high_resolution_clock::now();

            fruspagalpaz_vector(out5, out10000000k, out10000000n, a, 10000000);
            endTime = high_resolution_clock::now();
            diff = endTime - startTime; // Skirtumas (s)
            cout << "10000000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
            system("pause");
            //--------------------------------------------------------------------------------------

        }
        else
        {
            cout << "Ar norite naudoti deque konteineri? [Y/N] ";
            while (true)
            {
                cin >> A;
                if (A != 'y' && A != 'n' && A != 'Y' && A != 'N')
                    cout << "Y/N ";
                else break;
            }
            if (A == 'Y' || A == 'y')
            {
                auto startTime = high_resolution_clock::now();
                fruspagalpaz_deque(out1, out1000k, out1000n, a, 1000);
                auto endTime = high_resolution_clock::now();
                duration<double> diff = endTime - startTime; // Skirtumas (s)
                cout << "1000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                system("pause");
                //--------------------------------------------------------------------------------------
                startTime = high_resolution_clock::now();
                fruspagalpaz_deque(out2, out10000k, out10000n, a, 10000);
                endTime = high_resolution_clock::now();
                diff = endTime - startTime; // Skirtumas (s)
                cout << "10000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                system("pause");
                //--------------------------------------------------------------------------------------
                startTime = high_resolution_clock::now();

                fruspagalpaz_deque(out3, out100000k, out100000n, a, 100000);
                endTime = high_resolution_clock::now();
                diff = endTime - startTime; // Skirtumas (s)
                cout << "100000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                system("pause");
                //--------------------------------------------------------------------------------------
                startTime = high_resolution_clock::now();
                fruspagalpaz_deque(out4, out1000000k, out1000000n, a, 1000000);
                endTime = high_resolution_clock::now();
                diff = endTime - startTime; // Skirtumas (s)
                cout << "1000000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                system("pause");
                //--------------------------------------------------------------------------------------
                startTime = high_resolution_clock::now();

                fruspagalpaz_deque(out5, out10000000k, out10000000n, a, 10000000);
                endTime = high_resolution_clock::now();
                diff = endTime - startTime; // Skirtumas (s)
                cout << "10000000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                system("pause");
                //--------------------------------------------------------------------------------------
            }
            else
            {
                cout << "Ar norite naudoti list konteineri? [Y/N] ";
                while (true)
                {
                    cin >> A;
                    if (A != 'y' && A != 'n' && A != 'Y' && A != 'N')
                        cout << "Y/N ";
                    else break;
                }
                if (A == 'Y' || A == 'y')
                {
                    auto startTime = high_resolution_clock::now();
                    fruspagalpaz_list(out1, out1000k, out1000n, a, 1000);
                    auto endTime = high_resolution_clock::now();
                    duration<double> diff = endTime - startTime; // Skirtumas (s)
                    cout << "1000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                    system("pause");
                    //--------------------------------------------------------------------------------------
                    startTime = high_resolution_clock::now();
                    fruspagalpaz_list(out2, out10000k, out10000n, a, 10000);
                    endTime = high_resolution_clock::now();
                    diff = endTime - startTime; // Skirtumas (s)
                    cout << "10000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                    system("pause");
                    //--------------------------------------------------------------------------------------
                    startTime = high_resolution_clock::now();

                    fruspagalpaz_list(out3, out100000k, out100000n, a, 100000);
                    endTime = high_resolution_clock::now();
                    diff = endTime - startTime; // Skirtumas (s)
                    cout << "100000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                    system("pause");
                    //--------------------------------------------------------------------------------------
                    startTime = high_resolution_clock::now();
                    fruspagalpaz_list(out4, out1000000k, out1000000n, a, 1000000);
                    endTime = high_resolution_clock::now();
                    diff = endTime - startTime; // Skirtumas (s)
                    cout << "1000000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                    system("pause");
                    //--------------------------------------------------------------------------------------
                    startTime = high_resolution_clock::now();

                    fruspagalpaz_list(out5, out10000000k, out10000000n, a, 10000000);
                    endTime = high_resolution_clock::now();
                    diff = endTime - startTime; // Skirtumas (s)
                    cout << "10000000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                    system("pause");
                    //--------------------------------------------------------------------------------------
                }
                else
                    cout << "Programos pabaiga.";
            }
        }
    }
    else
    {
        //--------------------------------------------------------------------------------------
        cout << "Ar norite naudoti vector konteineri? [Y/N] ";
        while (true)
        {
            cin >> A;
            if (A != 'y' && A != 'n' && A != 'Y' && A != 'N')
                cout << "Y/N ";
            else break;
        }
        if (A == 'Y' || A == 'y')
        {
            auto startTime = high_resolution_clock::now();
            fruspagalpaz_vector_du(out1, out1000k, out1000n, a, 1000);
            auto endTime = high_resolution_clock::now();
            duration<double> diff = endTime - startTime; // Skirtumas (s)
            cout << "1000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
            system("pause");
            //--------------------------------------------------------------------------------------
            startTime = high_resolution_clock::now();
            fruspagalpaz_vector_du(out2, out10000k, out10000n, a, 10000);
            endTime = high_resolution_clock::now();
            diff = endTime - startTime; // Skirtumas (s)
            cout << "10000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
            system("pause");
            //--------------------------------------------------------------------------------------
            startTime = high_resolution_clock::now();

            fruspagalpaz_vector_du(out3, out100000k, out100000n, a, 100000);
            endTime = high_resolution_clock::now();
            diff = endTime - startTime; // Skirtumas (s)
            cout << "100000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
            system("pause");
            //--------------------------------------------------------------------------------------
            startTime = high_resolution_clock::now();
            fruspagalpaz_vector_du(out4, out1000000k, out1000000n, a, 1000000);
            endTime = high_resolution_clock::now();
            diff = endTime - startTime; // Skirtumas (s)
            cout << "1000000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
            system("pause");
            //--------------------------------------------------------------------------------------
            startTime = high_resolution_clock::now();

            fruspagalpaz_vector_du(out5, out10000000k, out10000000n, a, 10000000);
            endTime = high_resolution_clock::now();
            diff = endTime - startTime; // Skirtumas (s)
            cout << "10000000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
            system("pause");
            //--------------------------------------------------------------------------------------

        }
        else
        {
            cout << "Ar norite naudoti deque konteineri? [Y/N] ";
            while (true)
            {
                cin >> A;
                if (A != 'y' && A != 'n' && A != 'Y' && A != 'N')
                    cout << "Y/N ";
                else break;
            }
            if (A == 'Y' || A == 'y')
            {
                auto startTime = high_resolution_clock::now();
                fruspagalpaz_deque_du(out1, out1000k, out1000n, a, 1000);
                auto endTime = high_resolution_clock::now();
                duration<double> diff = endTime - startTime; // Skirtumas (s)
                cout << "1000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                system("pause");
                //--------------------------------------------------------------------------------------
                startTime = high_resolution_clock::now();
                fruspagalpaz_deque_du(out2, out10000k, out10000n, a, 10000);
                endTime = high_resolution_clock::now();
                diff = endTime - startTime; // Skirtumas (s)
                cout << "10000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                system("pause");
                //--------------------------------------------------------------------------------------
                startTime = high_resolution_clock::now();

                fruspagalpaz_deque_du(out3, out100000k, out100000n, a, 100000);
                endTime = high_resolution_clock::now();
                diff = endTime - startTime; // Skirtumas (s)
                cout << "100000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                system("pause");
                //--------------------------------------------------------------------------------------
                startTime = high_resolution_clock::now();
                fruspagalpaz_deque_du(out4, out1000000k, out1000000n, a, 1000000);
                endTime = high_resolution_clock::now();
                diff = endTime - startTime; // Skirtumas (s)
                cout << "1000000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                system("pause");
                //--------------------------------------------------------------------------------------
                startTime = high_resolution_clock::now();

                fruspagalpaz_deque_du(out5, out10000000k, out10000000n, a, 10000000);
                endTime = high_resolution_clock::now();
                diff = endTime - startTime; // Skirtumas (s)
                cout << "10000000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                system("pause");
                //--------------------------------------------------------------------------------------
            }
            else
            {
                cout << "Ar norite naudoti list konteineri? [Y/N] ";
                while (true)
                {
                    cin >> A;
                    if (A != 'y' && A != 'n' && A != 'Y' && A != 'N')
                        cout << "Y/N ";
                    else break;
                }
                if (A == 'Y' || A == 'y')
                {
                    auto startTime = high_resolution_clock::now();
                    fruspagalpaz_list_du(out1, out1000k, out1000n, a, 1000);
                    auto endTime = high_resolution_clock::now();
                    duration<double> diff = endTime - startTime; // Skirtumas (s)
                    cout << "1000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                    system("pause");
                    //--------------------------------------------------------------------------------------
                    startTime = high_resolution_clock::now();
                    fruspagalpaz_list_du(out2, out10000k, out10000n, a, 10000);
                    endTime = high_resolution_clock::now();
                    diff = endTime - startTime; // Skirtumas (s)
                    cout << "10000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                    system("pause");
                    //--------------------------------------------------------------------------------------
                    startTime = high_resolution_clock::now();

                    fruspagalpaz_list_du(out3, out100000k, out100000n, a, 100000);
                    endTime = high_resolution_clock::now();
                    diff = endTime - startTime; // Skirtumas (s)
                    cout << "100000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                    system("pause");
                    //--------------------------------------------------------------------------------------
                    startTime = high_resolution_clock::now();
                    fruspagalpaz_list_du(out4, out1000000k, out1000000n, a, 1000000);
                    endTime = high_resolution_clock::now();
                    diff = endTime - startTime; // Skirtumas (s)
                    cout << "1000000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                    system("pause");
                    //--------------------------------------------------------------------------------------
                    startTime = high_resolution_clock::now();

                    fruspagalpaz_list_du(out5, out10000000k, out10000000n, a, 10000000);
                    endTime = high_resolution_clock::now();
                    diff = endTime - startTime; // Skirtumas (s)
                    cout << "10000000" << " irasu programos veikimo laikas: " << diff.count() << endl << endl;
                    system("pause");
                    //--------------------------------------------------------------------------------------
                }
                else
                    cout << "Programos pabaiga.";
            }
        }
    }




}
