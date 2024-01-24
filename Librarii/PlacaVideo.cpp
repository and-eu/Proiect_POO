#include "PlacaVideo.h"
#include <iostream>
#include <fstream>

using namespace std;

int PlacaVideo::index_cod = 0;
int PlacaVideo::nrProduseDistincte = 0;

//constructor cu toate argumentele
PlacaVideo::PlacaVideo(float pret, const string &model, int an_fabricatie, int garantie,
                       const string &producator, const string &taraProvenienta, int stoc, string &chipset,
                       int capacitate_memorie, string &tip_memorie, int frecventa) :
        Produs(pret, model, an_fabricatie, garantie, producator, taraProvenienta, stoc) {
    this->cod_produs = "PV" + to_string(index_cod);
    this->chipset = chipset;
    this->capacitate_memorie = capacitate_memorie;
    this->tip_memorie = tip_memorie;
    this->frecventa = frecventa;
    nrProduseDistincte++;
    index_cod++;
}

//desctructor
PlacaVideo::~PlacaVideo(){
    nrProduseDistincte--;
}

const string &PlacaVideo::getCodProdus() const {
    return cod_produs;
}

const string &PlacaVideo::getChipset() const {
    return chipset;
}

void PlacaVideo::setChipset(const string &chipset) {
    this->chipset = chipset;
}

int PlacaVideo::getCapacitateMemorie() const {
    return capacitate_memorie;
}

void PlacaVideo::setCapacitateMemorie(int capacitateMemorie) {
    this->capacitate_memorie = capacitateMemorie;
}

const string &PlacaVideo::getTipMemorie() const {
    return tip_memorie;
}

void PlacaVideo::setTipMemorie(const string &tipMemorie) {
    this->tip_memorie = tipMemorie;
}

int PlacaVideo::getFrecventa() const {
    return frecventa;
}

void PlacaVideo::setFrecventa(int frecventa) {
    this->frecventa = frecventa;
}

void PlacaVideo::afisare() const {
    cout << "Cod produs: " << cod_produs << endl;
    Produs::afisare();
    cout << "Chipset: " << chipset << endl;
    cout << "Capacitate memorie: " << capacitate_memorie << endl;
    cout << "Tip memorie: " << tip_memorie << endl;
    cout << "Frecventa: " << frecventa << endl;
}

void PlacaVideo::outputFisier(ofstream &stream, string sep) const {
    stream << cod_produs << sep;
    Produs::outputFisier(stream, sep, false);
    stream << chipset << sep << capacitate_memorie << sep << tip_memorie << sep << frecventa << endl;
}

void PlacaVideo::afisarePretDupaProducator(string &producatorCautat) {
    if (producatorCautat == this->getProducator()) {
        cout << "Cod produs: " << this->cod_produs << endl;
        cout << "Model: " << this->getModel() << endl;
        cout << "Pret: " << this->getPret() << " lei" << endl;
        cout << "Stoc: " << this->getStoc() << endl;
    }
}

double PlacaVideo::calculPretRedus() {
    if ((this->getStoc() > 20) && (this->getPret() > 4000))
        return this->pret - this->pret * 0.1;
    else if ((this->getStoc() > 0) && (this->getPret() > 4000))
        return this->pret - this->pret * 0.05;
    else
    return this->pret;
}

