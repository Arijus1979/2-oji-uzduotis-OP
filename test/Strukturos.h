#pragma once

using namespace std;
using namespace std::chrono;

ifstream in("kursiokai.txt");

bool skaitymasisfailo = false;


struct stud {              //struktura studento duomenims saugoti
    string vardas;
    string pavarde;
    vector<int> nd;
    float egz;
    float gal;
    float med;
};

void ar_egzistuoja(const string& name);
void skaicius(int& a);
void skaiciavimai(vector<stud>& studentas, int j, int pazsum, int i);
void ivedimas(vector<stud>& studentas, int& i);
bool rusiavimasvard(stud& a, stud& b);
bool rusiavimaspavard(stud& a, stud& b);
void isvedimas(int i, vector<stud> studentas);
int ndkiekis();
void nuskaitymas(vector<stud>& studentas, int& i);
void failogeneracija(string& filename, int a, int b);
void fruspagalpaz_vector(string& ivedimas, string& kietekai, string& nuskriaustukai, int a, int b);
void fruspagalpaz_deque(string& ivedimas, string& kietekai, string& nuskriaustukai, int a, int b);
void fruspagalpaz_list(string& ivedimas, string& kietekai, string& nuskriaustukai, int a, int b);
void generacija(vector<stud>& studentas, int& i);
void greicioskaiciavimai();