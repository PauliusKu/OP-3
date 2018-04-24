#ifndef HEADERIS_H
#define HEADERIS_H 

#include <typeinfo>
#include <string> 
#include <vector>
#include <deque>
#include <list>
#include <iterator>
#include <sstream>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

class Mokiniai{
	private:
		string pavarde;
		string vardas;
		vector<int> Pazymiai;
		double galBalVid_;
		double galBalMed_;
	public:
		
		Mokiniai() : pavarde(""), vardas(""), galBalVid_(1), galBalMed_(1) {}
    	Mokiniai(std::string v, std::string p, std::vector<int> d) : vardas(v), pavarde(p), Pazymiai(d) {}
    	double getAverage(){return galBalVid_;}
   		std::string getPavarde(){return pavarde;}
   		
   		template <typename T> friend void Isvestis(T &Mok);
   		template <typename T> friend void sortContainer(T &);
   		template <typename T> friend void Nuskaitymas(T &Mok);
   		template <typename T> friend void Failas(bool b = true);
   		template <typename T> friend void Failas1(bool b = true);
   		template <typename T> friend void Random();
   		friend void Konsole();
   		
};

int ivestiSk( int a, int b);
bool customCompare(Mokiniai &, Mokiniai &);
double Vidurkis(vector<int> &Pazymiai);
double Mediana(vector<int> &Pazymiai);
void GeneruotiFaila(unsigned int n);

