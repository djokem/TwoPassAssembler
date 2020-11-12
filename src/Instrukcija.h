#ifndef INSTRUKCIJA_H
#define INSTRUKCIJA_H
#include <string>

using namespace std;

class Instrukcija {
protected:
	string sekcija;
public:
	int instr_loc_cnt;
	static int prbr;
	virtual string ispisiNaredbu() = 0;
	void setSekcija(string str) {
		sekcija = str;
		instr_loc_cnt = 0;
	}
	string getSekcija() {
		return sekcija;
	}
	void setInstrLocCnt(int cnt) {
		instr_loc_cnt = cnt;
	}
};


#endif
