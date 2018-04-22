/*!
 *  \brief     Mokinio pazymiu skaiciavimas
 *  \details   Ivedami mokinio pazymiai ir egzamino ivertinimas (random generavimas, ivestis per konsole ir ivestis is failo, failo generavimas ir container testas) ir apskaiciuojamas galutinis ivertinimas (pazymiu vidurkis, mediana).
 *  \author    Paulius
 *  \version   0.5
 *  \date      2018-04-02
 */
 #include <chrono>
#include <iostream>
#include <iomanip>  
#include <vector>
#include <algorithm>
#include <fstream>
#include "Headeris.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

int main()
{
	unsigned int a = 10;
	do //pagrindinisas ciklas kuriame pasirenkamas ivesties tipas
	{
		cout << "Funkcijos: 1 - random generavimas, 2 - ivestis per konsole, 3 - ivestis is failo, 4 - generuoti faila, 5 - testas, 0 - iseiti." << endl;
		try{
			a = ivestiSk(0, 5);
		
			switch(a)
			{
				case 1:	Random<std::list<Mokiniai>>(); a = 10; break;
				case 2: Konsole(); a = 10; break;
				case 3: Failas<std::vector<Mokiniai>>(); a = 10; break;
				case 4: //failo generavimas
				{
					unsigned int n{};
					bool t = true;
					do{ 
						cout << "Iveskite, kokio dydzio faila norite sugeneruoti (1-10^7) " << endl;
						t = false;
						try{
							n = ivestiSk(1, 10000000);
						}catch (const char* msg) {
    						std::cout << msg << std::endl;
    						t = true;
   						}
					}while (t);
					GeneruotiFaila(n);
					a = 10;
					break;
				}
				case 5:
				{
					unsigned int size{};
					bool t = true;
					do{ 
						cout << "Iveskite dydi x (10^x , Max 10^7): " << endl;
						t = false;
						try{
							size = ivestiSk(2, 7);
						}catch (const char* msg) {
    						std::cout << msg << std::endl;
    							t = true;
   						}
					}while (t);
					cout << "1-----------------------------------------------------------------------------------" << endl;			
					for (unsigned int i = 2; i <= size; i++)
					{
						GeneruotiFaila(pow(10, i)); //generuoja faila
						auto start = std::chrono::high_resolution_clock::now();
						Failas<std::vector<Mokiniai>>(false);
						auto end = std::chrono::high_resolution_clock::now();
						cout << "Vector Dydis: "<< std::setw(8)<< (int)pow(10, i) << "  |  "<< std::chrono::duration<double>(end-start).count() << " sekundes" << endl;
						auto start1 = std::chrono::high_resolution_clock::now();
						Failas<std::deque<Mokiniai>>(false);
						auto end1 = std::chrono::high_resolution_clock::now();
						cout << "Deque  Dydis: "<< std::setw(8)<< (int)pow(10, i) << "  |  "<< std::chrono::duration<double>(end1-start1).count() << " sekundes" << endl;
						auto start2 = std::chrono::high_resolution_clock::now();
						Failas<std::list<Mokiniai>>(false);
						auto end2 = std::chrono::high_resolution_clock::now();
						cout << "List   Dydis: "<< std::setw(8)<< (int)pow(10, i) << "  |  "<< std::chrono::duration<double>(end2-start2).count() << " sekundes" << endl;
						cout << "-----------------------------------------------------------------------------------" << endl;
					}
					cout << "2-----------------------------------------------------------------------------------" << endl;			
					for (unsigned int i = 2; i <= size; i++)
					{
						GeneruotiFaila(pow(10, i));
						auto start = std::chrono::high_resolution_clock::now();
						Failas1<std::vector<Mokiniai>>(false);
						auto end = std::chrono::high_resolution_clock::now();
						cout << "Vector Dydis: "<< std::setw(8)<< (int)pow(10, i) << "  |  "<< std::chrono::duration<double>(end-start).count() << " sekundes" << endl;
						auto start1 = std::chrono::high_resolution_clock::now();
						Failas1<std::deque<Mokiniai>>(false);
						auto end1 = std::chrono::high_resolution_clock::now();
						cout << "Deque  Dydis: "<< std::setw(8)<< (int)pow(10, i) << "  |  "<< std::chrono::duration<double>(end1-start1).count() << " sekundes" << endl;
						auto start2 = std::chrono::high_resolution_clock::now();
						Failas1<std::list<Mokiniai>>(false);
						auto end2 = std::chrono::high_resolution_clock::now();
						cout << "List   Dydis: "<< std::setw(8)<< (int)pow(10, i) << "  |  "<< std::chrono::duration<double>(end2-start2).count() << " sekundes" << endl;
						cout << "-----------------------------------------------------------------------------------" << endl;
					}
					GeneruotiFaila(0); // sukuria tuscia faila
					a = 10;
					break;
				}
				case 0: cout << "Programos pabaiga." << endl; break;
			}
		}catch (const char* msg)
		{
    	std::cout << msg << std::endl;
   		}
	} while (a == 10);
	return 0;
}
