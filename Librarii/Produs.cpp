#include "Produs.h"
#include <iostream>
#include <fstream>

using namespace std;

Produs::Produs(){ //constructor fara parametrii
    this->pret=0;
    this->model="####";
    this->an_fabricatie=1900;
    this->garantie=0;
    this->producator="####";
    this->tara_provenienta="####";
    this->stoc=0;
}

Produs::Produs(float pret, const string &marca, int an_fabricatie, int garantie, const string &producator,
               const string &taraProvenienta, int stoc) : pret(pret), model(model),
                                                          an_fabricatie(an_fabricatie), garantie(garantie),
                                                          producator(producator), tara_provenienta(taraProvenienta),
                                                          stoc(stoc) {}

Produs::Produs(const Produs &obiect) {
    this->pret=obiect.pret;
    this->model=obiect.model;
    this->an_fabricatie=obiect.an_fabricatie;
    this->garantie=obiect.garantie;
    this->producator=obiect.producator;
    this->tara_provenienta=obiect.tara_provenienta;
    this->stoc=obiect.stoc;
}

Produs::~Produs() = default;


float Produs::getPret() const {
    return pret;
}

void Produs::setPret(float pret) {
    if (pret>0) {this->pret = pret;}
    else {cout<<"pretul trebuie sa fie > 0"<<endl;}
}

const string &Produs::getModel() const {
    return model;
}

void Produs::setModel(const string &nouModel) {
    if (nouModel.length()>3) this->model = nouModel;
    else cout<<"Modelul trebuie sa aiba mai mult de 3 caractere."<<endl;
}

int Produs::getAnFabricatie() const {
    return an_fabricatie;
}

void Produs::setAnFabricatie(int anFabricatie) {
    if (anFabricatie>1900 and anFabricatie<2025) this->an_fabricatie = anFabricatie;
    else cout<<"Anul de fabricatie nu este corect."<<endl;
}

int Produs::getGarantie() const {
    return garantie;
}

void Produs::setGarantie(int garantie) {
    if (garantie>12 and garantie<100) this->garantie = garantie;
    else cout<<"Garantia introdusa nu pare sa fie corecta."<<endl;
}

const string &Produs::getProducator() const {
    return producator;
}

void Produs::setProducator(const string &producator) {
    if (producator.length()>3) this->producator = producator;
    else cout<<"Producatorul trebuie sa aiba mai mult de 3 caractere."<<endl;
}

const string &Produs::getTaraProvenienta() const {
    return tara_provenienta;
}

void Produs::setTaraProvenienta(const string &taraProvenienta) {
    if (taraProvenienta.length()>3) this->tara_provenienta = taraProvenienta;
    else cout<<"Tara de proveninta trebuie sa aiba mai mult de 3 caractere."<<endl;
}

int Produs::getStoc() const {
    return stoc;
}

void Produs::setStoc(int stocNou) {
    if (stocNou>=0) this->stoc = stocNou;
    else cout<<"Stocul nu poate fi negativ"<<endl;
}

void Produs::afisare() const {
    cout << "Model: " << this->model << endl;
    cout << "Pret: " << this->pret << " lei" << endl;
    cout << "An fabricatie: " << this->an_fabricatie << endl;
    cout << "Garantie: " << this->garantie << " luni" << endl;
    cout << "Producator: " << this->producator << endl;
    cout << "Tara de provenienta: " << this->tara_provenienta << endl;
    cout << "Stoc: " << this->stoc << endl;
}

void Produs::outputFisier(ofstream &stream, char sep, bool useEndl) const {
    stream  << this->pret << sep
            << this->model << sep
            << this->an_fabricatie << sep
            << this->garantie << sep
            << this->producator << sep
            << this->tara_provenienta << sep
            << this->stoc;
    if (useEndl)
        stream << endl;
    else
        stream << sep;
}

bool Produs::vanzareProdus(int cantitate) {
    if (cantitate > 0){
        if (cantitate > this->stoc){
            this->stoc = this->stoc - cantitate;
            cout << "Vanzare reusita" << endl;
            return true;
        } else {
            cout << "Stoc insuficient" << endl;
            return false;
        }
    } else {
        cout<<"Nu se poate vinde cantitate mai mica sau egal cu 0"<<endl;
        return false;
    }
}

void Produs::incarcaStoc(int cantitate) {
    if (cantitate > 0){
        this->stoc = this->stoc + cantitate;
    } else {
        cout<<"Nu se poate incarca stocul cu o cantitate mai mica sau egal cu 0"<<endl;
    }
}


