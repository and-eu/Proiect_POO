#include <string>
#include <ostream>

using namespace std;

class Produs{  // Clasa de baza abstracta
protected:
    int cod_produs; //cod unic
    float pret; //pretul produsului
    string marca; //marca produsului
    int an_fabricatie; //anul fabricatiei
    int garantie; //numar luni
    string producator; //numele producatorului
    string tara_provenienta; //tara de provenienta
    int stoc; //numarul de produse din stoc
public:
    Produs(); //constructor fara parametrii

    Produs(int codProdus, float pret, const string &marca, int an_fabricatie, int garantie, const string &producator,
           const string &taraProvenienta, int stoc); //constructor cu parametrii

    virtual ~Produs(); //destructor

    [[nodiscard]] int getCodProdus() const; //getter pentru codul produsului

    void setCodProdus(int codProdus); //setter pentru codul produsului

    [[nodiscard]] float getPret() const; //getter pentru pretul produsului

    void setPret(float pret); //setter pentru pretul produsului

    [[nodiscard]] const string &getMarca() const; //getter pentru marca produsului

    void setMarca(const string &marca); //setter pentru marca produsului

    [[nodiscard]] int getAnFabricatie() const; //getter pentru anul fabricatiei

    void setAnFabricatie(int anFabricatie); //setter pentru anul fabricatiei

    [[nodiscard]] int getGarantie() const; //getter pentru garantie

    void setGarantie(int garantie); //setter pentru garantie

    [[nodiscard]] const string &getProducator() const; //getter pentru producator

    void setProducator(const string &producator); //setter pentru producator

    [[nodiscard]] const string &getTaraProvenienta() const; //getter pentru tara de provenienta

    void setTaraProvenienta(const string &taraProvenienta); //setter pentru tara de provenienta

    [[nodiscard]] int getStoc() const; //getter pentru stoc

    void setStoc(int stoc); //setter pentru stoc

    void afisare() const; //afisarea produsului

    friend ostream &operator<<(ostream &os, const Produs &produs); //supraincarcarea operatorului de afisare << pentru produs (pentru a putea fi afisat in fisier) (nu este folosit in program)
};
