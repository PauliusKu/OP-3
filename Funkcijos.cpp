#include "Headeris.h"
#include <iostream>
#include <iomanip>  
#include <vector>
#include <algorithm>
#include <fstream>
#include <random>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
		
//----------------------------------------------------------------------------------------
double Vidurkis(vector<int> &Pazymiai)
{
	return double(std::accumulate(Pazymiai.begin(), Pazymiai.end()-1, 0))/(Pazymiai.size()-1)*0.4+Pazymiai.back()*0.6;
}
//----------------------------------------------------------------------------------------
double Mediana(vector<int> &Pazymiai)
{
	std::sort(Pazymiai.begin(), Pazymiai.end()-1);
	if ((Pazymiai.size()-1) % 2 == 0)
	{
		return ((double)(Pazymiai[(Pazymiai.size()-1)/2-1]) + (double)(Pazymiai[(Pazymiai.size()-1)/2]))/2*0.4+Pazymiai[Pazymiai.size()-1]*0.6;
	} else {
		return (Pazymiai[(Pazymiai.size()-1)/2])*0.4+Pazymiai[Pazymiai.size()-1]*0.6;
	}
	
}
//--------------------------------------------------------------------------------------------------------------------------------------
void GeneruotiFaila(unsigned int n) //sugeneruoja n skaiciu irasu
{
	std::ofstream of("Failas.txt"); //irasymo pradzia
	
	std::random_device rd;
	std::mt19937 mt(static_cast<unsigned int>(time(nullptr)));
	for (unsigned int i = 0; i < n; i++)
	{
		std::uniform_int_distribution<char> dist(97,122);
		of << (char)(dist(mt)-32); //generuoja pavardes pirmaja raide
		for (int i = 0; i < (int)dist(mt)-95; i++) //generuoja pavarde
		{
			of << dist(mt);
		}
		of << " ";
		
		of << (char)(dist(mt)-32); //generauoja vardo pirmaja raide
		for (int i = 0; i < (int)dist(mt)-95; i++) //generuoja varda
		{
			of << dist(mt);
		}
		of << " ";
		std::uniform_int_distribution<int> distint(1, 10);
		for (int i = 0; i < (int)dist(mt)-95; i++) //generuoja pazymius
		{
			of << distint(mt) << " ";
		}	
		of << endl;
	}
	of.close();
}
//----------------------------------------------------------------------------------------
bool customCompare(Mokiniai &stud1, Mokiniai &stud2){
    return stud1.pavarde < stud2.pavarde;
}
//----------------------------------------------------------------------------------------
int ivestiSk( int a, int b)
{
	int c{};
	string sk{};
	getline(cin, sk);
	if (sk == "")
	{
		throw "Nieko neivedete";
	}
	for (int i = 0; i < sk.size(); i++)
	{
		if((int)sk[i] < 48 || (int)sk[i] > 57)
		{
			throw "Jusu ivesti simboliai neatitinka reikalavimu";
		}
	}
	c = std::stoi(sk);
	if (c >= a && c <= b)
	{
		return c;
	} else throw "Jusu ivestas skaicius yra per didelis arba per mazas";
}
