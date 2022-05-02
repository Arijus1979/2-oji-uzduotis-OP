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

    stringstream buffer;

    vector<class_studentas> cl_studentas;

    class_studentas cl_s;

    auto startTime = high_resolution_clock::now();
    for (int i = 0; i < b; i++)
    {
        //in >> s.vardas >> s.pavarde;
        in >> vardas;
        cl_s.setName(vardas);
        in >> pavarde;
        cl_s.setSurname(pavarde);

        for (int j = 0; j < a; j++)
        {
            in >> paz;
            sum += paz;
        }
        //in >> s.egz;
        in >> egz;
        cl_s.setEgz(egz);

        //s.gal = (0.4 * (sum / (float)a)) + (0.6 * (float)s.egz);
        gal = (0.4 * (sum / (float)a)) + (0.6 * (float)cl_s.getEgz());
        cl_s.setGal(gal);
        sum = 0;
        cl_studentas.push_back(cl_s);
    }

    auto endTime = high_resolution_clock::now();
    duration<double> diff = endTime - startTime; // Skirtumas (s)
    cout << "nuskaitymas uztruko: " << diff.count() << endl;

    vector <class_studentas> cl_vargseliai;
    startTime = high_resolution_clock::now();
    sort(cl_studentas.begin(), cl_studentas.end(), rusiavimas3);
    
    vector<class_studentas>::iterator it = cl_studentas.end();
    it--;
    while (it->getGal() < 5.0)
    {
        cl_vargseliai.push_back(*it);
        cl_studentas.pop_back();
        it = cl_studentas.end();
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

    cl_studentas.shrink_to_fit();
    cl_vargseliai.shrink_to_fit();

    startTime = high_resolution_clock::now();

    for (int i = 0; i < cl_vargseliai.size(); i++)
    {
        buffer << left << setw(20) << cl_vargseliai[i].getName();
        buffer << left << setw(20) << cl_vargseliai[i].getSurname();
        buffer << left << setw(20) << cl_vargseliai[i].getGal() << endl;
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
    for (int i = 0; i < cl_studentas.size(); i++)
    {
        buffer << left << setw(20) << cl_studentas[i].getName();
        buffer << left << setw(20) << cl_studentas[i].getSurname();
        buffer << left << setw(20) << cl_studentas[i].getGal() << endl;
    }
    endTime = high_resolution_clock::now();

    cl_studentas.clear();
    cl_vargseliai.clear();
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