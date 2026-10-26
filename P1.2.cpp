#include <iostream>
#include <iomanip> // Pentru formatarea cu zecimale (setprecision)

using namespace std;

class Cutie {
public:
    // Cele 3 date membre publice de tip real
    double lungime;
    double latime;
    double inaltime;

    double calculeazaVolum() {
        return lungime * latime * inaltime;
    }

    double volumRamas(Cutie c2) {
    
        if (c2.lungime <= lungime && c2.latime <= latime && c2.inaltime <= inaltime) {
            return calculeazaVolum() - c2.calculeazaVolum();
        }
        else {
          
            return calculeazaVolum();
        }
    }
};

int main() {
    Cutie c1;

    
    cin >> c1.lungime >> c1.latime >> c1.inaltime;

    int comanda;
    cin >> comanda;

 
    cout << fixed << setprecision(3);

    if (comanda == 1) {
        
        cout << c1.calculeazaVolum() << "\n";
    }
    else if (comanda == 2) {
        
        Cutie c2;
        cin >> c2.lungime >> c2.latime >> c2.inaltime;

        cout << c1.volumRamas(c2) << "\n";
    }

    return 0;
}