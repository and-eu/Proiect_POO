#include "Procesor.h"
#include <iostream>
#include <fstream>

using namespace std;

int Procesor::index_cod = 1;
int Procesor::nrProduseDistincte = 0;


//constructor cu toate argumentele
Procesor::Procesor(float pret, const string &model, int an_fabricatie, int garantie, const string &producator,
                   const string &taraProvenienta, int stoc, string &soclu, int frecventa, int numar_nuclee,
                   int memorie_cache) : Produs(pret, model, an_fabricatie, garantie, producator, taraProvenienta,
                                                stoc) {
    string numar= to_string(index_cod);
    string zero(4-numar.length(),'0');
    this->cod_produs = "PS" + zero + numar;
    this->soclu = soclu;
    this->frecventa = frecventa;
    this->numar_nuclee = numar_nuclee;
    this->memorie_cache = memorie_cache;
    nrProduseDistincte++;
    index_cod++;
}

//destructor
Procesor::~Procesor() {
    nrProduseDistincte--;
}

const string &Procesor::getCodProdus() const {
    return cod_produs;
}

const string &Procesor::getSoclu() const {
    return soclu;
}

void Procesor::setSoclu(const string &soclu) {
    Procesor::soclu = soclu;
}

int Procesor::getFrecventa() const {
    return frecventa;
}

void Procesor::setFrecventa(int frecventa) {
    Procesor::frecventa = frecventa;
}

int Procesor::getNumarNuclee() const {
    return numar_nuclee;
}

void Procesor::setNumarNuclee(int numarNuclee) {
    numar_nuclee = numarNuclee;
}

int Procesor::getMemorieCache() const {
    return memorie_cache;
}

void Procesor::setMemorieCache(int memorieCache) {
    memorie_cache = memorieCache;
}

//afisare
void Procesor::afisare() const {
    cout << "Cod produs: " << cod_produs << endl;
    Produs::afisare();
    cout << "Soclu: " << soclu << endl;
    cout << "Frecventa: " << frecventa << endl;
    cout << "Numar nuclee: " << numar_nuclee << endl;
    cout << "Memorie cache: " << memorie_cache << endl;
}

void Procesor::outputFisier(ofstream &stream, char sep, bool useEndl) const {
    stream << "Procesor" << sep ;
    Produs::outputFisier(stream, sep, false);
    stream << soclu << sep << frecventa << sep << numar_nuclee << sep << memorie_cache << endl;
}

void Procesor::afisarePretDupaProducator(string &producatorCautat) {
    if (producatorCautat == this->getProducator()) {
        cout << "Cod produs: " << this->cod_produs << endl;
        cout << "Model: " << this->getModel() << endl;
        cout << "Pret: " << this->getPret() << "lei" << endl;
        cout << "Stoc: " << this->getStoc() << endl<<endl;
    }
}

float Procesor::calculPretRedus() {
    if ((this->getStoc()>20) && (this->getPret()>4000))
        return this->getPret() - this->getPret() * 0.1;
    else if ((this->getStoc()>0) && (this->getPret()>4000))
        return this->getPret() - this->getPret() * 0.05;
    else
        return this->getPret();
}