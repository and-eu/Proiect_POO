#include "Memorie.h"
#include <iostream>
#include <fstream>

using namespace std;

int Memorie::index_cod = 1;
int Memorie::nrProduseDistincte = 0;


//constructor cu toate argumentele
Memorie::Memorie(float pret, const string &model, int an_fabricatie, int garantie, const string &producator,
                       const string &taraProvenienta, int stoc, string &tip_memorie, int capacitate,
                       int frecventa) : Produs(pret, model, an_fabricatie, garantie, producator, taraProvenienta,
                                                stoc) {
    string numar= to_string(index_cod);
    string zero(4-numar.length(),'0');
    this->cod_produs = "MR" + to_string(index_cod);
    this->tip_memorie = tip_memorie;
    this->capacitate = capacitate;
    this->frecventa = frecventa;
    nrProduseDistincte++;
    index_cod++;
}

//destructor
Memorie::~Memorie() {
    nrProduseDistincte--;
}

const string &Memorie::getCodProdus() const {
    return cod_produs;
}

const string &Memorie::getTipMemorie() const {
    return tip_memorie;
}

void Memorie::setTipMemorie(const string &tipMemorie) {
    tip_memorie = tipMemorie;
}

int Memorie::getCapacitate() const {
    return capacitate;
}

void Memorie::setCapacitate(int capacitate) {
    Memorie::capacitate = capacitate;
}

int Memorie::getFrecventa() const {
    return frecventa;
}

void Memorie::setFrecventa(int frecventa) {
    Memorie::frecventa = frecventa;
}

//afisarea memoriei RAM
void Memorie::afisare() const {
    cout << "Cod produs: " << cod_produs << endl;
    Produs::afisare();
    cout << "Tip memorie: " << tip_memorie << endl;
    cout << "Capacitate: " << capacitate << endl;
    cout << "Frecventa: " << frecventa << endl;
}

//afisarea memoriei RAM in fisier
void Memorie::outputFisier(ofstream &stream, char sep) const {
    stream << cod_produs << sep;
    Produs::outputFisier(stream, sep, false);
    stream << tip_memorie << sep << capacitate << sep << frecventa << endl;
}

//afisarea pretului memoriei RAM dupa producator
void Memorie::afisarePretDupaProducator(string &producatorCautat) {
    if (producatorCautat == this->getProducator()) {
        cout << "Cod produs: " << this->cod_produs << endl;
        cout << "Model: " << this->getModel() << endl;
        cout << "Pret: " << this->getPret() << "lei" << endl;
        cout << "Stoc: " << this->getStoc() << endl;
    }
}

//calcularea pretului redus al memoriei RAM
float Memorie::calculPretRedus() {
    if ((this->getStoc()>20) && (this->getPret()>1500))
        return this->getPret() - this->getPret() * 0.1;
    else if ((this->getStoc()>0) && (this->getPret()>1500))
        return this->getPret() - this->getPret() * 0.05;
            else
        return this->getPret();
}