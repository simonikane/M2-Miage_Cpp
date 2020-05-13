#include <iostream>
#include "Input/Iris.h"
#include <vector>
const int NB_IRIS = 150;
const int NB_TRAINING = 60000;

int main() {
    std::cout << "M2 MASTER MIAGE IF - RESEAU DE NEURONES!" << std::endl;

    // Création du vecteur contenant les données Iris
    std::vector<Iris> iris_vector;

    // Rajouter les iris0,iris1 [...] iris149 au vector
    for (int i = 0; i < NB_IRIS; i++) {
        Iris newIris(i);
        iris_vector.push_back(newIris);
    }

    // Afficher les données du vecteur
    for (int i = 0; i < NB_IRIS; i++) {
        for (int indice_description = 0; indice_description < 3; indice_description++) {
            std::cout << iris_vector.at(i)[indice_description] << ",";
        }
        std::cout<<iris_vector.at(i).get_label()<<"\n";
    }

    return 0;
}
