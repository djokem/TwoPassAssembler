#ifndef DIREKTIVA_H
#define DIREKTIVA_H
#include <string>
#include <vector>
#include "Instrukcija.h"
#include "TabelaSimbola.h"
#include "TabelaSekcija.h"
using namespace std;

class Direktiva :public Instrukcija{
public:
	int getRbr() {
		return rbr;
	}
	string mnemonik;
	vector<int> parametri;
	vector<string> simboli;

	Direktiva(string mn, string sek) :mnemonik(mn) {
		rbr = ++Instrukcija::prbr;
		this->setSekcija(sek);
	};
	void dodaj(int br) {
		parametri.push_back(br);
	}

	void razresiSimbole(TabelaSimbola* ts, TabelaSekcija* tsek);

	string ispisiNaredbu() {
		return this->mnemonik;
	}
	int getVelicina() {
		if(mnemonik == ".word")
			return 2 * (parametri.size() + simboli.size());
		else
			return parametri.size();
	}
private:
	int rbr;
};


#endif

