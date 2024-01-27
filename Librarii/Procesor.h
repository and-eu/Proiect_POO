#include <string>
#include "Produs.h"

using namespace std;

class Procesor : public Produs {
private:
    string cod_produs; //codul produsului
    string soclu; //socket-ul procesorului
    int frecventa; //frecventa procesorului
    int numar_nuclee; //numarul de nuclee ale procesorului
    int memorie_cache; //memoria cache a procesorului
    static int nrProduseDistincte; //numarul de produse distincte de tip procesor
    static int index_cod; //indexul codului produsului

public:
    Procesor(float pret, const string &model, int an_fabricatie, int garantie, const string &producator,
             const string &taraProvenienta, int stoc, string &soclu, int frecventa, int numar_nuclee,
             int memorie_cache); //constructor cu toate argumentele

    ~Procesor(); //destructor

    void afisare() const;

    const string &getCodProdus() const;

    const string &getSoclu() const;
    void setSoclu(const string &soclu);

    int getFrecventa() const;
    void setFrecventa(int frecventa);

    int getNumarNuclee() const;
    void setNumarNuclee(int numarNuclee);

    int getMemorieCache() const;
    void setMemorieCache(int memorieCache);

    void outputFisier(ofstream &stream, char sep = ',', bool useEndl = true) const override;

    void afisarePretDupaProducator(string& producatorCautat);

    float calculPretRedus();
};
