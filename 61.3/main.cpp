#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class zadanie {
	
public:
	
    ifstream plik1;
    ofstream plik2;

    zadanie();

};

zadanie::zadanie() {
	plik1.open("plik1.txt");
	plik2.open("plik2.txt");
}

class ciagi {

	private:
		
		zadanie x;
		vector <int> ciag;
		vector <int> y;
		vector <int> zle;

	public:

		void wczytaj();
		void zapisz();
};

void ciagi::wczytaj() {
	int dlug_ciagu, liczba, poprawne;

	while(!x.plik1.eof()) {

    	x.plik1>>dlug_ciagu;

    for(int i = 0;i<dlug_ciagu;i++) {
	    x.plik1>>liczba;
	    ciag.push_back(liczba);
    }
    
    for(int i = 0;i<4;i++) {
    	y.push_back(ciag[i+1]-ciag[i]);
    }
    
    if(y[0]==y[1]) {
    	poprawne = y[0];
    } else if(y[1]==y[2]) {
        poprawne = y[1];
    } else if(y[2]==y[3]) {
        poprawne = y[2];
    } else if(y[3]==y[0]) {
        poprawne = y[3];
    }

    for(int i = 0;i<dlug_ciagu;i++) {
        if(ciag[i] + poprawne != ciag[i+1]){
        	zle.push_back(ciag[i+1]);
            break;
		}
	}
		ciag.clear();
		y.clear();
	}
}

void ciagi::zapisz() {
	for(int i = 0;i<zle.size()-1;i++) {
    	x.plik2<<i+1<<": "<<zle[i]<<endl;
	}
}

int main(int argc, char** argv) {

	ciagi t;
	t.wczytaj();
	t.zapisz();

	return 0;
}



