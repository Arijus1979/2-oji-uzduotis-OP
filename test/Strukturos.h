#include <chrono>
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;


struct stud {              //struktura studento duomenims saugoti
    string vardas;
    string pavarde;
    vector<int> nd;
    float egz;
    float gal;
    float med;
};

// Reikia includinti visas priklausomybes: <iostream>, <string>, <vector>, "mediana.h"
class class_studentas {
    // realizacija
private:
    string vardas_;
    string pavarde_;
    double egzaminas_;
    vector<double> nd_;
    float gal_;
    // interfeisas
public:
    class_studentas();
    ~class_studentas();
//-----------setteriai-------------------
    void setName(string a) 
    {
        vardas_ = a;
    }
    void setSurname(string a)
    {
        pavarde_ = a;
    }
    void setEgz(int a)
    {
        egzaminas_ = a;
    }
    void setGal(int a)
    {
        gal_ = a;
    }

//----------getteriai--------------------
    string getName()
    {
        return vardas_;
    }
    string getSurname()
    {
        return pavarde_;
    }
    double getEgz()
    {
        return egzaminas_;
    }
    float getGal()
    {
        return gal_;
    }
};

//bool compare(const class_studentas&, const class_studentas&);
//bool comparePagalPavarde(const class_studentas&, const class_studentas&);
//bool comparePagalEgza(const class_studentas&, const class_studentas&);




void ar_egzistuoja(const string& name);
void skaicius(int& a);
void skaiciavimai(vector<stud>& studentas, int j, int pazsum, int i);
void ivedimas(vector<stud>& studentas, int& i);
bool rusiavimas(stud& a, stud& b);
bool rusiavimas2(stud& a, stud& b);
bool rusiavimas3(class_studentas& a, class_studentas& b);
bool rusiavimasvard(stud& a, stud& b);
bool rusiavimaspavard(stud& a, stud& b);
void isvedimas(int i, vector<stud> studentas);
int ndkiekis();
void nuskaitymas(vector<stud>& studentas, int& i);
void failogeneracija(string& filename, int a, int b);
void fruspagalpaz_vector(string& ivedimas, string& kietekai, string& nuskriaustukai, int a, int b);
void fruspagalpaz_deque(string& ivedimas, string& kietekai, string& nuskriaustukai, int a, int b);
void fruspagalpaz_list(string& ivedimas, string& kietekai, string& nuskriaustukai, int a, int b);

void fruspagalpaz_vector_du(string& ivedimas, string& kietekai, string& nuskriaustukai, int a, int b);
void fruspagalpaz_deque_du(string& ivedimas, string& kietekai, string& nuskriaustukai, int a, int b);
void fruspagalpaz_list_du(string& ivedimas, string& kietekai, string& nuskriaustukai, int a, int b);

void generacija(vector<stud>& studentas, int& i);
void greicioskaiciavimai();