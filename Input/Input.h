//
// Created by CRYSTA on 10/05/2020.
//

#ifndef PROJET_CPP_INPUT_H
#define PROJET_CPP_INPUT_H

#include <string>

// à changer
const std::string PROJECT_FOLDER_PATH = R"(C:\Users\33652\Downloads\Cours 2019-2020\C++\Projet\M2-Miage_Cpp\)";
const int NB_IRIS = 150;
const int NB_TRAINING = 60000;


class Input {
public:
    Input();

    virtual double operator[](int i) = 0;// permet d'accéder à une valeur du tableau
    char get_label();// Renvoie le label de l'input
    void set_label(char label);

    ~Input();

private:
    char label;// le label de l'input
};


#endif //PROJET_CPP_INPUT_H
