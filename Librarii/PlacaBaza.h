#include "Produs.h"

class PlacaBaza : public Produs {
private:
    string soclu; //socket-ul placii de baza
    string chipset; //chipset-ul placii de baza
    string format; //forma placii de baza
    string tip_memorie; //tipul memoriei placii de baza

public:
    PlacaBaza(int codProdus, float pret, const string &marca, int an_fabricatie, int garantie, const string &producator,
              const string &taraProvenienta, int stoc, string &soclu, string &chipset, string &format,
              string &tip_memorie) {} //constructor cu toate argumentele

    ~PlacaBaza() {} //destructor

    void afisare() const {} //afisarea placii de baza
    const string &getSoclu() const;

    void setSoclu(const string &soclu);

    const string &getChipset() const;

    void setChipset(const string &chipset);

    const string &getFormat() const;

    void setFormat(const string &format);

    const string &getTipMemorie() const;

    void setTipMemorie(const string &tipMemorie);
};