#include "Stocare.h"
#include <iostream>
#include <fstream>

using namespace std;

int Stocare::index_cod = 1;
int Stocare::nrProduseDistincte = 0;

//constructor cu toate argumentele
Stocare::Stocare(float pret, const string &model, int an_fabricatie, int garantie, const string &producator,
                 const string &taraProvenienta, int stoc, string &tip, string &format, int capacitate,
                 int viteza) : Produs(pret, model, an_fabricatie, garantie, producator, taraProvenienta, stoc) {
    string numar= to_string(index_cod);
    string zero(4-numar.length(),'0');
    this->cod_produs = "ST" + zero + numar;
    this->tip = tip;
    this->format = format;
    this->capacitate = capacitate;
    this->viteza = viteza;
    nrProduseDistincte++;
    index_cod++;
}

//destructor
Stocare::~Stocare() {
    nrProduseDistincte--;
}

const string &Stocare::getCodProdus() const {
    return cod_produs;
}

const string &Stocare::getTip() const {
    return tip;
}

void Stocare::setTip(const string &tip) {
    Stocare::tip = tip;
}

const string &Stocare::getFormat() const {
    return format;
}

void Stocare::setFormat(const string &format) {
    Stocare::format = format;
}

int Stocare::getCapacitate() const {
    return capacitate;
}

void Stocare::setCapacitate(int capacitate) {
    Stocare::capacitate = capacitate;
}

int Stocare::getViteza() const {
    return viteza;
}

void Stocare::setViteza(int viteza) {
    Stocare::viteza = viteza;
}

//afisarea stocarii
void Stocare::afisare() const {
    cout << "Cod produs: " << cod_produs << endl;
    Produs::afisare();
    cout << "Tip: " << tip << endl;
    cout << "Format: " << format << endl;
    cout << "Capacitate: " << capacitate << endl;
    cout << "Viteza: " << viteza << endl;
}

//afisarea stocarii in fisier
void Stocare::outputFisier(ofstream &stream, char sep) const {
    stream << cod_produs << sep;
    Produs::outputFisier(stream, sep, false);
    stream << tip << sep << format << sep << capacitate << sep << viteza << endl;
}

//afisarea pretului dupa producator
void Stocare::afisarePretDupaProducator(string &producatorCautat) {
    if (producatorCautat == getProducator()) {
        cout << "Cod produs: " << this->cod_produs << endl;
        cout << "Model: " << this->getModel() << endl;
        cout << "Pret: " << this->getPret() << "lei" << endl;
        cout << "Stoc: " << this->getStoc() << endl;
    }
}

//calcularea pretului redus
double Stocare::calculPretRedus() {
    if ((this->getStoc()>20) && (this->getPret()>5000))
        return this->getPret() - this->getPret() * 0.1;
    else if ((this->getStoc()>0) && (this->getPret()>5000))
        return this->getPret() - this->getPret() * 0.05;
            else
        return this->getPret();
}