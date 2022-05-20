# Bendra informacija
2021-2022 žiemos ir pavasario semestras
Objektinis + procedūrinis programavimas => Kursinis darbas: žaidimas tinklinis

# Apie žaidimą
Žaidimas kurį matote nėra orginalaus dizaino ar idėjos (Pats suprogramuotas kodas aišku yra mano darbas). 
*Pagrindinis tikslas*: sukurti kažką panašaus į Rhett Anderson 1988 sukurą žaidimą "Arcade Volleyball". 
"Arcade Volleyball" yra labai paprastas tinklinio simuliatorius vienam arba dviem žaidėjams. 
Mano sukurtoje versijoje yra skirta vienam žaidėjui, nes oponentą valdo AI algoritmas. Visos žaidėjų tekstūros irgi yra paimtos iš orginalaus žaidimo.

## Žaidimo tikslas
*Žaidimo tikslas*: neleisti kamuoliui paliesti žemės savo ekrano pusėje, o kartu stengtis pasiųsti kamuolį priešininkui taip, kad jis negalėtų jo atmušti.

# Darbo eiga
## Žiemos semestras: 
- Sugalvota pati įdėja ir parašytas kodas, __kuris veikė__, bet nebuvo pats objektiškiausias ar logiškiausias ar gražiausias. Beveik viskas buvo parašyta main.cpp faile.
Tikslas buvo padaryti, kad bent jau veiktų ir būtų panašu į tinklinį. Šis tikslas buvo įgyvendintas :)

## Pavasario semestras:
-Žaidimas buvo patobulintas pritaikant objektinio programavimo žinias įgytas per pavasario semestrą objektinio programavimo paskaitose. 
Tai yra sukurta ir panaudota:
    1. klasės (tiek bazinė klasė, tiek atskiros objektų klasės), vykdomas klasių paveldėjimas, naudojami virtual elementai;
    2. operatorių perkrovimas;
    3. STL konteineris: vector;
    4. Metodų ir klasių paskirstymas į atskirus .h ir .cpp failus;
    5. <dynamic_cast>, pointer'iai ir referesai;
    6. pridėtas algoritmas, kuris padaro, kad vienas žaidėjas nebūtų valdomas klavietūros, o kompiuterio.
    7. srand() ir rand() panaudotas, kad kamuolys nuo žaidėjo atsimuštu į random pusę.
