#include "Memorie.h"

const string &MemorieRAM::getTipMemorie() const {
    return tip_memorie;
}

void MemorieRAM::setTipMemorie(const string &tipMemorie) {
    tip_memorie = tipMemorie;
}

int MemorieRAM::getCapacitate() const {
    return capacitate;
}

void MemorieRAM::setCapacitate(int capacitate) {
    MemorieRAM::capacitate = capacitate;
}

int MemorieRAM::getFrecventa() const {
    return frecventa;
}

void MemorieRAM::setFrecventa(int frecventa) {
    MemorieRAM::frecventa = frecventa;
}
