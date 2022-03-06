#pragma once

using namespace std;
ifstream in("kursiokai.txt");

bool skaitymasisfailo = false;


struct stud {                //struktura studento duomenims saugoti
    string vardas;
    string pavarde;
    vector<int> nd;
    float egz;
    float gal;
    float med;
};
