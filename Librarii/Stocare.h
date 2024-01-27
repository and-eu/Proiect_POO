#include <string>
#include "Produs.h"

using namespace std;

class Stocare : public Produs {
private:
    string cod_produs; //codul produsului
    string tip; //tipul stocarii
    string format; //formatul stocarii
    int capacitate; //capacitatea stocarii
    int viteza; //viteza stocarii
    static int index_cod; //indexul codului produsului
    static int nrProduseDistincte; //numarul de produse distincte

public:
    Stocare(float pret, const string &model, int an_fabricatie, int garantie, const string &producator,
        const string &taraProvenienta, int stoc, string &tip, string &format, int capacitate,
        int viteza); //constructor cu toate argumentele

~Stocare(); //destructor

    void afisare() const; //afisarea stocarii

    const string &getCodProdus() const; //getter pentru codul produsului

    const string &getTip() const;
    void setTip(const string &tip);

    const string &getFormat() const;
    void setFormat(const string &format);

    int getCapacitate() const;
    void setCapacitate(int capacitate);

    int getViteza() const;
    void setViteza(int viteza);

    void outputFisier(ofstream &stream, char sep = ',', bool useEndl = true) const override;

    void afisarePretDupaProducator(string& producatorCautat);

    float calculPretRedus();
};