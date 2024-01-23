#include "PlacaBaza.h"

const string &PlacaBaza::getSoclu() const {
    return soclu;
}

void PlacaBaza::setSoclu(const string &soclu) {
    PlacaBaza::soclu = soclu;
}

const string &PlacaBaza::getChipset() const {
    return chipset;
}

void PlacaBaza::setChipset(const string &chipset) {
    PlacaBaza::chipset = chipset;
}

const string &PlacaBaza::getFormat() const {
    return format;
}

void PlacaBaza::setFormat(const string &format) {
    PlacaBaza::format = format;
}

const string &PlacaBaza::getTipMemorie() const {
    return tip_memorie;
}

void PlacaBaza::setTipMemorie(const string &tipMemorie) {
    tip_memorie = tipMemorie;
}
