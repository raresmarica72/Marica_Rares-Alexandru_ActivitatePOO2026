/*Atunci când se definește un constructor cu parametri, constructorul implicit este suprimat și trebuie definit în mod
explicit sau încorporat într-un constructor cu parametri sub forma unui constructor cu argumente implicite.
Pentru clasa Pisica cu datele membre nume, vârstă, greutate să se scrie toți constructorii cu parametri posibili.
Toate valorile numerice implicite vor fi egale cu 0, iar șirurile de caractere implicite nu vor conține niciun caracter. 
În programul principal se vor instanția mai întâi un obiect cu niciun parametru, apoi cu un parametru, cu doi parametri, respectiv 3 parametri - parametrii
vor fi transmiși în ordinea menționată anterior, fiecare dintre ei fiind citit de pe un rând nou. Pentru fiecare obiect menționat se vor afișa toate datele membre,
în ordinea menționată, separate de un spațiu. După fiecare set de date membre aparținând unui obiect se va trece pe următorul rând (caracterul newline).
*/



#include <iostream>
#include <limits>
#include <string>

class Pisica {
private:
    std::string nume;
    int varsta;
    float greutate;
public:
    Pisica(std::string nume = "", int varsta = 0, float greutate = 0) : nume(nume), varsta(varsta), greutate(greutate) {}

    void display() {
        std::cout << this->nume << " " << this->varsta << " " << this->greutate << "\n";
    }
};

int main() {
    std::string temp_nume;
    int temp_varsta;
    float temp_greutate;

    Pisica p1;
    p1.display();

    std::cin >> temp_nume;
    Pisica p2(temp_nume);
    p2.display();

    std::cin >> temp_nume;
    std::cin >> temp_varsta;
    Pisica p3(temp_nume, temp_varsta);
    p3.display();

    std::cin.ignore();
    std::getline(std::cin, temp_nume);
    std::cin >> temp_varsta;
    std::cin >> temp_greutate;
    Pisica p4(temp_nume, temp_varsta, temp_greutate);
    p4.display();

    return 0;
}