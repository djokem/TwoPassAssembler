#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <sstream>
#include "TabelaSekcija.h"
#include "Asembler.h"
#include "TabelaSimbola.h"
#include "Naredbe.h"
#include "Instrukcija.h"
using namespace std;

int Instrukcija::prbr = 0;
int Sekcija::srbr = 0;
int Simbol::s_rbr = 0;
char* Asembler::prom = 0;

int main(int argc, char* argv[]) {

Asembler::prom = argv[2];    
	Asembler* as = new Asembler();

    ifstream instr;
ofstream izlaz;
   // instr.open("C:\\Users\\Malesevic\\Desktop\\Djordje\\SS\\SSProjekat\\Testovi\\ulaz.txt");
instr.open(argv[1]);
    if(instr.is_open()){
		as->prviProlaz(instr);
    }
    else{
        cout << "Greska pri citanju fajla ulaz.txt" << endl;
        exit(1);
    }
	instr.close();
	
	instr.open(argv[1]);
	//instr.open("C:\\Users\\Malesevic\\Desktop\\Djordje\\SS\\SSProjekat\\Testovi\\ulaz.txt");
	if (instr.is_open()) {
		as->drugiProlaz(instr);
	}
	else {
		cout << "Greska pri citanju fajla ulaz.txt" << endl;
		exit(1);
	}
	instr.close();
		return 0;
}

