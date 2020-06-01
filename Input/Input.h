//
// Created by CRYSTA on 10/05/2020.
//  La classe "Input" représente tout type de donnée pouvant être analysé par le réseau de neurone
// Ainsi dans notre cas, ce sont des set d'iris et d'images.
//

#ifndef PROJET_CPP_INPUT_H
#define PROJET_CPP_INPUT_H

#include <string>

// Le chemin vers le dossier contenant les les données iris et celles pour les images
//const std::string PROJECT_FOLDER_PATH = R"(C:\Users\33652\Downloads\Cours 2019-2020\C++\Projet\M2-Miage_Cpp\)";
//const std::string PROJECT_FOLDER_PATH = R"(/Users/simonaarizanova/Documents/GitHub/M2-Miage_Cpp)";
const std::string PROJECT_FOLDER_PATH = R"(C:\\Users\\DiKeLa M'Babane\\Documents\\M2IF DAUPHINE\\M2-C++\\M2-Miage_Cpp\\)";

const int NB_IRIS = 150;
const int NB_TRAINING = 60000;

class Input {
public:
    virtual double operator[](int i) = 0;// permet d'accéder à une valeur du tableau
    char get_label();// Renvoie le label de l'input
    void set_label(char label);

private:
    char label;// le label de l'input
};


#endif //PROJET_CPP_INPUT_H
