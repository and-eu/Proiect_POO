#include "Produs.h"

class Stocare : public Produs {
private:
    string tip; //tipul stocarii
    string format; //formatul stocarii
    int capacitate; //capacitatea stocarii
    int viteza; //viteza stocarii


public:

Stocare(int codProdus, float pret, const string &marca, int an_fabricatie, int garantie, const string &producator,
        const string &taraProvenienta, int stoc, string &tip, string &format, int capacitate,
        int viteza) {} //constructor cu toate argumentele

~Stocare() {} //destructor

void afisare() const {} //afisarea stocarii
    const string &getTip() const;

    void setTip(const string &tip);

    const string &getFormat() const;

    void setFormat(const string &format);

    int getCapacitate() const;

    void setCapacitate(int capacitate);

    int getViteza() const;

    void setViteza(int viteza);
};