#ifndef HEADERIS_H
#define HEADERIS_H 

#include <typeinfo>
#include <string> 
#include <vector>
#include <iterator>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>  
#include <fstream>
#include <random>
#include <chrono>
#include <numeric>

/// Mokiniø klasë
class Mokiniai{
	private:
		///Mokinio pavardë
		std::string pavarde;
		///Mokinio vardas
		std::string vardas;
		///Mokinio paþymiai
		std::vector<int> Pazymiai;
		///Mokinio galutinis balas (skaièiuojant vidurká)
		double galBalVid_;
		///Mokinio galutinis balas (skaièiuojant medianà)
		double galBalMed_;
	public:
		/**
     	* Sukonstruoja Mokinio objektà
     	*/
		Mokiniai() : pavarde(""), vardas(""), galBalVid_(1), galBalMed_(1) {}

    	Mokiniai(std::string v, std::string p, std::vector<int> d) : vardas(v), pavarde(p), Pazymiai(d) {}
  		/**
   		* Graþinamas vidurkis
    	* @return Mokinio galBalVid
   		*/
    	double getAverage(){return galBalVid_;}
    	/**
   		* Graþinama pavarde
    	* @return Mokinio pavarde
   		*/
   		std::string getPavarde(){return pavarde;}
   		/**
   		* Mokinio informacijos iðvedimas
  		* @return iðvesties strea'mas
  		*/
   		friend std::ostream &operator<<(std::ostream&, Mokiniai&);
    	/**
    	* Tikrina, kurio mokinio vardas ir pavarde eina pirmiau nei kito
    	* @return Ar mokinio vardas ir pavardë abeceliðkai eina pirmiau nei kito
    	*/
   		bool operator< (const Mokiniai& rhs);
    	/**
    	* Tikrina, kurio mokinio vardas ir pavarde eina vëliau nei kito
    	* @return Ar mokinio vardas ir pavardë abeceliðkai eina vëliau nei kito
    	*/
   		bool operator> (const Mokiniai& rhs);
    	/**
    	* Tikrinama, ar mokinio vardas ir sutampa su kito
    	* @return Ar mokinio vardas ir sutampa su kito
    	*/
   		bool operator== (const Mokiniai& rhs);
    	/**
    	* Tikrinama, ar mokinio vardas ir nesutampa su kito
    	* @return Ar mokinio vardas ir nesutampa su kito
    	*/
   		bool operator!= (const Mokiniai& rhs);
   		
   		friend void Konsole();
   		friend void Isvestis(std::vector<Mokiniai> &Mok);
   		friend void sortContainer(std::vector<Mokiniai> &);
   		friend void Nuskaitymas(std::vector<Mokiniai> &Mok);
   		friend void Failas(bool b);
   		friend void Failas1(bool b);
   		friend void Random();
   		
};

int ivestiSk( int a, int b);
bool customCompare(Mokiniai &, Mokiniai &);
double Vidurkis(std::vector<int> &Pazymiai);
double Mediana(std::vector<int> &Pazymiai);
void GeneruotiFaila(unsigned int n);



void Isvestis(std::vector<Mokiniai> &Mok);
//--------------------------------------------------------------------------------------------------
void Nuskaitymas(std::vector<Mokiniai> &Mok);
//--------------------------------------------------------------------------------------------------
void Failas(bool b = 1);
//--------------------------------------------------------------------------------------------------
void Failas1(bool b = 1);
//--------------------------------------------------------------------------------------------------
void sortContainer(std::vector<Mokiniai> &stud);
//--------------------------------------------------------------------------------------------------
void Random();
//--------------------------------------------------------------------------------------------------
void Konsole();


#endif
