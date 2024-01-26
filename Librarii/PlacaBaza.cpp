#include "PlacaBaza.h"
#include <iostream>
#include <fstream>

using namespace std;

int PlacaBaza::index_cod = 1;
int PlacaBaza::nrProduseDistincte = 0;

//constructor cu toate argumentele
PlacaBaza::PlacaBaza(float pret, const string &model, int an_fabricatie, int garantie, const string &producator,
                     const string &taraProvenienta, int stoc, string &soclu, string &chipset, string &format,
                     string &tip_memorie) : Produs(pret, model, an_fabricatie, garantie, producator, taraProvenienta,
                                                   stoc) {
    string numar= to_string(index_cod);
    string zero(4-numar.length(),'0');
    this->cod_produs = "PB" + zero + numar;
    this->soclu = soclu;
    this->chipset = chipset;
    this->format = format;
    this->tip_memorie = tip_memorie;
    nrProduseDistincte++;
    index_cod++;
}

//desctructor
PlacaBaza::~PlacaBaza() {
    nrProduseDistincte--;
}

const string &PlacaBaza::getCodProdus() const {
    return cod_produs;
}

const string &PlacaBaza::getSoclu() const {
    return soclu;
}

void PlacaBaza::setSoclu(const string &soclu) {
    PlacaBaza::soclu = soclu;
}

const string &PlacaBaza::getChipset() const {
    return chipset;
}

void PlacaBaza::setChipset(const string &chipset) {
    PlacaBaza::chipset = chipset;
}

const string &PlacaBaza::getFormat() const {
    return format;
}

void PlacaBaza::setFormat(const string &format) {
    PlacaBaza::format = format;
}

const string &PlacaBaza::getTipMemorie() const {
    return tip_memorie;
}

void PlacaBaza::setTipMemorie(const string &tipMemorie) {
    tip_memorie = tipMemorie;
}

//afisarea placii de baza
void PlacaBaza::afisare() const {
    cout << "Cod produs: " << cod_produs << endl;
    Produs::afisare();
    cout << "Soclu: " << soclu << endl;
    cout << "Chipset: " << chipset << endl;
    cout << "Format: " << format << endl;
    cout << "Tip memorie: " << tip_memorie << endl;
}

//afisarea placii de baza in fisier
void PlacaBaza::outputFisier(ofstream &stream, char sep) const {
    stream << cod_produs << sep;
    Produs::outputFisier(stream, sep, false);
           stream << soclu << sep << chipset << sep << format << sep << tip_memorie << endl;
}

//afisarea pretului placii de baza dupa producator
void PlacaBaza::afisarePretDupaProducator(string &producatorCautat) {
    if (producatorCautat == this->getProducator()) {
        cout << "Cod produs: " << this->cod_produs << endl;
        cout << "Model: " << this->getModel() << endl;
        cout << "Pret: " << this->getPret() << "lei" << endl;
        cout << "Stoc: " << this->getStoc() << endl<<endl;
    }
}

//calcularea pretului redus al placii de baza
float PlacaBaza::calculPretRedus() {
    if ((this->getStoc()>20) && (this->getPret()>2500))
        return this->getPret() - this->getPret() * 0.1;
    else if ((this->getStoc()>0) && (this->getPret()>2500))
        return this->getPret() - this->getPret() * 0.05;
            else
        return this->getPret();
}