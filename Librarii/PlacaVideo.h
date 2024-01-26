#include <string>
#include "Produs.h"

using namespace std;

class PlacaVideo : public Produs{
private:
    string cod_produs; //codul produsului
    string chipset; //chipset-ul placii video
    int capacitate_memorie; //memoria placii video
    string tip_memorie; //tipul memoriei placii video
    int frecventa; //frecventa placii video
    static int nrProduseDistincte; //numarul de produse distincte
    static int index_cod; //indexul codului produsului

public:
    PlacaVideo(float pret, const string &model, int an_fabricatie, int garantie, const string &producator,
               const string &taraProvenienta, int stoc, string &chipset, int capacitate_memorie,
               string &tip_memorie, int frecventa); //constructor cu toate argumentele

    ~PlacaVideo(); //destructor

    void afisare() const; //afisarea placii video

    const string &getCodProdus() const; //getter pentru codul produsului

    const string &getChipset() const;
    void setChipset(const string &chipset);

    int getCapacitateMemorie() const;
    void setCapacitateMemorie(int capacitateMemorie);

    const string &getTipMemorie() const;
    void setTipMemorie(const string &tipMemorie);

    int getFrecventa() const;
    void setFrecventa(int frecventa);

    void outputFisier(ofstream &stream, char sep = ",") const;

    void afisarePretDupaProducator(string& producatorCautat);

    float calculPretRedus();
};
