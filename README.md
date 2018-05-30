# Paulius Kuprevičius. 3 uzduotis
 ![alt text](https://github.com/PauliusKu/2-uzduotisVEC/blob/master/Pav/WordItOut-word-cloud-2910278.png)
 ## Programos tikslas:
 - Patobulinti 2-osios užduoties realizaciją. Pakeistį studentų struktūrą į klasę.
 
 ## Programos pagrindinės funkcijos:
  1. Sugeneruoti mokinio pažymius (max 10^6) ir atlikti galutinio balo skaičiavimą (ivestis per konsolę).
  2. Įvesti mokinio duomenys ir atlikti galutinio balo skaičiavimą (ivestis per konsolę)    .
  3. Įvesti mokinių doumenys iš 'txt' failo ir išvesti mokinių galutinių balų lentelę per konsolę.
  4. Sugeneruoti norimo dydžio (1-10^7) mokinių 'txt' failą. Mokinio vardo ir pavardės ilgis bei pažymių kiekis: 3-21 simboliai.
## Programos naudojimas
![alt text](https://github.com/PauliusKu/2-uzduotisVEC/blob/master/Pav/Menu.png)
### Meniu pasirinkimai:
    1: random generavimas -> vardas -> pavardė -> kiek norite sugeneruoti -> egzamino įvertinimas ->...
    2: ivestis per konsole -> vardas -> pavardė -> mokinio įverinimai (1-10) -> 0 (pažymių įvesties pabaiga) -> egzamino įvertinimas ->...
    3: ivesti is failo ->...
    4: generuoti faila -> Iveskite, kokio dydzio faila norite sugeneruoti ->...
    5: testas -> Iveskite dydi x (10^x , Max 10^7) ->...
    
  ## Veikimo spartos palyginimas
![alt text](https://github.com/PauliusKu/OP-3/blob/Developer/Pav/NoClass.png)
![alt text](https://github.com/PauliusKu/OP-3/blob/Developer/Pav/Class.png)
##### 1 pav - su struktūra , 2 pav - su klasėmis
      
 - Kaip matome struktūrą pakeitus į klasę programos sparta nežymiai sumažėja.

## Išskaidymas į du konteinerius

```cpp
		auto p = std::partition(Mok.begin(), Mok.end(), Maziau);
		std::vector<Mokiniai> Win(p, Mok.end());
		Mok.erase(p, Mok.end());
```

## Versijų istorija (changelog)

### [Changelog v0.1 (2018-04-24)](https://github.com/PauliusKu/OP-3/releases/tag/v0.1)
#### Pridėta
- Struktūra Mokiniai pakeista į klasą Mokiniai
- Spartos palyginimas tarp klasęs ir struktūros
- Papildytas README failas
#### Pakeista

#### Pašalinta

### [Changelog v0.2 (2018-04-03)](https://github.com/PauliusKu/OP-3/releases/tag/v0.2)
#### Pridėta
- Doxygen sugeneruoti failai
- Pridėtos naujos member funkcijos
- Papildytas README failas
#### Pakeista

#### Pašalinta

### [Changelog v1.0 (2018-05-03)](https://github.com/PauliusKu/OP-3/releases/tag/v1.0)
#### Pridėta
- Unit testingai
#### Pakeista
- Papildytas README failas
#### Pašalinta
