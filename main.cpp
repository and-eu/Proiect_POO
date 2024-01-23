#include <iostream>
#include "Librarii/Produs.h"
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream f("../produs.in");
    Produs prod;
    string n;
    f >> n;
    cout << n << endl;
    prod.afisare();

    ofstream g("../produs.out");
    return 0;
}
