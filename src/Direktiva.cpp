#include <string>
#include <iostream>
#include "Direktiva.h"
#include "TabelaSimbola.h"
#include "RelokacioniZapis.h"
#include "TabelaSekcija.h"
using namespace std;

void Direktiva::razresiSimbole(TabelaSimbola* ts, TabelaSekcija* tsek) {
	for (vector<string>::iterator it = simboli.begin(); it != simboli.end(); ++it) {
		string sim = *it;
		Simbol* s = ts->getSimbol(sim);
		int vr;
		if (s->isGlobal()) {
			vr = 0;
		}
		else {
			vr = s->getVrednost();
		}
		int i = 0;
		for (vector<int>::iterator it_in = parametri.begin(); it_in != parametri.end(); it_in++) {
			if (*it_in == -9999) {
				i++;
				*it_in = vr;
				break;
			}
		}
		if (s->isGlobal()) {
			Sekcija* sekcija_naredbe = tsek->getSekcija(this->sekcija);
			if (sekcija_naredbe == 0) {
				cout << "Greska Naredbe.cpp" << endl;
				exit(1);
			}
			RelokacioniZapis* rz = new RelokacioniZapis(sekcija_naredbe->getIme(), "R_386_32", s->getRbr(), this->instr_loc_cnt+i);
			sekcija_naredbe->relzap.push_back(*rz);
		}
		else {
			vr = 0;
			Sekcija* sekcija_naredbe = tsek->getSekcija(this->sekcija);
			if (sekcija_naredbe == 0) {
				cout << "Greska Naredbe.cpp" << endl;
				exit(1);
			}
			if (s->getSekcija() != this->sekcija) {
				RelokacioniZapis* rz = new RelokacioniZapis(sekcija_naredbe->getIme(), "R_386_32", sekcija_naredbe->getRbr(), this->instr_loc_cnt + i);
				sekcija_naredbe->relzap.push_back(*rz);
			}
		}
	}
}


