#include <string>
#include "Produs.h"

using namespace std;

class PlacaBaza : public Produs {
private:
    string cod_produs; //codul produsului
    string soclu; //socket-ul placii de baza
    string chipset; //chipset-ul placii de baza
    string format; //forma placii de baza
    string tip_memorie; //tipul memoriei placii de baza
    static int nrProduseDistincte; //numarul de produse distincte
    static int index_cod; //indexul codului produsului

public:
    PlacaBaza(float pret, const string &model, int an_fabricatie, int garantie, const string &producator,
              const string &taraProvenienta, int stoc, string &soclu, string &chipset, string &format,
              string &tip_memorie); //constructor cu toate argumentele

    ~PlacaBaza(); //destructor

    void afisare() const; //afisarea placii de baza

    const string &getCodProdus() const; //getter pentru codul produsului

    const string &getSoclu() const;
    void setSoclu(const string &soclu);

    const string &getChipset() const;
    void setChipset(const string &chipset);

    const string &getFormat() const;
    void setFormat(const string &format);

    const string &getTipMemorie() const;
    void setTipMemorie(const string &tipMemorie);

    void outputFisier(ofstream &stream, char sep = ',', bool useEndl = true) const override;

    void afisarePretDupaProducator(string& producatorCautat);

    float calculPretRedus();
};