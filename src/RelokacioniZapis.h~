#ifndef _RELOKACIONI_ZAPIS_H
#define _RELOKACIONI_ZAPIS_H

#include <string>
using namespace std;

class RelokacioniZapis {

	string sekcija;
	int offset;
	string tip;
	int redniBroj;

public:

	RelokacioniZapis(string sekcija, string tip, int redniBroj = -1, int offset = 0):sekcija(sekcija), tip(tip), offset(offset), redniBroj(redniBroj) {}

	string toString() {
		return to_string(offset) + "\t\t" + tip + "\t\t" + sekcija + "\t\t" + to_string(redniBroj);
	}
	string getSekcija() {
		return sekcija;
	}
	int getOffset() {
		return offset;
	}
	string getTip() {
		return tip;
	}
	int getRbr() {
		return redniBroj;
	}


	void setSekcija(string s) {
		sekcija = s;
	}
	void setOffset(int off) {
		offset = off;
	}
	void setTip(string t) {
		tip = t;
	}
	void setRedniBroj(int r) {
		redniBroj = r;
	}
};



#endif

