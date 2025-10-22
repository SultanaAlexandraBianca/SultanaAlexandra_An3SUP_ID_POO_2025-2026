#include <iostream>
#include <string>

using namespace std;

class Angajat {
	//nu am private pentru ca este implicit
	int idAngajat;
	double salariu;
	string numePrenume;
	bool estePermanent;//contract pe nederminat sau nu
	float oreLucrate;

public:


	//Constructor fara parametrii
	Angajat()
	{
		this->estePermanent = 0;
		this->idAngajat = 0;
		this->numePrenume = "Necompletat";
		this->oreLucrate = 0;
		this->salariu = 0;
	}

	//Constructor cu un parametru
	Angajat(int idAngajat)
	{
		this->idAngajat = idAngajat;
		this->estePermanent = 0;
		this->numePrenume = "Necompletat";
		this->oreLucrate = 0;
		this->salariu = 0;
	}

	//Constructor cu doi parametrii
	Angajat(int idAngajat, float salariu)
	{
		this->idAngajat = idAngajat;
		this->salariu = salariu;
		this->estePermanent = 0;
		this->numePrenume = "Necompletat";
		this->oreLucrate = 0;
	}

	//Constructor cu toti parametrii de data trecuta
	Angajat(int idAngajat, double salariu, string numePrenume, bool estePermanent, float oreLucrate)
	{
		this->idAngajat = idAngajat;
		this->salariu = salariu;
		this->numePrenume = numePrenume;
		this->estePermanent = estePermanent;
		this->oreLucrate = oreLucrate;
	}

	//Getteri - rol de afisare

	int getIdAngajat()
	{
		return this->idAngajat;
	}
	double getSalariu()
	{
		return this->salariu;
	}
	string getNumePrenume()
	{
		return this->numePrenume;

	}
	bool getEstePermanent()
	{
		return this->estePermanent;
	}
	float getOreLucrate()
	{
		return this->oreLucrate;
	}

	//Setteri - rol de modificare

	void setIdAngajat(int idAngajatnou)
	{
		this->idAngajat = idAngajatnou;
	}
	void setSalariu(double salariunou)
	{
		this->salariu = salariunou;
	}
	void setNumePrenume(string numePrenumeNou)
	{
		this->numePrenume = numePrenumeNou;
	}
	void setEstePermanent(bool estePermanentNou)
	{
		this->estePermanent = estePermanentNou;
	}
	void setOreLucrate(float oreLucrateNoi)
	{
		this->oreLucrate = oreLucrateNoi;
	}
};
void main()
{
	//Testare constructori
	Angajat a1(1023, 8435.890, "Alex Gabriel", 1, 1600.70);
	Angajat a2(2045, 7509.678, "Maria Anghel", 1, 2000.50);
	Angajat a3(3213, 3670.874, "George Marian", 0, 500.08);
	Angajat a0();
	Angajat a11(1000);
	Angajat a12(3421, 3467.98);

	//Afisare prin getteri

	cout << "Constructor cu un parametru: " << endl;
	cout << "Id Angajat: " << a11.getIdAngajat() << endl;
	cout << "Constructor cu 2 parametrii: " << endl;
	cout << "Id Angajat: " << a12.getIdAngajat() << " " << "Salariu: " << a12.getSalariu() << endl;
	cout << "Constructor cu toti parametrii: " << endl;
	cout << " Id Anagajt: " << a1.getIdAngajat() << endl;
	cout << " Salariu: " << a1.getSalariu() << endl;
	cout << " Nume si Prenume: " << a1.getNumePrenume() << endl;
	cout << " Este pe nederminat/sau nu? " << a1.getEstePermanent() << endl;
	cout << " Ore lucrate: " << a1.getOreLucrate() << endl;

	//Modificare cu setteri + afisarea modificarii

	a1.setSalariu(10000);
	a1.setNumePrenume("Mara Gabriela");
	a1.setEstePermanent(0);
	a1.setOreLucrate(100);
	a1.setIdAngajat(2334);

	cout << "Salariul pentru angajatul a1 s-a marit la suma de: " << a1.getSalariu() << endl;
	cout << "Numele schimbat: " << a1.getNumePrenume() << endl;
	cout << "Tipul contractului schimbat: " << a1.getEstePermanent() << endl;
	cout << "Noul pontaj de ore lucrate: " << a1.getOreLucrate() << endl;
	cout << "Noul id de angajat: " << a1.getIdAngajat() << endl;



}