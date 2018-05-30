/*!
 *  \brief     Mokinio pazymiu skaiciavimas
 *  \details   Ivedami mokinio pazymiai ir egzamino ivertinimas (random generavimas, ivestis per konsole ir ivestis is failo, failo generavimas ir container testas) ir apskaiciuojamas galutinis ivertinimas (pazymiu vidurkis, mediana).
 *  \author    Paulius
 *  \version   0.5
 *  \date      2018-05-02
 */
#include "Headeris.h"

int main()
{
	unsigned int a = 10;
	do //pagrindinisas ciklas kuriame pasirenkamas ivesties tipas
	{
		std::cout << "Funkcijos: 1 - random generavimas, 2 - ivestis per konsole, 3 - ivestis is failo, 4 - generuoti faila, 5 - testas, 0 - iseiti." << std::endl;
		try{
			a = ivestiSk(0, 5);
		
			switch(a)
			{
				case 1:	Random(); a = 10; break;
				case 2: Konsole(); a = 10; break;
				case 3: Failas(); a = 10; break;
				case 4: //failo generavimas
				{
					unsigned int n{};
					bool t = true;
					do{ 
						std::cout << "Iveskite, kokio dydzio faila norite sugeneruoti (1-10^7) " << std::endl;
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
						std::cout << "Iveskite dydi x (10^x , Max 10^7): " << std::endl;
						t = false;
						try{
							size = ivestiSk(2, 7);
						}catch (const char* msg) {
    						std::cout << msg << std::endl;
    							t = true;
   						}
					}while (t);
					std::cout << "1-----------------------------------------------------------------------------------" << std::endl;
					for (unsigned int i = 2; i <= size; i++)
					{
						GeneruotiFaila(pow(10, i)); //generuoja faila
						auto start = std::chrono::high_resolution_clock::now();
						Failas(false);
						auto end = std::chrono::high_resolution_clock::now();
						std::cout << "Vector Dydis: "<< std::setw(8)<< (int)pow(10, i) << "  |  "<< std::chrono::duration<double>(end-start).count() << " sekundes" << std::endl;
						std::cout << "-----------------------------------------------------------------------------------" << std::endl;
					}
					std::cout << "2-----------------------------------------------------------------------------------" << std::endl;
					for (unsigned int i = 2; i <= size; i++)
					{
						GeneruotiFaila(pow(10, i));
						auto start = std::chrono::high_resolution_clock::now();
						Failas1(false);
						auto end = std::chrono::high_resolution_clock::now();
						std::cout << "Vector Dydis: "<< std::setw(8)<< (int)pow(10, i) << "  |  "<< std::chrono::duration<double>(end-start).count() << " sekundes" << std::endl;
						std::cout << "-----------------------------------------------------------------------------------" << std::endl;
					}
					GeneruotiFaila(0); // sukuria tuscia faila
					a = 10;
					break;
				}
				case 0: std::cout << "Programos pabaiga." << std::endl; break;
			}
		}catch (const char* msg)
		{
    	std::cout << msg << std::endl;
   		}
	} while (a == 10);
	return 0;
}
