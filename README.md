# Bendra informacija
2021-2022 rudens ir pavasario semestras

Objektinis + procedūrinis programavimas => Kursinis darbas: žaidimas tinklinis

# Apie žaidimą
Žaidimas kurį matote nėra orginalaus dizaino ar idėjos (Pats suprogramuotas kodas aišku yra mano darbas). 
*Pagrindinis tikslas*: sukurti kažką panašaus į Rhett Anderson 1988 sukurą žaidimą "Arcade Volleyball". 
"Arcade Volleyball" yra labai paprastas tinklinio simuliatorius vienam arba dviem žaidėjams. 
Mano sukurtoje versijoje yra skirta vienam žaidėjui, nes oponentą valdo AI algoritmas. Visos žaidėjų tekstūros irgi yra paimtos iš orginalaus žaidimo.

## Žaidimo tikslas
*Žaidimo tikslas*: neleisti kamuoliui paliesti žemės savo ekrano pusėje, o kartu stengtis pasiųsti kamuolį priešininkui taip, kad jis negalėtų jo atmušti.

# Galutinis rezultatas
<img src="https://github.com/UlaSv/Tinklinis/blob/master/Resources/Final_result.png" alt="Resultatas" width="450"/>

# Darbo eiga
## Rudens semestras: 
Rudens semestre prasidėjo pati žaidimo pradžia. Išvystyta pati žaidimo idėja. Daugiausiai buvo remiamasi procedūrinio programavimo žiniomis.
1. Susipažinta su žaidimo kurimo eiga ir metodais;
2. Panaudoti SFML bibliotekos pagrindai kuriant objektus;
3. Viskas buvo kuriama main.cpp faile, main() metode;
4. Susipažinta su GitHub erdve ir jos sąsajomis su Microsoft Visual Studio;
Tikslas buvo padaryti, kad programa funkcionuotų ir būtų panaši į tinklinio žaidimą. 

## Pavasario semestras:
Žaidimas buvo patobulintas pritaikant objektinio programavimo žinias, įgytas per pavasario semestrą objektinio programavimo paskaitose. 
Tai yra sukurta ir panaudota:
1. klasės (tiek bazinė klasė, tiek atskiros objektų klasės), vykdomas klasių paveldėjimas, naudojami virtual elementai: metodai ir destruktoriai;
2. operatorių perkrovimas;
3. STL konteineris: vector;
4. metodų ir klasių paskirstymas į atskirus .h ir .cpp failus;
5. <dynamic_cast>, pointer'iai ir referesai;
6. pridėtas algoritmas, kuris padaro, kad vienas žaidėjas nebūtų valdomas klavietūros, o kompiuterio.
7. srand() ir rand() panaudotas, kad kamuolys nuo žaidėjo atsimuštų į nenuspėjamą kryptį.
