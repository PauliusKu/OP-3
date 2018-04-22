# Paulius KUprevičius. 2 uzduotis
 ![alt text](https://github.com/PauliusKu/2-uzduotisVEC/blob/master/Pav/WordItOut-word-cloud-2910278.png)
## Programos pagrindinės funkcijos:
  1. Sugeneruoti mokinio pažymius (max 10^6) ir atlikti galutinio balo skaičiavimą (ivestis per konsolę).
  2. Įvesti mokinio duomenys ir atlikti galutinio balo skaičiavimą (ivestis per konsolę)    .
  3. Įvesti mokinių doumenys iš 'txt' failo ir išvesti mokinių galutinių balų lentelę per konsolę.
  4. Sugeneruoti norimo dydžio (1-10^7) mokinių 'txt' failą. Mokinio vardo ir pavardės ilgis bei pažymių kiekis: 3-21 simboliai.
  5. Naudojant 2 skirtingas strategijas testuoti vector deque ir list tipo konteinerius ir pateikti ataskaitą.
## Programos naudojimas
![alt text](https://github.com/PauliusKu/2-uzduotisVEC/blob/master/Pav/Menu.png)
### Meniu pasirinkimai:
    1: random generavimas -> vardas -> pavardė -> kiek norite sugeneruoti -> egzamino įvertinimas ->...
    2: ivestis per konsole -> vardas -> pavardė -> mokinio įverinimai (1-10) -> 0 (pažymių įvesties pabaiga) -> egzamino įvertinimas ->...
    3: ivesti is failo ->...
    4: generuoti faila -> Iveskite, kokio dydzio faila norite sugeneruoti ->...
    5: testas -> Iveskite dydi x (10^x , Max 10^7) ->...
### Išvestis:
![alt text](https://github.com/PauliusKu/2-uzduotisVEC/blob/master/Pav/Isvestis.png)
## Veikimo spartos analizė
### I strategija (su algoritmais)

|Container                    |n = 100    |n = 1000     |n = 10000    |n = 100000   |n = 1000000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Vector |0.0009756 s|0.008041 s|0.0741989 s |0.990607  s|10.7395  s|
|Deque |0.0010027 s| 0.0070441 s|0.072219 s |0.933481 s|11.1386 s|
|List |0        s| 0.00603    s|0.0561509 s |0.73796 s|8.16674 s|

### II strategija (su algoritmais)

|Container                    |n = 100    |n = 1000     |n = 10000    |n = 100000   |n = 1000000 |
|-----------------------------|----------|------------|------------|------------|-----------|
|Vector |0.0009053 s|0.006041 s|0.0787989 s |0.89734857  s|10.0808  s|
|Deque |0.0010524 s| 0.0070259 s|0.071581 s |0.8670571 s|9.67171 s|
|List |0        s| 0.00603    s|0.0502584 s |0.604575 s|6.50328 s|
### Išvados:
Čia pateikti I ir II strategijos su algoritmais spartos rodikliai. Jeigu algoritmų nenaudojame, antrtosios strategijos sparta žymiai sumažėja. Visais atvejais (I, II strategijos, su algoritmais, be algoritmų) greičiausiai veikia programa su List konteineriu.

## Programos įdiegimas

  1. Atsisiųskite [**naujausią versiją.**](https://github.com/PauliusKu/2-uzduotisVEC/releases)<br>
  2. Išskleiskite failus į pasirinktą vietą
  3. Per konsolė įveskite:
  
    cd OOP-Task-2/uzd2/cpp
    g++ -std=c++11 *.cpp -o main
    ./main
## Versijos:
### [Changelog v1.0 Galutinis](https://github.com/PauliusKu/2-uzduotisVEC/releases/tag/v1)
#### Pridėta
- 2 skirtingų strategijų įgyvendinimas
- Panaudojami algoritmai
#### Koreguota 
- Dalis funkcijų ir UI
#### Panaikinta
### [Changelog v0.5 Konteinerių testavimas](https://github.com/PauliusKu/2-uzduotisVEC/releases/tag/v0.5)
#### Pridėta
- Testavimas (list ir deque)
- Templates
#### Koreguota 
- Pakeista dalis funkcijų
#### Panaikinta
- Dalis nebereikalingų funkcijų
### [Changelog v0.4 Skirstymas ir greičio matavimas](https://github.com/PauliusKu/2-uzduotisVEC/releases/tag/v0.4)
#### Pridėta
- Testavimas (vektoriai)
- Mokinių skirstymas į kategorijas
#### Koreguota 
- Pakeista dalis funkcijų
#### Panaikinta

#### Skaičiavimo trukmė:
     10 - apie 0.004 s
     100 - apie 0.008 s
     1000 - apie 0.02 s
     10000 - apie 0.1 s
     100000 - apie 1 s
     1000000 - apie 10 s

### [Changelog v0.3 Struktūros](https://github.com/PauliusKu/2-uzduotisVEC/releases/tag/v0.3)
#### Pridėta
- Struktūros
- Exception Handling
- Header files
#### Koreguota
- Dalis veiksmų perkelta į atskiras funkcijas
#### Panaikinta
### [Changelog v0.2 Įvedimas iš failo](https://github.com/PauliusKu/2-uzduotisVEC/releases/tag/v0.2)
#### Pridėta
- įvedimas iš failo
- išvedimas į konsolė (daug mokinių)
- rikiavimas pagal pavardes
#### Koreguota

#### Panaikinta
### [Changelog v0.1 Vectoriai](https://github.com/PauliusKu/2-uzduotisVEC/releases/tag/v0.1)
#### Pridėta

- Random pažymių generavimas
- Madianos skaičiavimas
#### Koreguota

#### Panaikinta

