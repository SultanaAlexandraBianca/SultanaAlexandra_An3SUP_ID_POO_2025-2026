#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Student {
	int idStudent;
	string numeStudent;
	bool esteBuget;
	float* noteExamene;
	int nrExamene;
	char* universitate;
	const string CNP;

public:
	//const fara parametrii

	Student() :CNP("60405059493")
	{
		this->idStudent = 0;
		this->numeStudent = "Necunoscut";
		this->esteBuget = 0;
		this->nrExamene = 0;
		this->noteExamene = NULL;
		this->universitate = new char[strlen("necunoscut") + 1];
		strcpy(this->universitate, "necunoscut");


	}

	//const cu parametrii

	Student(int idStudent, string numeStudent, bool esteBuget, float* noteExamene, int nrExamene, const char* universitate) :CNP(CNP)
	{
		this->idStudent = idStudent;
		this->numeStudent = numeStudent;
		this->esteBuget = esteBuget;
		this->nrExamene = nrExamene;
		this->noteExamene = new float[nrExamene + 1];
		this->universitate = new char[strlen(universitate) + 1];
		strcpy(this->universitate, universitate);

		//++ La asta fac si initializare pointeri mai putin CHAR

		for (int i = 0; i < this->nrExamene; i++)
		{
			this->noteExamene[i] = noteExamene[i];
		}
	}
	//constructir de copiere
	Student(Student& obj) :CNP(CNP)
	{
		this->idStudent = obj.idStudent;
		this->numeStudent = obj.numeStudent;
		this->esteBuget = obj.esteBuget;
		this->nrExamene = obj.nrExamene;
		this->noteExamene = new float[nrExamene + 1];
		this->universitate = new char[strlen(obj.universitate) + 1];
		strcpy(this->universitate,obj.universitate );

		//++ La asta fac si initializare pointeri mai putin CHAR

		for (int i = 0; i < this->nrExamene; i++)
		{
			this->noteExamene[i] = obj.noteExamene[i];
		}
		
	}

	//destructor

	~Student()
	{
		if (this->noteExamene != NULL)
		{
			delete[]this->noteExamene;
		}
	}

	//getteri

	int getidStudent()
	{
		return this->idStudent;
	}
	string getNumeStudent()
	{
		return this->numeStudent;
	}
	bool getesteBuget()
	{
		return this->esteBuget;
	}
	int getnrExamene()
	{
		return this->nrExamene;
	}
	float* getnoteExamene()
	{
		return this->noteExamene;
	}
	const char* getUniversitate()
	{
		return this->universitate;
	}
	string getCNP()
	{
		return this->CNP;
	}
	//setteri
	void setIdStudent(int idNou)
	{
		this->idStudent = idNou;
	}
	void setNumeStudent(string numeNou)
	{
		this->numeStudent = numeNou;
	}
	void setesteBuget(bool bugetNou)
	{
		this->esteBuget = bugetNou;
	}
	
	void setNoteExamene(int nrExamenenou, float* noteExamenenoi)
	{
		//obligatpriu destructor aici ca sa scap nde val veche
		if (this->noteExamene != NULL)
		{
			delete[]this->noteExamene;
		}

		this->nrExamene = nrExamenenou;
		this->noteExamene = new float[nrExamenenou + 1];
		for (int i = 0; i < nrExamene; i++)
		{
			this->noteExamene[i] = noteExamenenoi[i];
		}
	}
	void setUniversitate(char* UniversitateNoua)
	{
		//oblig copia destructorul aici
		if (this->universitate != NULL)
		{
			delete[]this->universitate;

		}
		this->universitate = new char[strlen(UniversitateNoua) + 1];
		strcpy(this->universitate, UniversitateNoua);
	}

	//operatorul <<
	friend ostream& operator <<(ostream& out, const Student obj)
	{

		out << "id " << obj.idStudent << endl;
		out << "nume " << obj.numeStudent << endl;
		out << "este bugetar " << obj.esteBuget << endl;
		for (int i = 0; i < obj.nrExamene; i++)
		{
			out << "note examene " << obj.noteExamene[i] << endl;
		}

		out << "universitate " << obj.universitate << endl;
		out << "CNP: " << obj.CNP << endl;

		return out;
	}
	//operatorul >>
	friend istream& operator >>(istream& in,  Student& obj)
	{
		//destructor neaparat

		if (obj.noteExamene != NULL)
		{
			delete[] obj.noteExamene;
		}
		if (obj.universitate != NULL)
		{
			delete[] obj.universitate;
		}

		cout << "Citiri de la tast :" << endl;

		in >> obj.idStudent;
		in >> obj.numeStudent;
		in >> obj.esteBuget;
		in >> obj.nrExamene;

		obj.noteExamene = new float[obj.nrExamene + 1];
		for (int i = 0; i < obj.nrExamene; i++)
		{
			in >> obj.noteExamene[i];
		}
		char aux[100]; //pebntru ca citim de la tasztv trebuie sa existre un char nou;

		in >> aux;
		obj.universitate = new char[strlen(aux) + 1];
		strcpy(obj.universitate, aux);

		//NEAPARAT
		return in;
	}
};
void main()
{
	float note1[] = { 10, 9, 7 };
	float note2[] = { 5, 6.5, 7.98, 9 };
	Student s1(1234, "Alex Ionut", 1, note1, 3, "ASE");
	Student s2(1235, "Maria IOna", 0, note2, 4, "UNIBUC");
	//Testare const de copiere
	Student s3(s2);

	//getteri

	cout << "id " << s1.getidStudent() << endl;
	cout << "nume " << s1.getNumeStudent() << endl;
	cout << "este bugetar " << s1.getesteBuget() << endl;
	for (int i = 0; i < s1.getnrExamene(); i++)
	{
		cout << "note examene " << s1.getnoteExamene()[i] << endl;
	}
	
	cout << "universitate " << s1.getUniversitate() << endl;
	cout << "CNP: " << s1.getCNP() << endl;

	//operator >>

	Student s4;
	cin >> s4;
	cout << s4;

}