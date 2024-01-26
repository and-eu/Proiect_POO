#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include "Librarii/Produs.h"
#include "Librarii/Memorie.h"
#include "Librarii/PlacaBaza.h"
#include "Librarii/PlacaVideo.h"
#include "Librarii/Procesor.h"
#include "Librarii/Stocare.h"

using namespace std;

int citireInt();
float citireFloat();
string citireString();
int cautareProdus(vector<Produs*>& vectorProduse, bool skip_afisare = false);
void clearConsole();
void afisareSumar(vector<Produs*>& vectorProduse);

void vanzareProdus(vector<Produs*>& vectorProduse, bool &data_change);
void adaugareProdus(vector<Produs*>& vectorProduse, bool &data_change);
void stergereProdus(vector<Produs*>& vectorProduse, bool &data_change);
void incarcareStoc(vector<Produs*>& vectorProduse, bool &data_change);
void afisareProdus(vector<Produs*>& vectorProduse);
void pretRedus(vector<Produs*>& vectorProduse);
void totalCategorie(vector<Produs*>& vectorProduse);
void afisarePreturiProducator(vector<Produs*>& vectorProduse);
void salvareDate(vector<Produs*>& vectorProduse, bool &data_change);

int main() {
    ifstream fisier_in("../lista_produse.csv");
    int n;
    string linie;
    char *p_temp;
    vector<Produs*> vectorProduse;
    const char *sep = ",";
    bool data_change = false;

    vector<string> nume_categorii = {"Memorie", "PlacaBaza", "PlacaVideo", "Procesor", "Stocare"};
    unordered_map<std::string, int> map_categorie = {
            {"Memorie", 1},
            {"PlacaBaza", 2},
            {"PlacaVideo", 3},
            {"Procesor", 4},
            {"Stocare", 5}
    };

    if (fisier_in.is_open()){
        while (getline(fisier_in, linie)){
            stringstream stream(linie);

            string temp;
            vector<string> vect_linie;

            while(getline(stream, temp, *sep)){
                vect_linie.push_back(temp);
            }

            if (find(nume_categorii.begin(), nume_categorii.end(), vect_linie[0]) == nume_categorii.end()){
                continue;
            }

//                //atribute Produs
//            string categorie, model, producator, tara;
//            float pret = 0;
//            int an_fab, garantie, stoc;
//
//                //atribute derivate
//            string chipset, tip_memorie, soclu, format, tip_stocare;
//            int capacitate_memorie, frecventa, capacitate, viteza, numar_nuclee, cahe;

            auto iterator = map_categorie.find(vect_linie[0]);
            int conditie = iterator->second;

//            stoc = stof(vect_linie[1]);
//            model = vect_linie[2];
//            an_fab = stoi(vect_linie[3]);
//            garantie = stoi(vect_linie[4]);
//            producator = vect_linie[5];
//            tara = vect_linie[6];
//            stoc = stoi(vect_linie[7]);

            switch (conditie) {
                case 1:{
                    //Produs *temp_prod = new Memorie();
//                    tip_memorie = vect_linie[8];
//                    capacitate = stoi(vect_linie[9]);
//                    frecventa = stoi(vect_linie[10]);
//                    Produs *temp_prod = new Memorie(pret, model, an_fab, garantie, producator,
//                                                    tara, stoc, tip_memorie, capacitate, frecventa);
                    Produs *temp_prod = new Memorie(stof(vect_linie[1]), vect_linie[2], stoi(vect_linie[3]),
                                                    stoi(vect_linie[4]), vect_linie[5], vect_linie[6],
                                                    stoi(vect_linie[7]), vect_linie[8], stoi(vect_linie[9]),
                                                    stoi(vect_linie[10]));
                    vectorProduse.push_back(temp_prod);
                    break;}
                case 2:{
                    Produs *temp_prod = new PlacaBaza(stof(vect_linie[1]), vect_linie[2], stoi(vect_linie[3]),
                                                    stoi(vect_linie[4]), vect_linie[5], vect_linie[6], stoi(vect_linie[7]),
                                                    vect_linie[8], vect_linie[9], vect_linie[10], vect_linie[11]);
                    vectorProduse.push_back(temp_prod);
                    break;}
                case 3:{
                    Produs *temp_prod = new PlacaVideo(stof(vect_linie[1]), vect_linie[2], stoi(vect_linie[3]),
                                                      stoi(vect_linie[4]), vect_linie[5], vect_linie[6], stoi(vect_linie[7]),
                                                      vect_linie[8], stoi(vect_linie[9]), vect_linie[10], stoi(vect_linie[11]));
                    vectorProduse.push_back(temp_prod);
                    break;}
                case 4:{
                    Produs *temp_prod = new Procesor(stof(vect_linie[1]), vect_linie[2], stoi(vect_linie[3]),
                                                     stoi(vect_linie[4]), vect_linie[5], vect_linie[6], stoi(vect_linie[7]),
                                                     vect_linie[8], stoi(vect_linie[9]), stoi(vect_linie[10]), stoi(vect_linie[11]));
                    vectorProduse.push_back(temp_prod);
                    break;}
                case 5:{
                    Produs *temp_prod = new Stocare(stof(vect_linie[1]), vect_linie[2], stoi(vect_linie[3]),
                                                     stoi(vect_linie[4]), vect_linie[5], vect_linie[6], stoi(vect_linie[7]),
                                                     vect_linie[8], vect_linie[9], stoi(vect_linie[10]), stoi(vect_linie[11]));
                    vectorProduse.push_back(temp_prod);
                    break;}
                default:
                    continue;
            }
        }
        fisier_in.close();
    } else {
        cout<<"Fisierul nu a putut fi deschis"<<endl;
        return 1;
    }

    while(true){
        cout<<endl<<"Meniu principal"<<endl;
        cout<<"1. Vanzare produs"<<endl;
        cout<<"2. Adaugare produs"<<endl;
        cout<<"3. Stergere produs"<<endl;
        cout<<"4. Incarcare stoc produs"<<endl;
        cout<<"5. Afisare produs"<<endl;
        cout<<"6. Verificare reducere"<<endl;
        cout<<"7. Calcul total categorie"<<endl;
        cout<<"8. Afisare preturi pentru un anumit brand"<<endl;
        cout<<"9. Salvare date"<<endl;
        cout<<"0. Iesire"<<endl;
        cout<<"Selectati o optiune: ";
        int optiune = citireInt();
        switch (optiune) {
            case 1:
                vanzareProdus(vectorProduse, data_change);
                break;
            case 2:
                adaugareProdus(vectorProduse, data_change);
                break;
            case 3:
                stergereProdus(vectorProduse, data_change);
                break;
            case 4:
                incarcareStoc(vectorProduse, data_change);
                break;
            case 5:
                afisareProdus(vectorProduse);
                break;
            case 6:
                pretRedus(vectorProduse);
                break;
            case 7:
                totalCategorie(vectorProduse);
                break;
            case 8:
                afisarePreturiProducator(vectorProduse);
                break;
            case 9:
                salvareDate(vectorProduse, data_change);
                break;
            case 0:
                if (data_change == false){
                    cout<<"Iesire..."<<endl;
                    return 0;
                } else {
                    char raspuns;
                    while (true) {
                        cout << "Datele nu au fost salvate. Doriti sa salvati datele?" << endl;
                        cout << "[Y] pentru salvare si iesire, [N] pentru iesire fara salvare: ";
                        cin >> raspuns;
                        cout<<endl;
                        if (raspuns == 'Y' or raspuns == 'y') {
                            salvareDate(vectorProduse, data_change);
                            return 0;
                        } else if (raspuns == 'N' or raspuns == 'n') {
                            return 0;
                        } else {
                            cout<<"Optiune invalida."<<endl;
                            continue;
                        }
                    }
                }
                break;
            default:
                cout<<"Nu ati selectat o optiune valida."<<endl;
                continue;
        }
    }

    return 0;
}
void clearConsole(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void afisareSumar(vector<Produs*>& vectorProduse){
    cout<<endl<<"Sumar produse:"<<endl;
    for(const auto &prod: vectorProduse){
        cout<<"Cod: "<<prod->getCodProdus()<<", Model: "<<prod->getModel()<<", Pret: "<<prod->getPret()<<", Stoc: "<<
        prod->getStoc()<<endl;
    }
    cout<<endl;
}

int citireInt(){

    int numar;
    while (true){
        cin>>numar;
        if (cin.fail()){
            cout<<"Nu ati introdus un numar. Va rog reintroduceti numarul: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else
            return numar;
    }
}

float citireFloat(){
    clearConsole();
    float numar;
    while (true){
        cin>>numar;
        if (cin.fail()){
            cout<<"Nu ati introdus un numar cu zecimale. Va rog reintroduceti numarul: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else
            return numar;
    }
}

string citireString(){
    clearConsole();
    string text;
    while (true){
        getline(cin, text);
        if (text.size()>3){
            return text;
        } else {
            cout<<"Textul introdus este prea scurt. Introduceti din nou: "<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int cautareProdus(vector<Produs*>& vectorProduse, bool skip_afisare){
    afisareSumar(vectorProduse);
    cout<<"Introduceti codul produsului: ";
    string cod = citireString();
    if (cod.size() != 6){
        cout<<"Codul introdus nu are 6 caractere."<<endl;
        return -1;
    }
    int i = 0;
    while (i<vectorProduse.size()){
        if (vectorProduse[i]->getCodProdus() == cod){
            if (skip_afisare) {
                cout<<endl;
                return i;
            }
            cout<<"Produs gasit."<<endl;
            while (true) {
                char raspuns;
                cout << "Doriti sa vizualizati produsul? (Y/n)"<<endl;
                cin >> raspuns;

                if (raspuns == 'Y' or raspuns == 'y') {
                    vectorProduse[i]->afisare();
                    return i;
                } else if (raspuns == 'N' or raspuns == 'n') {
                    return i;
                } else {
                    cout << "Optiune invalida." << endl;
                    continue;
                }
            }
        } else {
            i++;
        }
    }
    cout<<"Codul nu a fot gasit"<<endl;
    return -1;
}

void vanzareProdus(vector<Produs*>& vectorProduse, bool &data_change){
    int index = cautareProdus(vectorProduse);
    if (index == -1) return;
    cout<<"Introduceti cantitatea: ";
    int cantitate = citireInt();
    bool rezultat = vectorProduse[index]->vanzareProdus(cantitate);
    if (rezultat == true){
        data_change = true;
    } else
        return;
}

void adaugareProdus(vector<Produs*>& vectorProduse, bool &data_change){

}

void stergereProdus(vector<Produs*>& vectorProduse, bool &data_change){
    int index = cautareProdus(vectorProduse);
    if (index == -1) return;

    while (true) {
        char raspuns;
        cout<<"Sunteti sigur ca doriti sa stergeti: (Y/n)"<<endl;
        cin >> raspuns;
        if (raspuns == 'Y' or raspuns == 'y') {
            vectorProduse.erase(vectorProduse.begin()+index);
            data_change = true;
            return;
        } else {
            return;
        }
    }
}

void incarcareStoc(vector<Produs*>& vectorProduse, bool &data_change){
    int index = cautareProdus(vectorProduse);
    if (index == -1) return;
    cout<<"Introduceti cantitatea: ";
    int cantitate = citireInt();
    vectorProduse[index]->incarcaStoc(cantitate);
    data_change = true;
}

void afisareProdus(vector<Produs*>& vectorProduse){
    int index = cautareProdus(vectorProduse, true);
    if (index == -1) return;
    vectorProduse[index]->afisare();
    cout<<endl<<"Press any key to continue."<<endl;
    cin.get();
    return;
}

void pretRedus(vector<Produs*>& vectorProduse){
    int index = cautareProdus(vectorProduse);
    if (index == -1) return;
    cout<<"Pretul intreg este: "<<vectorProduse[index]->getPret()<<endl;
    cout<<"Pretul cu discount este: "<<vectorProduse[index]->calculPretRedus()<<endl;
}

void totalCategorie(vector<Produs*>& vectorProduse){
    float total_categorie = 0;
    cout<<endl<<"Categorii: "<<endl;
    cout<<"1. Procesor"<<endl;
    cout<<"2. Placa de baza"<<endl;
    cout<<"3. Memorie "<<endl;
    cout<<"4. Placa video"<<endl;
    cout<<"5. Mediu de stocare"<<endl;
    cout<<"0. Renuntare"<<endl;
    cout<<"Selectati o optiune: ";
    int optiune = citireInt();
    switch (optiune) {
        case 1:
            for (const auto& prod : vectorProduse) {
                Procesor* tip = dynamic_cast<Procesor*>(prod);
                if (tip != nullptr) {
                    total_categorie += tip->getStoc() * tip->getPret();
                }
            }
            cout<<"Totalul categoriei Procesor este: "<< total_categorie<<" lei"<<endl;
            cout<<endl<<"Press any key to continue."<<endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            return;
        case 2:
            for (const auto& prod : vectorProduse) {
                PlacaBaza* tip = dynamic_cast<PlacaBaza*>(prod);
                if (tip != nullptr) {
                    total_categorie += tip->getStoc() * tip->getPret();
                }
            }
            cout<<"Totalul categoriei Placa de Baza este: "<< total_categorie<<" lei"<<endl;
            cout<<endl<<"Press any key to continue."<<endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            return;
        case 3:
            for (const auto& prod : vectorProduse) {
                Memorie* tip = dynamic_cast<Memorie*>(prod);
                if (tip != nullptr) {
                    total_categorie += tip->getStoc() * tip->getPret();
                }
            }
            cout<<"Totalul categoriei Memorie este: "<< total_categorie<<" lei"<<endl;
            cout<<endl<<"Press any key to continue."<<endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            return;
        case 4:
            for (const auto& prod : vectorProduse) {
                PlacaVideo* tip = dynamic_cast<PlacaVideo*>(prod);
                if (tip != nullptr) {
                    total_categorie += tip->getStoc() * tip->getPret();
                }
            }
            cout<<"Totalul categoriei Placa video este: "<< total_categorie<<" lei"<<endl;
            cout<<endl<<"Press any key to continue."<<endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            return;
        case 5:
            for (const auto& prod : vectorProduse) {
                Stocare* tip = dynamic_cast<Stocare*>(prod);
                if (tip != nullptr) {
                    total_categorie += tip->getStoc() * tip->getPret();
                }
            }
            cout<<"Totalul categoriei Mediu de stocare este: "<< total_categorie<<" lei"<<endl;
            cout<<endl<<"Press any key to continue."<<endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            return;
        case 0:
            return;
    }
}
void afisarePreturiProducator(vector<Produs*>& vectorProduse){
    vector<string> liste_producatori;
    for (const auto& prod : vectorProduse) {
        if (find(liste_producatori.begin(), liste_producatori.end(), prod->getProducator()) == liste_producatori.end()){
            liste_producatori.push_back(prod->getProducator());
        }
    }
    cout<<"lista producatori: ";
    for (const auto& nume : liste_producatori){
        cout<<nume<<", ";
    }
    cout<<endl;

    cout<<"Introduceti brand-ul pentru care doriti sa afisati preturile: "<<endl;
    string producator = citireString();
    for (const auto& prod : vectorProduse) {
        prod->afisarePretDupaProducator(producator);
    }
    cout<<"Press any key to continue."<<endl;
    cin.get();
    return;
}

void salvareDate(vector<Produs*>& vectorProduse, bool &data_change){

}
