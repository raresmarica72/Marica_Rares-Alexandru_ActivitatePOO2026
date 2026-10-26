#include <iostream>
#include <string>

using namespace std;

class Cofetarie {
private:
    const int id;
    string denumire;
    int nrProduse;
    float* preturi;
public:
    static int nrCofetarii;

    // Constructor implicit
    Cofetarie() : id(++nrCofetarii) {
        this->denumire = "Cofetarie generala";
        this->nrProduse = 0;
        this->preturi = nullptr;
    }

    // Constructor cu parametri
    Cofetarie(int id, string denumire, int nrProduse, float* preturi) : id(id) {
        nrCofetarii++;
        this->denumire = denumire;
        this->nrProduse = nrProduse;
        if (nrProduse > 0 && preturi != nullptr) {
            this->preturi = new float[nrProduse];
            for (int i = 0; i < this->nrProduse; i++) {
                this->preturi[i] = preturi[i];
            }
        }
        else {
            this->preturi = nullptr;
            this->nrProduse = 0;
        }
        delete[] preturi; // Eliberam vectorul temporar trimis ca parametru
    }

    // DESTRUCTORUL - obligatoriu pentru eliberarea memoriei alocate dinamic
    ~Cofetarie() {
        if (this->preturi != nullptr) {
            delete[] this->preturi;
        }
    }

    // Metoda de afisare
    void afisare() {
        cout << endl << "Id: " << this->id;
        cout << endl << "Denumire: " << this->denumire;
        cout << endl << "Nr. produse: " << this->nrProduse;
        if (this->nrProduse > 0 && this->preturi != nullptr) {
            cout << " cu urmatoarele preturi: ";
            for (int i = 0; i < this->nrProduse - 1; i++) {
                cout << this->preturi[i] << " lei, ";
            }
            cout << this->preturi[this->nrProduse - 1] << " lei.";
        }
        cout << endl;
    }
};

int Cofetarie::nrCofetarii = 0;

int main() {
    // 1. Testare constructor implicit
    Cofetarie cofetarieGenerala;
    cofetarieGenerala.afisare();

    // 2. Testare constructor cu parametri fixi
    float* preturi = new float[3] { 18.5f, 24.0f, 15.5f };
    Cofetarie* cofetarieRomana = new Cofetarie(7, "CofetarieRomana", 3, preturi);
    cofetarieRomana->afisare();
    delete cofetarieRomana; // Eliberam memoria alocata dinamic pentru obiect

    // 3. CITIREA DE LA TASTATURĂ
    cout << "\n--- Introducere date de la tastatura ---" << endl;

    int idTastatura;
    string denumireTastatura;
    int nrProduseTastatura;

    cout << "Introdu ID-ul cofetariei (ex: 10): ";
    cin >> idTastatura;

    // Golim bufferul tastaturii înainte de a citi un string cu spații (getline)
    cin.ignore();

    cout << "Introdu denumirea cofetariei (ex: DulceMania): ";
    getline(cin, denumireTastatura);

    cout << "Introdu numarul de produse (ex: 2): ";
    cin >> nrProduseTastatura;

    float* preturiTastatura = nullptr;
    if (nrProduseTastatura > 0) {
        preturiTastatura = new float[nrProduseTastatura];
        cout << "Introdu cele " << nrProduseTastatura << " preturi:\n";
        for (int i = 0; i < nrProduseTastatura; i++) {
            cout << "Pret produs " << i + 1 << ": ";
            cin >> preturiTastatura[i];
        }
    }

    // Creare obiect cu datele preluate de la tastatură
    Cofetarie cofetarieNoua(idTastatura, denumireTastatura, nrProduseTastatura, preturiTastatura);

    cout << "\nAfisare cofetarie noua citita de la tastatura:";
    cofetarieNoua.afisare();

    cout << endl << "Numar total cofetarii create: " << Cofetarie::nrCofetarii << endl;

    return 0;


}