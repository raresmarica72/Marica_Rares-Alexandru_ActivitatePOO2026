/*
Se va crea o clasă Segment, care este definită în spațiu de o pereche de puncte în coordonate carteziene în plan tridimensional.
Punctele sunt create ca instanțe ale clasei Punct. Să se definească un constructor cu 6 argumente pentru clasa Segment și o funcție
care să calculeze lungimea segmentului. În programul principal se va instanția un obiect de tipul Segment, prin citirea de la tastatură 
a celor 6 atribute, în ordinea x1, y1, z1, x2, y2, z2 și se va afișa pe ecran lungimea segmentului, cu 2 zecimale.


terminal (exemplu):

1 2 3 4 5 6

*/


#include <iostream>
#include <cmath>
#include <iomanip>

class Punct {
private:
    double x, y, z;

public:
    // Constructor cu parametri impliciti
    Punct(double x = 0, double y = 0, double z = 0) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    // Metode de acces (getteri)
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
};

class Segment {
private:
    Punct p1;
    Punct p2;

public:
    // Constructor cu 6 argumente: x1, y1, z1, x2, y2, z2
    Segment(double x1, double y1, double z1, double x2, double y2, double z2)
        : p1(x1, y1, z1), p2(x2, y2, z2) {}

    // Funcție membră pentru calculul lungimii segmentului în 3D
    double calculLungime() const {
        double dx = p2.getX() - p1.getX();
        double dy = p2.getY() - p1.getY();
        double dz = p2.getZ() - p1.getZ();
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }
};

int main() {
    double x1, y1, z1, x2, y2, z2;

    // Citirea celor 6 coordonate de la tastatura
    std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

    // Instantierea obiectului Segment
    Segment s(x1, y1, z1, x2, y2, z2);

    // Setarea formatului la 2 zecimale si afisarea rezultatului
    std::cout << std::fixed << std::setprecision(2);
    std::cout << s.calculLungime() << "\n";

    return 0;
}