#include "Strukturos.h"


int main()
{
    srand(time(0)); // test
    vector<stud> studentas;
    int i = 0;
    char A;

    cout << "Ar norite sukurti naujus duomenu failus? [Y/N] ";
    while (true)
    {
        cin >> A;
        if (A != 'y' && A != 'n' && A != 'Y' && A != 'N')
            cout << "Y/N ";
        else break;
    }
    if (A == 'Y' || A == 'y')
    {
        generacija(studentas, i);
    }
    else
    {
        cout << "Ar turite jau sugeneruotus duomenu failus? [Y/N] ";
        while (true)
        {
            cin >> A;
            if (A != 'y' && A != 'n' && A != 'Y' && A != 'N')
                cout << "Y/N ";
            else break;
        }
        if (A == 'Y' || A == 'y')
        {
            greicioskaiciavimai();
        }
        else
        {
            cout << "Ar norite duomenis nuskaityti is failo? [Y/N] ";
            while (true)
            {
                cin >> A;
                if (A != 'y' && A != 'n' && A != 'Y' && A != 'N')
                    cout << "Y/N ";
                else break;
            }
            if (A == 'Y' || A == 'y')
            {
                try
                {
                    ar_egzistuoja("kursiokai.txt");
                    nuskaitymas(studentas, i);
                    isvedimas(i, studentas);
                }
                catch (const char* msg)
                {
                    cerr << msg << endl;
                }
            }
            else
            {
                ivedimas(studentas, i);
                isvedimas(i, studentas);
            }
        }
    }

}
