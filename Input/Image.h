//
// Created by CRYSTA on 10/05/2020.
//

#ifndef PROJET_CPP_IMAGE_H
#define PROJET_CPP_IMAGE_H

#include "Input.h"

const std::string PROJECT_FOLDER_PATH = R"(C:\Users\33652\Downloads\Cours 2019-2020\C++\Projet\M2-Miage_Cpp\)";
const int NB_IRIS = 150;
const int NB_TRAINING = 60000;


class Image : public Input {
public:
    explicit Image(int indice);//constructeur indice i correspondant à l'indice de l'image
    double operator[](int pixel) override;//Renvoie le niveau de gris du pixel correspondant
    //get_label deja utilisé dans Input même signature donc pas bésoin de le redefinir
private:
    char pixel[28][28]; // image composée de 28*28 pixels compris entre 0 et 255
};

#endif //PROJET_CPP_IMAGE_H
