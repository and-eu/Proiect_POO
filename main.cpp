#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include "Librarii/Produs.h"
#include "Librarii/Memorie.h"
#include "Librarii/PlacaBaza.h"
#include "Librarii/PlacaVideo.h"
#include "Librarii/Procesor.h"
#include "Librarii/Stocare.h"

using namespace std;

int main() {
    ifstream fisier("../lista_produse.csv");
    int n;
    string linie;
    char *p_temp;
    vector<Produs> VP;
    const char *sep = ",";

    vector<string> nume_categorii = {"Memorie", "PlacaBaza", "PlacaVideo", "Procesor", "Stocare"};
    unordered_map<std::string, int> map_categorie = {
            {"Memorie", 1},
            {"PlacaBaza", 2},
            {"PlacaVideo", 3},
            {"Procesor", 4},
            {"Stocare", 5}
    };

    if (fisier.is_open()){
        while (getline(fisier, linie)){
            stringstream stream(linie);

            string temp;
            vector<string> vect_linie;

            while(getline(stream, temp, *sep)){
                vect_linie.push_back(temp);
            }

            if (find(nume_categorii.begin(), nume_categorii.end(), vect_linie[0]) == nume_categorii.end()){
                continue;
            }

                //atribute Produs
            string categorie, model, producator, tara;
            float pret;
            int an_fab, garantie, stoc;

                //atribute derivate
            string chipset, tip_memorie, soclu, format, tip_stocare;
            int capacitate_memorie, frecventa, capacitate, viteza, numar_nuclee, cahe;

            auto iterator = map_categorie.find(vect_linie[0]);
            int conditie = iterator->second;

            int index = 0;
            switch (conditie) {
                case 1:
                    break;

                default:
                    continue;
                    break;
            }


        }

    }

    return 0;
}
