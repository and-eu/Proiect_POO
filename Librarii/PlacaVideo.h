#include <string>
#include "Produs.h"

using namespace std;

class PlacaVideo : public Produs{
private:
    string chipset; //chipset-ul placii video
    string model; //modelul placii video
    int capacitate_memorie; //memoria placii video
    string tip_memorie; //tipul memoriei placii video
    int frecventa; //frecventa placii video

public:
    PlacaVideo(int codProdus, float pret, const string &marca, int an_fabricatie, int garantie, const string &producator,
               const string &taraProvenienta, int stoc, string &chipset, string &model, int capacitate_memorie,
               string &tip_memorie, int frecventa) {} //constructor cu toate argumentele

    ~PlacaVideo() {} //destructor

    void afisare() const {} //afisarea placii video
    const string &getChipset() const;

    void setChipset(const string &chipset);

    const string &getModel() const;

    void setModel(const string &model);

    int getCapacitateMemorie() const;

    void setCapacitateMemorie(int capacitateMemorie);

    const string &getTipMemorie() const;

    void setTipMemorie(const string &tipMemorie);

    int getFrecventa() const;

    void setFrecventa(int frecventa);
};
