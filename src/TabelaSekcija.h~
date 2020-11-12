#ifndef TABELASEKCIJA_H
#define TABELASEKCIJA_H
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "RelokacioniZapis.h"
using namespace std;
class Sekcija {
	string ime;
	int rbr;
	int pocetak;
	int kraj;
	int velicina;
	string pravaPristupa;
public:

	vector<RelokacioniZapis> relzap;

	void ispisiRelokacioniZapis();

	string ispisiSekciju() {
		return to_string(rbr) + "         \t\t" + ime + "     \t\t" + to_string(kraj) + "         \t\t" + pravaPristupa;
	}

	static int srbr;
	int getRbr() {
		return rbr;
	}
    Sekcija(string i, string pp):ime(i), pravaPristupa(pp){
        rbr = ++srbr;
		pocetak = 0;
		kraj = 0;
    };
    void setKraj(int k){
        if(k > 0){
            kraj = k;
            velicina = kraj - pocetak;
        }
    }
    string getIme(){
        return this->ime;
    }
};


class TabelaSekcija{
public:
	
	map<string, Sekcija*> mapa;
    TabelaSekcija();
    ~TabelaSekcija();
	void ispisiTabeluSekcija(ofstream& os);
    void putSekcija(Sekcija *s, string key);
    Sekcija* getSekcija(string key);
};

#endif // TABELASEKCIJA_H_INCLUDED

