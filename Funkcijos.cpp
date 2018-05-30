#include "Headeris.h"

	
//----------------------------------------------------------------------------------------
double Vidurkis(std::vector<int> &Pazymiai)
{
	return double(std::accumulate(Pazymiai.begin(), Pazymiai.end()-1, 0))/(Pazymiai.size()-1)*0.4+Pazymiai.back()*0.6;
}
//----------------------------------------------------------------------------------------
double Mediana(std::vector<int> &Pazymiai)
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
		std::uniform_int_distribution<int> dist(97,122);
		of << (char)(dist(mt)-32); //generuoja pavardes pirmaja raide
		for (int i = 0; i < (int)dist(mt)-95; i++) //generuoja pavarde
		{
			of << (char)(dist(mt));
		}
		of << " ";
		
		of << (char)(dist(mt)-32); //generauoja vardo pirmaja raide
		for (int i = 0; i < (int)dist(mt)-95; i++) //generuoja varda
		{
			of << (char)(dist(mt));
		}
		of << " ";
		std::uniform_int_distribution<int> distint(1, 10);
		for (int i = 0; i < (int)dist(mt)-95; i++) //generuoja pazymius
		{
			of << distint(mt) << " ";
		}	
		of << std::endl;
	}
	of.close();
}
//----------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------
int ivestiSk( int a, int b)
{
	int c{};
	std::string sk{};
	std::getline(std::cin, sk);
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


std::ostream &operator<<(std::ostream &output, Mokiniai &M) {
	output << M.vardas << " " << M.pavarde << " " << M.galBalVid_ << " " << M.galBalMed_ << std::endl;
	return output;
}
//--------------------------------------------------------------------------------------------------
bool Mokiniai::operator<(const Mokiniai &rhs)
{
	return pavarde <= rhs.pavarde || (pavarde == rhs.pavarde && vardas < rhs.vardas);
}
bool Win(double i) { return (i >= 6); }
//--------------------------------------------------------------------------------------------------
bool Mokiniai::operator>(const Mokiniai &rhs) {
	return !operator<(rhs);
}
//--------------------------------------------------------------------------------------------------
bool Mokiniai::operator==(const Mokiniai &rhs) {
	return vardas == rhs.vardas && pavarde == rhs.pavarde;
}
//--------------------------------------------------------------------------------------------------
bool Mokiniai::operator!=(const Mokiniai &rhs) {
	return !operator==(rhs);
}

//--------------------------------------------------------------------------------------------------
bool customCompare(Mokiniai &stud1, Mokiniai &stud2) {
	return stud1.getPavarde() < stud2.getPavarde();
}
//--------------------------------------------------------------------------------------------------
bool Maziau(Mokiniai &stud) {
	return stud.getAverage() < 6;
}
//--------------------------------------------------------------------------------------------------
void Isvestis(std::vector<Mokiniai> &Mok)
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
	std::cout << std::setw(a + 3) << std::left << "Pavarde";
	std::cout << std::setw(b + 1) << std::left << "Vardas";
	std::cout << std::fixed;
	std::cout << std::setw(3) << std::left << "Vid   Med" << std::endl;
	for (unsigned int i = 0; i < a + b + 12; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
	unsigned int i = 0;
	for (auto& v : Mok) //isveda visa struktura
	{
		i++;
		std::cout << i << " ";
		std::cout << std::setw(a + 1) << std::left << v.pavarde;
		std::cout << std::setw(b + 1) << std::left << v.vardas;
		std::cout << std::fixed;
		std::cout << std::setw(3) << std::left << std::setprecision(2) << v.galBalVid_ << "  " << v.galBalMed_ << std::endl;
	}
	for (unsigned int i = 0; i < a + b + 12; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
}
//--------------------------------------------------------------------------------------------------
void Nuskaitymas(std::vector<Mokiniai> &Mok)
{
	std::ifstream inf("Failas.txt"); //nuskaitymo pradzia
	Mokiniai in;

	for (unsigned int i = 0; !inf.eof(); i)
	{
		std::string input; //ivesties string'as
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
			in.Pazymiai.push_back(std::stoi(input)); //iraso i vektoriu pazymius
		}
		else {
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
void Failas(bool b)
{
	std::vector<Mokiniai> Mok;
	std::vector<Mokiniai> Win{};
	std::vector<Mokiniai> Los{};
	try {
		Nuskaitymas(Mok);
		sortContainer(Mok);
		//vidurki, mediana ir rusiavimas
		for (auto& v : Mok)
		{
			switch (v.Pazymiai.size())
			{
			case 1: throw "Truksta nd ivertinimu!";
			case 0: throw "Truksta nd ivertinimu ir egzamino ivertinimu!";
			}
			v.galBalVid_ = Vidurkis(v.Pazymiai);
			v.galBalMed_ = Mediana(v.Pazymiai);
		}

		unsigned n = std::count_if(Mok.begin(), Mok.end(), Maziau);
		Los.resize(n); Win.resize(Mok.size() - n);

		std::partition_copy(Mok.begin(), Mok.end(), Los.begin(), Win.begin(), Maziau);


		if (b)
		{
			Isvestis(Mok); //visu duomenu isvestis per konsole
			std::cout << std::endl;
			std::cout << "WINNERS" << std::endl;
			Isvestis(Win);
			std::cout << std::endl;
			std::cout << "LOSERS" << std::endl;
			Isvestis(Los);
		}
	}
	catch (const char* msg) {
		std::cout << msg << std::endl;
	}

}
//--------------------------------------------------------------------------------------------------
void Failas1(bool b)
{

	std::vector<Mokiniai> Mok;
	try {
		Nuskaitymas(Mok);

		//vidurki, mediana ir rusiavimas
		for (auto& v : Mok)
		{
			switch (v.Pazymiai.size())
			{
			case 1: throw "Truksta nd ivertinimu!";
			case 0: throw "Truksta nd ivertinimu ir egzamino ivertinimu!";
			}
			v.galBalVid_ = Vidurkis(v.Pazymiai);
			v.galBalMed_ = Mediana(v.Pazymiai);

		}

		auto p = std::partition(Mok.begin(), Mok.end(), Maziau);
		std::vector<Mokiniai> Win(p, Mok.end());
		Mok.erase(p, Mok.end());

		sortContainer(Mok);
		sortContainer(Win);
		if (b)
		{
			std::cout << "LOSERS" << std::endl;
			Isvestis(Mok);
			std::cout << std::endl;
			std::cout << "WINNERS" << std::endl;
			Isvestis(Win);
			std::cout << std::endl;
		}
	}
	catch (const char* msg) {
		std::cout << msg << std::endl;
	}

}
//--------------------------------------------------------------------------------------------------
void sortContainer(std::vector<Mokiniai> &stud) {
	std::sort(stud.begin(), stud.end(), customCompare);
}
//--------------------------------------------------------------------------------------------------
void Random()
{
	Mokiniai Mok;
	
	std::cout << "Mokinio vardas: ";
	std::getline(std::cin, Mok.vardas);
	std::cout << "Mokinio pavarde: ";
	std::getline(std::cin, Mok.pavarde);
	
	int a = 0;
	int n = 0;
	bool t = true;
	std::cout << "Pasirinkote: random generavimas." << std::endl;

	   std::random_device rd;
	   std::mt19937 mt(rd());
	   std::uniform_int_distribution<int> dist(1, 10);
	
	do{ 
		std::cout << "Iveskite, kiek pazymiu norite sugeneruoti:" << std::endl;
		t = false;
		try{
			n = ivestiSk(1, 1000000);
			std::cout << a << std::endl;
		}catch (const char* msg) {
	   	std::cout << msg << std::endl;
	   	t = true;
	  		}
	}while (t);
	std::cout << "Sugeneruoti pazymiai: " << std::endl;
	for (int i = 0; i < n; i++)
	{
		Mok.Pazymiai.push_back(dist(mt)); //i vektoriu irasomi random pazymiai
		std::cout << Mok.Pazymiai[i] << " ";
	}
	std::cout << std::endl;
	
	do{ //ivedimas is konsoles
		std::cout << "Mokinio egzamino ivertinimas: ";
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
	
	std::vector<Mokiniai> MokiniaiV{Mok};
	Isvestis(MokiniaiV);
	std::cout << "Funkcijos pabaiga" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
	
	
}
//--------------------------------------------------------------------------------------------------
void Konsole()
{
	Mokiniai Mok;

	std::cout << "Mokinio vardas: ";
	std::getline(std::cin, Mok.vardas);
	std::cout << "Mokinio pavarde: ";
	std::getline(std::cin, Mok.pavarde);

	std::cout << "Pasirinkote: ivestis per konsole. Noredami pabaigti pazymiu ivedima, iveskite 0" << std::endl;
	int a = 0;
	bool t = true;

	do { //ivedimas is konsoles
		std::cout << Mok.Pazymiai.size() + 1 << "-asis pazymys ";
		try {
			a = ivestiSk(0, 10);
			if (a == 0)
			{
				if (Mok.Pazymiai.size() == 0)
				{
					throw "Neivedete nei vieno pazymio";
				}
				else t = false;
				std::cout << "Pazymiu ivedimas baigtas" << std::endl;
			}
			else Mok.Pazymiai.push_back(a);
		}
		catch (const char* msg) {
			std::cout << msg << std::endl;
		}
	} while (t);

	do { //ivedimas is konsoles
		std::cout << "Mokinio egzamino ivertinimas: ";
		t = false;
		try {
			a = ivestiSk(1, 10);
		}
		catch (const char* msg) {
			std::cout << msg << std::endl;
			t = true;
		}
	} while (t);
	Mok.Pazymiai.push_back(a);

	Mok.galBalVid_ = Vidurkis(Mok.Pazymiai);
	std::sort(Mok.Pazymiai.begin(), Mok.Pazymiai.end() - 1); //rikiavimas
	Mok.galBalMed_ = Mediana(Mok.Pazymiai); //skaiciuojama mediana perduodama vidurkio kintamajam del isvesties patogumo
	std::vector<Mokiniai> MokiniaiV{ Mok };
	Isvestis(MokiniaiV);
	std::cout << "Funkcijos pabaiga" << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
}
