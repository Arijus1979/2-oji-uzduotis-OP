# Programa skirta mokinių galutiniam vidurkiui apskaičiuoti.

### v2.0

> Sukurkite dokumentaciją panaudojant Doxygen 1.5 projekto pagrindu. Įkelkite dokumentaciją (kaip atskirą doxygen katalogą) į repoziciją.
> Realizuokite Unit Testus naudodami Jums labiausiai patinkantį C++ Unit testų framework'ą. Užtenka pademonstruoti, kad supratote, kam jie reikalingi, t.y. užtenka kelių > testų. 
> Sukurkite 1.5 versijai automatinį įdiegimo failą (setup.msi arba setup.exe)
> Galutinėje versijoje turi būti pateikta:
> Tvarkinga github repozicija, kurioje būtų tik Jūsų kurti (source) failai, t.y. jokių naudojamo IDE "šiukšlių".
> Projekto įdiegimo failas, arba jei tokios galimybės nėra make Makefile (Unix OS atveju).
> README.md faile aprašyti visi releasai, bei pakomentuoti gauti rezultatai.
> Parengta naudojimosi instrukcija, t.y. pagrindiniai žingsniai aprašyti tame pačiame README.md faile.
> Parengta įdiegimo instrukcija.

# Programos įdiegimo instrukcija
1. Parsisiunciate [ProgramInstallSetup.msi](https://github.com/Arijus1979/2-oji-uzduotis-OP/releases/download/v2.0/ProgramInstallSetup.msi) failą.
2. Jį pasileidžiate ir vadovaujatės instaliavimo instrukcija.
3. Programa suinstaliuota, ją galite pasileisti su ant darbalaukio atsiradusiu `Vidurkio skaičiavimo programa` failu.

# Programos naudojimosi instrukcija
1. Pasileidžiate instaliuotą programą
2. Vadovaujatės ekrane matomomis instrukcijomis.

### v1.5

- Vietoje Jūsų turimos vienos Studentas (ar kažkaip kitaip pavadintos) klasės sukurkite dvi: bazinę klasę, skirtą bendrai aprašyti žmogų ir tuomet iš jos išvestinę (derived) klasę - Studentas.
- Padarykite, kad žmogui skirta bazinė klasė būtų abstrakčioji klasė, t.y. nebūtų galima sukurti žmogaus tipo objektų, o tik objektus gautus iš jos išvestinių klasių.

### v1.2

Realizuokite visus reikiamus (realizuokitė "Rule of three") ir tinkamus (turinčius prasmę) ir tik šiuos operatorius Jūsų turimai Studentas klasei. Pažymiu, kad nebūtinai visi realizuoti operatoriai turi būti panaudoti Jūsų programose - atminkite, kad Jūs kuriate/kursite programas ne tik sau, todėl įvertinkite ko gali prireikti ateities vartotojams naudojantiems Jūsų Studentas klasę!

### v1.1

- Ankstesnės atliktos užduoties pagrindu susikurti naują repoziciją, t.y., visa git istorija iki v1.0 turi išlikti. Įprastinė procedūra būtų:

- Realizuokite programą pagal rekomendacijas ir reikalavimus pateiktus aprašė. Manau suprantate, kad parėjus iš struktūros į klasę, reikės atlikti atitinkamus pakeitimus visame kode!

- Palyginkite abiejų Jūsų programų: naudojančios struct iš ankstesniojo darbo ir naudojančio class tipo Studentus iš dabartinės realizacijos spartą (veikimo laiką), naudojant vieną fiksuotą konteinerį, pvz. vektorių, pačią greičiausią dalijimo strategiją ir 100000 ir 1000000 dydžio failus. Gautus rezultatus aprašykite README.md faile.

- Atlikite eksperimentinę analizę priklausomai nuo kompiliatoriaus optimizavimo lygio, nurodomo per flag'us: O1, O2, O3 ir papildykite README.md failą gautais rezultatais su optimizavimo flag'ais.

- Padarykite v1.1 releasą pagal ankstesniame darbe aprašytus reikalavimus.

- Rezultatai be "flago"

![image](https://user-images.githubusercontent.com/43725384/166299208-95dedb4c-7ca1-4a58-a53b-7a91f027571e.png)

- Rezultatai su "-O1" flagu

![image](https://user-images.githubusercontent.com/43725384/166299264-6d28650a-5f1c-43f7-a25b-03ec7aa7afab.png)

- Rezultatai su "-O2" flagu

![image](https://user-images.githubusercontent.com/43725384/166299321-11126128-7047-450b-b2c4-90948981985c.png)

- Rezultatai su "-O3" flagu

![image](https://user-images.githubusercontent.com/43725384/166299373-bcf37bef-2133-44df-a4eb-d8ae4baad6fc.png)

