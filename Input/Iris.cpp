//
// Created by CRYSTA on 10/05/2020.
// Permet de s'occuper de la gestion des Iris (créer un Iris a partir du dataset "iris_training")
//

#include "Iris.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

/**
   @brief Permet de parser un iris et récupérer les données de la fleur
   @param string chaine : l'iris en entrée depuis la base "iris_training"
   @param char delimit : le délimiteur qui permet de diviser la chaine, dans le cas des "iris" ce serai une virgule
   @return vector<string> Iris : L'iris parsé
   */
vector<std::string> Iris::split(std::string chaine, char delimit) {
    stringstream ss(chaine);
    string element;
    vector<std::string> tabChar;
    while (std::getline(ss, element, delimit))
    {
        tabChar.push_back(element);
    }
    return tabChar;
}

/**
   @brief Permet la lecture des iris et l'affectation de label de la manière suivante
   Iris setosa (label 0), Iris virginica (label 1) and Iris versicolor (label 2)
   @param int indice : indice du tableau d'Iris
   */
Iris::Iris(int indice) :Input() {
    //Pour un Windows ou Linux
    string pathFolder = PROJECT_FOLDER_PATH + "\\Data_Source\\iris_training\\";

    //Pour un MacOS
    //string pathFolder = PROJECT_FOLDER_PATH + "/Data_Source/iris_training/";

    string filePath = pathFolder.append("iris" + to_string(indice));
    ifstream irisFile(filePath);
    if (irisFile) {
        string ligne;
        if (getline(irisFile, ligne)) {
            char c = ',';
            vector<string> myVector = this->split(ligne, c);
            int sizeVec = myVector.size();

            if (!myVector.at(sizeVec - 1).compare("Iris-setosa")) {
                this->set_label(0);
            } else if (!myVector.at(sizeVec - 1).compare("Iris-virginica")) {
                this->set_label(1);
            } else if (!myVector.at(sizeVec - 1).compare("Iris-versicolor")) {
                this->set_label(2);
            }
            for (int i = 0; i < (sizeVec - 1); i++) {
                this->description[i] = stod(myVector.at(i));
            }
        } else{
            cerr<<"ERREUR";
        }
    } else{
        cerr << "ERREUR : impossible d'ouvrir le fichier " << filePath << "\n";
    }
    irisFile.close();

}

/** @brief L'opérateur [] qui permet d'accéder à un caractéristique de l'Iris
   @param int indice : l'indice du tableau d'Iris
   @return double  : un des champs caractéristique de la fleur (longueur de pétale, largeur sépales etc...) */
double Iris::operator[] (int indice) {
    return indice >= 0 && indice <= 3 ? this->description[indice] : -1;
}
