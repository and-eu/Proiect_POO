#include <string>
#include <ostream>

using namespace std;
class Produs{
protected:
    int cod_produs;
    float pret;
    string marca;
    int an_fabricatie;
    int garantie; //numar luni
    string producator;
    string tara_provenienta;
    int stoc;
public:
    Produs();

    Produs(int codProdus, float pret, const string &marca, int an_fabricatie, int garantie, const string &producator,
           const string &taraProvenienta, int stoc);

    virtual ~Produs();

    [[nodiscard]] int getCodProdus() const;

    void setCodProdus(int codProdus);

    [[nodiscard]] float getPret() const;

    void setPret(float pret);

    [[nodiscard]] const string &getMarca() const;

    void setMarca(const string &marca);

    int getAnFabricatie() const;

    void setAnFabricatie(int anFabricatie);

    [[nodiscard]] int getGarantie() const;

    void setGarantie(int garantie);

    [[nodiscard]] const string &getProducator() const;

    void setProducator(const string &producator);

    [[nodiscard]] const string &getTaraProvenienta() const;

    void setTaraProvenienta(const string &taraProvenienta);

    [[nodiscard]] int getStoc() const;

    void setStoc(int stoc);

    void afisare() const;

    friend ostream &operator<<(ostream &os, const Produs &produs);

};
