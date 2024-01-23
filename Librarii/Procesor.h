#include <string>
#include "Produs.h"

class Procesor : public Produs {
private:
    string soclu; //socket-ul procesorului
    int frecventa; //frecventa procesorului
    int numar_nuclee; //numarul de nuclee ale procesorului
    int memorie_cache; //memoria cache a procesorului

public:
    Procesor(int codProdus, float pret, const string &marca, int an_fabricatie, int garantie, const string &producator,
             const string &taraProvenienta, int stoc, string &soclu, int frecventa, int numar_nuclee,
             int memorie_cache) {} //constructor cu toate argumentele

    ~Procesor() {} //destructor

    void afisare() const {}

    const string &getSoclu() const;

    void setSoclu(const string &soclu);

    int getFrecventa() const;

    void setFrecventa(int frecventa);

    int getNumarNuclee() const;

    void setNumarNuclee(int numarNuclee);

    int getMemorieCache() const;

    void setMemorieCache(int memorieCache);
};
