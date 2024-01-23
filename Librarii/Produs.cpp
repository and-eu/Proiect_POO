#include "Produs.h"
#include <iostream>

using namespace std;

Produs::Produs(){ //constructor fara parametrii
    this->cod_produs=000;
    this->pret=0;
    this->marca="####";
    this->an_fabricatie=1900;
    this->garantie=0;
    this->producator="####";
    this->tara_provenienta="####";
    this->stoc=0;
}

Produs::Produs(int codProdus, float pret, const string &marca, int an_fabricatie, int garantie, const string &producator,
               const string &taraProvenienta, int stoc) : cod_produs(codProdus), pret(pret), marca(marca),
                                                          an_fabricatie(an_fabricatie), garantie(garantie),
                                                          producator(producator), tara_provenienta(taraProvenienta),
                                                          stoc(stoc) {}

Produs::~Produs() = default; //destructor

int Produs::getCodProdus() const {
    return cod_produs;
}

void Produs::setCodProdus(int codProdus) {
    this->cod_produs = codProdus;
}

float Produs::getPret() const {
    return pret;
}

void Produs::setPret(float pret) {
    this->pret = pret;
}

const string &Produs::getMarca() const {
    return marca;
}

void Produs::setMarca(const string &nouaMarca) {
    this->marca = nouaMarca;
}

int Produs::getAnFabricatie() const {
    return an_fabricatie;
}

void Produs::setAnFabricatie(int anFabricatie) {
    this->an_fabricatie = anFabricatie;
}

int Produs::getGarantie() const {
    return garantie;
}

void Produs::setGarantie(int garantie) {
    this->garantie = garantie;
}

const string &Produs::getProducator() const {
    return producator;
}

void Produs::setProducator(const string &producator) {
    this->producator = producator;
}

const string &Produs::getTaraProvenienta() const {
    return tara_provenienta;
}

void Produs::setTaraProvenienta(const string &taraProvenienta) {
    this->tara_provenienta = taraProvenienta;
}

int Produs::getStoc() const {
    return stoc;
}

void Produs::setStoc(int stoc) {
    this->stoc = stoc;
}


void Produs::afisare() const {
    cout << "Cod produs: " << this->cod_produs << endl;
    cout << "Pret: " << this->pret << " lei" << endl;
    cout << "Marca: " << this->marca << endl;
    cout << "An fabricatie: " << this->an_fabricatie << endl;
    cout << "Garantie: " << this->garantie << " luni" << endl;
    cout << "Producator: " << this->producator << endl;
    cout << "Tara de provenienta: " << this->tara_provenienta << endl;
    cout << "Stoc: " << this->stoc << endl;
    cout << "descriereProdus: " << endl;
}

ostream &operator<<(ostream &os, const Produs &produs) {
    os << "cod_produs: " << produs.cod_produs << " pret: " << produs.pret << " marca: " << produs.marca
       << " an_fabricatie: " << produs.an_fabricatie << " garantie: " << produs.garantie << " producator: "
       << produs.producator << " tara_provenienta: " << produs.tara_provenienta << " stoc: " << produs.stoc;
    return os;
}