bool Win (double i) { return (i >= 6);}
//--------------------------------------------------------------------------------------------------
bool customCompare(Mokiniai &stud1, Mokiniai &stud2){
    return stud1.getPavarde() < stud2.getPavarde();
}
//--------------------------------------------------------------------------------------------------
bool Maziau(Mokiniai &stud){
    return stud.getAverage() < 6;
}
//--------------------------------------------------------------------------------------------------
template <typename T> void Isvestis(T &Mok)
{
	int a = 8; int b = 8;
	for (auto& v : Mok)
	{
		if (v.pavarde.size() > a) //randa ilgiausia pavarde
		{
			a = v.pavarde.size();
		}
		if (v.vardas.size() > b) //randa ilgiausia varda
		{
			b = v.vardas.size();
		}
	}	
	cout << std::setw(a+3) << std::left << "Pavarde";
	cout << std::setw(b+1) << std::left << "Vardas";
	cout << std::fixed;
	cout << std::setw(3) << std::left << "Vid   Med" << endl;
	for (unsigned int i = 0; i < a+b+12; i++)
	{
		cout << "-";
	}
	cout << endl;
	unsigned int i = 0;
	for (auto& v : Mok) //isveda visa struktura
	{
		i++;
		cout << i << " ";
		cout << std::setw(a+1) << std::left << v.pavarde;
		cout << std::setw(b+1) << std::left << v.vardas;
		cout << std::fixed;
		cout << std::setw(3) << std::left << std::setprecision(2) << v.galBalVid_ << "  " << v.galBalMed_ << endl;
	}
	for (unsigned int i = 0; i < a+b+12; i++)
	{
		cout << "-";
	}
	cout << endl;	
}
//--------------------------------------------------------------------------------------------------
template <typename T> void Nuskaitymas(T &Mok)
{
	std::ifstream inf("Failas.txt"); //nuskaitymo pradzia
	Mokiniai in;
	
	for (unsigned int i = 0; !inf.eof(); i)
	{
		string input; //ivesties string'as
		inf >> input; //ivestis
		if (input == "")
		{
			if (i == 0)
			{
				throw "Failas tuscias!";
			}
			break;
		}
		if ((input == "1") || (input == "2") || (input == "3") || (input == "4") || (input == "5") || (input == "6") || (input == "7") || (input == "8") || (input == "9") || (input == "10"))
		{	
			in.Pazymiai.push_back(std::stoi (input)); //iraso i vektoriu pazymius
		} else {
			if (i != 0)
			{
				Mok.push_back(in);
			}
			in.pavarde = input; //iveda i vektoriu pavardes
			inf >> input;
			in.vardas = input; //iveda i vektoriu vardus
			i++;
			in.Pazymiai = {};
		}
	}
	Mok.push_back(in);
	inf.close(); //nuskaitymo pabaiga	
}
//--------------------------------------------------------------------------------------------------
template <typename T> void Failas(bool b = true)
{
	T Mok;
	T Win{};
	T Los{};
	try {
    	Nuskaitymas(Mok);
    	
    	sortContainer(Mok);
		//vidurki, mediana ir rusiavimas
		for (auto& v : Mok)
		{
			switch(v.Pazymiai.size())
			{
				case 1: throw "Truksta nd ivertinimu!";
				case 0: throw "Truksta nd ivertinimu ir egzamino ivertinimu!";
			}
			v.galBalVid_ = Vidurkis(v.Pazymiai);
			v.galBalMed_ = Mediana(v.Pazymiai);
		}
		
		unsigned n = std::count_if (Mok.begin(), Mok.end(), Maziau);
		Los.resize(n); Win.resize(Mok.size()-n);

		std::partition_copy (Mok.begin(), Mok.end(), Los.begin(), Win.begin(), Maziau);
		
		
		if (b)
		{
			Isvestis(Mok); //visu duomenu isvestis per konsole
			cout << endl;
			cout << "WINNERS" << endl;
			Isvestis(Win);
			cout << endl;
			cout << "LOSERS" << endl;
			Isvestis(Los);
		}
   	}catch (const char* msg) {
    std::cout << msg << std::endl;
   	}
	
}
//--------------------------------------------------------------------------------------------------
template <typename T> void Failas1(bool b = true)
{
	
	T Mok;
	try {
    	Nuskaitymas(Mok);
    	
		//vidurki, mediana ir rusiavimas
		for (auto& v : Mok)
		{
			switch(v.Pazymiai.size())
			{
				case 1: throw "Truksta nd ivertinimu!";
				case 0: throw "Truksta nd ivertinimu ir egzamino ivertinimu!";
			}
			v.galBalVid_ = Vidurkis(v.Pazymiai);
			v.galBalMed_ = Mediana(v.Pazymiai);
   		 
		}
		
		auto it = Mok.end();
		auto pivot = std::partition (Mok.begin(), Mok.end(), Maziau);
		
		T Win(std::distance(pivot, Mok.end()));
		
		std::copy(pivot, Mok.end(), Win.begin());

		it--;
        pivot--;
		while (it != pivot)
		{
        	Mok.pop_back();
            it--;
        }
		
		sortContainer(Mok);
		sortContainer(Win);
		if (b)
		{
			cout << "LOSERS" << endl;
			Isvestis(Mok);
			cout << endl;
			cout << "WINNERS" << endl;
			Isvestis(Win);
			cout << endl;
		}
   	}catch (const char* msg) {
    std::cout << msg << std::endl;
   	}
	
}
//--------------------------------------------------------------------------------------------------
template <> void sortContainer(std::vector<Mokiniai> &stud){
    std::sort(stud.begin(), stud.end(), customCompare);
}
template <> void sortContainer(std::deque<Mokiniai> &stud){
    std::sort(stud.begin(), stud.end(), customCompare);
}
template <> void sortContainer(std::list<Mokiniai> &stud){
    stud.sort(customCompare);
}
//--------------------------------------------------------------------------------------------------
template <typename T> void Random()
{
	Mokiniai Mok;
	
	cout << "Mokinio vardas: ";
	getline(cin, Mok.vardas);
	cout << "Mokinio pavarde: ";
	getline(cin, Mok.pavarde);
	
	int a = 0;
	int n = 0;
	bool t = true;
	cout << "Pasirinkote: random generavimas." << endl;
	std::random_device rd;
	std::mt19937 mt(static_cast<unsigned int>(time(nullptr)));
	std::uniform_int_distribution<int> dist(1,10);
	
	do{ 
		cout << "Iveskite, kiek pazymiu norite sugeneruoti:" << endl;
		t = false;
		try{
			n = ivestiSk(1, 1000000);
			cout << a << endl;
		}catch (const char* msg) {
    	std::cout << msg << std::endl;
    	t = true;
   		}
	}while (t);
	cout << "Sugeneruoti pazymiai: " << endl;
	for (int i = 0; i < n; i++)
	{
		Mok.Pazymiai.push_back(dist(mt)); //i vektoriu irasomi random pazymiai
		cout << Mok.Pazymiai[i] << " ";
	}
	cout << endl;
	
	do{ //ivedimas is konsoles
		cout << "Mokinio egzamino ivertinimas: ";
		t = false;
		try{
			a = ivestiSk(1, 10);
		}catch (const char* msg) {
    	std::cout << msg << std::endl;
    	t = true;
   		}
	}while (t);
	Mok.Pazymiai.push_back(a);
	
	
	Mok.galBalVid_ = Vidurkis(Mok.Pazymiai);
	Mok.galBalMed_ = Mediana(Mok.Pazymiai); //skaiciuojama mediana perduodama vidurkio kintamajam del isvesties patogumo
	
	T MokiniaiV{Mok};
	Isvestis(MokiniaiV);
	cout << "Funkcijos pabaiga" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;	
	
	
}
//--------------------------------------------------------------------------------------------------
void Konsole()
{
	Mokiniai Mok;
	
	cout << "Mokinio vardas: ";
	getline(cin, Mok.vardas);
	cout << "Mokinio pavarde: ";
	getline(cin, Mok.pavarde);
	
	cout << "Pasirinkote: ivestis per konsole. Noredami pabaigti pazymiu ivedima, iveskite 0" << endl;
	int a = 0;
	bool t = true;

	do{ //ivedimas is konsoles
		cout << Mok.Pazymiai.size()+1 << "-asis pazymys ";
		try{
			a = ivestiSk(0, 10);
			if (a == 0)
			{
				if (Mok.Pazymiai.size() == 0)
				{
					throw "Neivedete nei vieno pazymio";
				} else t = false;
				cout << "Pazymiu ivedimas baigtas" << endl;
			} else Mok.Pazymiai.push_back(a);
		}catch (const char* msg) {
    	std::cout << msg << std::endl;
   		}
	}while (t);
	
	do{ //ivedimas is konsoles
		cout << "Mokinio egzamino ivertinimas: ";
		t = false;
		try{
			a = ivestiSk(1, 10);
		}catch (const char* msg) {
    	std::cout << msg << std::endl;
    	t = true;
   		}
	}while (t);
	Mok.Pazymiai.push_back(a);
	
	Mok.galBalVid_ = Vidurkis(Mok.Pazymiai);
	std::sort (Mok.Pazymiai.begin(), Mok.Pazymiai.end()-1); //rikiavimas
	Mok.galBalMed_ = Mediana(Mok.Pazymiai); //skaiciuojama mediana perduodama vidurkio kintamajam del isvesties patogumo
	vector<Mokiniai> MokiniaiV{Mok};
	Isvestis(MokiniaiV);
	cout << "Funkcijos pabaiga" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------" << endl;
}
#endif
