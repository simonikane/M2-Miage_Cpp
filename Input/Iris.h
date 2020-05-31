//
// Created by CRYSTA on 10/05/2020.
// Permet de s'occuper de la gestion des Iris (créer un Iris a partir du dataset "iris_training")
//

#ifndef PROJET_CPP_IRIS_H
#define PROJET_CPP_IRIS_H


#include "Input.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

class Iris : public Input {
public:
    Iris(int indice);//charge la description de la fleur et son label
    double operator[](int i);

    std::vector<std::string> split(std::string chaine, char delimit); //pour recupérer les 4 reel de chaque iris
private:
    double description[4];
};


#endif //PROJET_CPP_IRIS_H