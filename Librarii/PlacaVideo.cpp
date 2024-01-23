#include "PlacaVideo.h"

const string &PlacaVideo::getChipset() const {
    return chipset;
}

void PlacaVideo::setChipset(const string &chipset) {
    PlacaVideo::chipset = chipset;
}

const string &PlacaVideo::getModel() const {
    return model;
}

void PlacaVideo::setModel(const string &model) {
    PlacaVideo::model = model;
}

int PlacaVideo::getCapacitateMemorie() const {
    return capacitate_memorie;
}

void PlacaVideo::setCapacitateMemorie(int capacitateMemorie) {
    capacitate_memorie = capacitateMemorie;
}

const string &PlacaVideo::getTipMemorie() const {
    return tip_memorie;
}

void PlacaVideo::setTipMemorie(const string &tipMemorie) {
    tip_memorie = tipMemorie;
}

int PlacaVideo::getFrecventa() const {
    return frecventa;
}

void PlacaVideo::setFrecventa(int frecventa) {
    PlacaVideo::frecventa = frecventa;
}
