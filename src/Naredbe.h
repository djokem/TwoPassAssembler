#ifndef NAREDBE_H
#define NAREDBE_H
#include <string>
#include "Asembler.h"
#include "Instrukcija.h"
using namespace std;

class Naredba:public Instrukcija{
	
public:
	bool imaPcRelOp1;
	bool imaPcRelOp2;
	bool PcRelLocalOp1;
	bool PcRelGlobalOp1;
	bool PcRelLocalOp2;
	bool PcRelGlobalOp2;
	bool imaPcUNaredbiOp1;
	bool imaPcUNaredbiOp2;

    Naredba(string m, char c, string o1, string o2, int adr1 = -1, int adr2 = -1, string sek = ""):mnemonik(m),oc(c),op1(o1), op2(o2), adr_op1(adr1), adr_op2(adr2){
		rbr = ++Instrukcija::prbr;
		velicina1 = velicina2 = op1Im1 = op1Im2 = op2Im1 = op2Im2 = -1;
		imaPcRelOp1 = imaPcRelOp2 = PcRelGlobalOp1 = PcRelLocalOp1 = PcRelGlobalOp2 = PcRelLocalOp2 = imaPcUNaredbiOp1 = imaPcUNaredbiOp2 = false;
		this->setSekcija(sek);
		updateOp1Descr();
		updateOp2Descr();
	}
    

	int getRbr() {
		return this->rbr;
	}

    string getMnemonik(){
        return mnemonik;
    }
    
    char getOC(){
        return oc;
    }
    
    int getAdrOp1(){
        return adr_op1;
    }
    
    int getAdrOp2(){
        return adr_op2;
    }
    
    int getVelicina1(){
        return velicina1;
    }
	int getVelicina2() {
		return velicina2;
	}
	string getOp1() {
		return op1;
	}
	string getOp2() {
		return op2;
	}
	string* getOp1p() {
		return &op1;
	}
	string* getOp2p() {
		return &op2;
	}
	void setOp1(string o) {
		op1 = o;
	}
	void setOp2(string o) {
		op2 = o;
	}
    void setAdrOp1(int v){
        adr_op1 = v;
    }

	int ugradnjaOp1() {
		return 2-getUkupnaVelicina();
	}
	int ugradnjaOp2() {
		return 1 + getVelicina1() - getUkupnaVelicina();
	}
    void setAdrOp2(int v){
        adr_op2 = v;
    }
    void setVelicina1(int v){
        velicina1 = v;
    }
	void setVelicina2(int v) {
		velicina2 = v;
	}
	string ispisiNaredbu() {
		return to_string(rbr) + "  " + mnemonik + "  " + op1 + "  (" + to_string(int(Op1Descr)) + "  " + to_string((int)op1Im1) + "  " + to_string((int)op1Im2) + "  V1: " + to_string(velicina1) + ")  "+ op2 + "  (" + to_string(int(Op2Descr)) + "  " + to_string((int)op2Im1) + "  " + to_string((int)op2Im2) +"   V2:" + to_string(velicina2) + ")  "  ;
	}
	int getUkupnaVelicina() {
		int v1 = (velicina1 == -1) ? 0 : velicina1;
		int v2 = (velicina2 == -1) ? 0 : velicina2;
		int a = 1 + v1 + v2;
		return a;
	}
	char* getOp1Im1() {
		return &op1Im1;
	}
	char* getOp1Im2() {
		return &op1Im2;
	}

	char* getOp2Im1() {
		return &op2Im1;
	}
	char* getOp2Im2() {
		return &op2Im2;
	}

	char getOp1Descr() {
		return Op1Descr;
	}
	
	char getOp2Descr() {
		return Op2Descr;
	}

	void updateOp1Descr();
	void updateOp2Descr();
	void updateOp1Im(int adr_op, int velicina, string* op, TabelaSimbola* ts, TabelaSekcija* tsek, char* opIm1, char* opIm2, bool op1_chosen);

private:
	int rbr;
    string mnemonik;
	string op1;
	string op2;
	int adr_op1;
	int adr_op2;
	int velicina1;
	int velicina2;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
    char oc;
	char Op1Descr;
	char op1Im1;
	char op1Im2;
	char Op2Descr;
	char op2Im1;
	char op2Im2;
    
};

#endif /* NAREDBA_H */


