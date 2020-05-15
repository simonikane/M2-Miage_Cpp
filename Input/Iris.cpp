//
// Created by CRYSTA on 10/05/2020.

#include "Iris.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

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
 *
 * @param indice
 */
Iris::Iris(int indice) :Input() {
    //string pathFolder = "C:\\Users\\DiKeLa M'Babane\\Documents\\M2IF DAUPHINE\\M2-C++\\M2-Miage_Cpp\\Data_Source\\iris_training\\";
    string iris_training_folderPath = "C:\\Users\\33652\\Downloads\\Cours 2019-2020\\C++\\Projet\\M2-Miage_Cpp\\Data_Source\\iris_training\\";
    string filePath = iris_training_folderPath.append("iris" + to_string(indice));
    ifstream irisFile(filePath);
    if (irisFile) {
        string ligne;
        if (getline(irisFile, ligne)) {
            char c = ',';
            vector<string> myVector = this->split(ligne, c);
            int sizeVec = myVector.size();
            this->set_label(myVector.at(sizeVec - 1));
            // cout << "\n";
            for (int i = 0; i < (sizeVec - 1); i++) {
                this->description[i] = stod(myVector.at(i));
                // cout<<this->description[i]<<",";
            }
            // cout<<this->get_label();

        } else{
            cerr<<"ERREUR";
        }

    } else{

        cerr << "ERREUR : impossible d'ouvrir le fichier " << filePath << "\n";
    }
    irisFile.close();

}

double Iris::operator[] (int indice) {
    return indice >= 0 && indice <= 3 ? this->description[indice] : -1; // faire un try catch au lieu de renvoyer -1 ??
}

