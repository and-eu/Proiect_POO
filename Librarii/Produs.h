#pragma once
#include <string>
#include <ostream>

using namespace std;

class Produs{  // Clasa de baza abstracta
protected:
    float pret; //pretul produsului
    string model; //marca produsului
    int an_fabricatie; //anul fabricatiei
    int garantie; //numar luni
    string producator; //numele producatorului
    string tara_provenienta; //tara de provenienta
    int stoc; //numarul de produse din stoc

public:
    Produs(); //constructor fara parametrii

    Produs(float pret, const string &model, int an_fabricatie, int garantie, const string &producator,
           const string &taraProvenienta, int stoc); //constructor cu parametrii

    Produs(const Produs& obiect);

    virtual ~Produs();

    [[nodiscard]] float getPret() const;

    void setPret(float pret);

    [[nodiscard]] const string &getModel() const;

    void setModel(const string &model);

    int getAnFabricatie() const;

    void setAnFabricatie(int anFabricatie);

    [[nodiscard]] int getGarantie() const;

    void setGarantie(int garantie);

    [[nodiscard]] const string &getProducator() const;

    void setProducator(const string &producator);

    [[nodiscard]] const string &getTaraProvenienta() const;

    void setTaraProvenienta(const string &taraProvenienta);

    [[nodiscard]] int getStoc() const;

    void setStoc(int stoc);

    virtual void afisare() const;

    virtual void outputFisier(ofstream &stream, char sep = ',', bool useEndl = true) const;

    bool vanzareProdus(int cantitate);

    void incarcaStoc(int cantitate);

    virtual void afisarePretDupaProducator(string& producatorCautat) = 0;

    virtual float calculPretRedus() = 0;

};
