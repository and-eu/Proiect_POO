#include "Procesor.h"

const string &Procesor::getSoclu() const {
    return soclu;
}

void Procesor::setSoclu(const string &soclu) {
    Procesor::soclu = soclu;
}

int Procesor::getFrecventa() const {
    return frecventa;
}

void Procesor::setFrecventa(int frecventa) {
    Procesor::frecventa = frecventa;
}

int Procesor::getNumarNuclee() const {
    return numar_nuclee;
}

void Procesor::setNumarNuclee(int numarNuclee) {
    numar_nuclee = numarNuclee;
}

int Procesor::getMemorieCache() const {
    return memorie_cache;
}

void Procesor::setMemorieCache(int memorieCache) {
    memorie_cache = memorieCache;
}
