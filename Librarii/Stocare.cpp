#include "Stocare.h"

namespace std {
} // std
const string &Stocare::getTip() const {
    return tip;
}

void Stocare::setTip(const string &tip) {
    Stocare::tip = tip;
}

const string &Stocare::getFormat() const {
    return format;
}

void Stocare::setFormat(const string &format) {
    Stocare::format = format;
}

int Stocare::getCapacitate() const {
    return capacitate;
}

void Stocare::setCapacitate(int capacitate) {
    Stocare::capacitate = capacitate;
}

int Stocare::getViteza() const {
    return viteza;
}

void Stocare::setViteza(int viteza) {
    Stocare::viteza = viteza;
}
