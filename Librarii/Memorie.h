#include "Produs.h"

class MemorieRAM : public Produs {
private:
    string tip_memorie; //tipul memoriei RAM
    int capacitate; //capacitatea memoriei RAM
    int frecventa; //frecventa memoriei RAM

public:
    MemorieRAM(int codProdus, float pret, const string &marca, int an_fabricatie, int garantie,
               const string &producator, const string &taraProvenienta, int stoc, string &tip_memorie, int capacitate,
               int frecventa) {} //constructor cu toate argumentele

    ~MemorieRAM() {} //destructor

    void afisare() const {} //afisarea memoriei RAM
    const string &getTipMemorie() const;

    void setTipMemorie(const string &tipMemorie);

    int getCapacitate() const;

    void setCapacitate(int capacitate);

    int getFrecventa() const;

    void setFrecventa(int frecventa);
};