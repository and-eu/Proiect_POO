#include <string>
#include "Produs.h"

using namespace std;

class Memorie : public Produs {
private:
    string cod_produs; //codul produsului
    string tip_memorie; //tipul memoriei RAM
    int capacitate; //capacitatea memoriei RAM
    int frecventa; //frecventa memoriei RAM
    static int nrProduseDistincte; //numarul de produse distincte de tipul memorie RAM
    static int index_cod; //indexul codului produsului

public:
    Memorie(float pret, const string &model, int an_fabricatie, int garantie, const string &producator,
               const string &taraProvenienta, int stoc, string &tip_memorie, int capacitate,
               int frecventa); //constructor cu toate argumentele

    ~Memorie(); //destructor

    void afisare() const; //afisarea memoriei RAM

    const string &getCodProdus() const;

    const string &getTipMemorie() const;
    void setTipMemorie(const string &tipMemorie);

    int getCapacitate() const;
    void setCapacitate(int capacitate);

    int getFrecventa() const;
    void setFrecventa(int frecventa);

    void outputFisier(ofstream &stream, char sep = ',') const;

    void afisarePretDupaProducator(string& producatorCautat);

    float calculPretRedus();
};