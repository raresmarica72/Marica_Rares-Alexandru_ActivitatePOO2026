#include <iostream>

using namespace std;

class Cutie {
private:
    float lungime;
    float latime;
    float inaltime;

public:
 
    void setLungime(float lungime) {
        this->lungime = lungime;
    }

    void setLatime(float latime) {
        this->latime = latime;
    }

    void setInaltime(float inaltime) {
        this->inaltime = inaltime;
    }

    float getLungime() {
        return this->lungime;
    }

    float getLatime() {
        return this->latime;
    }

    float getInaltime() {
        return this->inaltime;
    }
};

int main() {
    Cutie cutie;
    float lungime, latime, inaltime;

    cin >> lungime >> latime >> inaltime;


    cutie.setLungime(lungime);
    cutie.setLatime(latime);
    cutie.setInaltime(inaltime);

    cout << cutie.getLungime() << endl;
    cout << cutie.getLatime() << endl;
    cout << cutie.getInaltime() << endl;

    return 0;
}