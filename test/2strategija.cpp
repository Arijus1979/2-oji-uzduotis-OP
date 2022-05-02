#include "Strukturos.h"

void fruspagalpaz_vector_du(string& ivedimas, string& kietekai, string& nuskriaustukai, int a, int b)
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
    startTime = high_resolution_clock::now();
    sort(studentas.begin(), studentas.end(), rusiavimas2);
    vector<stud>::iterator it = studentas.end();
    it--;
    while (it->gal < 5.0)
    {
        vargseliai.push_back(*it);
        studentas.pop_back();
        it = studentas.end();
        it--;
    }


    //for (int i = studentas.size()-1; i >= 0; i--)
    //{
    //    if (studentas[i].gal < 5)
    //    {
    //        vargseliai.push_back(studentas[i]);
    //       //studentas.erase(studentas.begin() + i);
    //        studentas.pop_back();
    //    }
    //}
    endTime = high_resolution_clock::now();
    diff = endTime - startTime; // Skirtumas (s)
    cout << b << " dalijimo i dvi grupes laikas: " << diff.count() << endl;

    studentas.shrink_to_fit();
    vargseliai.shrink_to_fit();

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
    for (int i = 0; i < studentas.size(); i++)
    {
        buffer << left << setw(20) << studentas[i].vardas;
        buffer << left << setw(20) << studentas[i].pavarde;
        buffer << left << setw(20) << studentas[i].gal << endl;
    }
    endTime = high_resolution_clock::now();

    studentas.clear();
    vargseliai.clear();
    out2 << buffer.str() << endl;
    buffer.str("");

    in2.close();
    out2.close();
    diff = endTime - startTime; // Skirtumas (s)
    cout << b << " kieteku dalijimo i faila laikas: " << diff.count() << endl;
}

void fruspagalpaz_deque_du(string& ivedimas, string& kietekai, string& nuskriaustukai, int a, int b)
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

    sort(studentas.begin(), studentas.end(), rusiavimas2);

    startTime = high_resolution_clock::now();
    deque<stud>::iterator it = studentas.end();
    it--;
    while (it->gal < 5.0)
    {
        vargseliai.push_back(*it);
        studentas.pop_back();
        it = studentas.end();
        it--;
    }

    //sort(studentas.begin(), studentas.end(), rusiavimas2);
    //int i = 0;
    //for (int i = studentas.size() - 1; i >= 0; i--)
    //{
    //    if (studentas[i].gal < 5.0)
    //    {
    //        vargseliai.push_back(studentas[i]);
    //        //studentas.erase(studentas.begin() + i);
    //        studentas.pop_back();
    //    }
    //}
    endTime = high_resolution_clock::now();
    diff = endTime - startTime; // Skirtumas (s)
    cout << b << " dalijimo i dvi grupes laikas: " << diff.count() << endl;
    studentas.shrink_to_fit();
    vargseliai.shrink_to_fit();
}

void fruspagalpaz_list_du(string& ivedimas, string& kietekai, string& nuskriaustukai, int a, int b)
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

    studentas.sort(rusiavimas2);

    startTime = high_resolution_clock::now();
    list<stud>::iterator it = studentas.end();
    it--;
    while (it->gal < 5.0)
    {
        vargseliai.push_back(*it);
        studentas.pop_back();
        it = studentas.end();
        it--;
    }
    endTime = high_resolution_clock::now();
    diff = endTime - startTime; // Skirtumas (s)
    cout << b << " dalijimo i dvi grupes laikas: " << diff.count() << endl;

    studentas.clear();
    vargseliai.clear();
}