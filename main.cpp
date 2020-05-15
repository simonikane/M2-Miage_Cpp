#include <iostream>
#include "Input/Iris.h"
#include "Input/Image.h"
#include <vector>


int main() {
    std::cout << "--------------------- M2 MASTER MIAGE IF - RESEAU DE NEURONES ---------------------\n";
    std::cout << "Project Path Folder : " << PROJECT_FOLDER_PATH << "\n";
    std::cout << "\n--------------------- Import des Images et des Iris ---------------------\n";



    // Création du vecteur contenant les données Iris
    std::vector<Iris> iris_vector;
    std::vector<Image> image_vector;

    // Rajouter les iris0,iris1 [...] iris149 au vecteur d'Iris
    for (int indiceIris = 0; indiceIris < NB_IRIS; indiceIris++) {
        Iris newIris(indiceIris);
        iris_vector.push_back(newIris);
    }

    // Rajouter les training0, training1, [...] training59999 au vecteur d'Images
    for (int indiceImage = 0; indiceImage < 1; indiceImage++) {
        Image newImage(indiceImage);
        image_vector.push_back(newImage);
    }
    // Afficher les données du vecteur Iris
/*    for (int i = 0; i < NB_IRIS; i++) {
        for (int indice_description = 0; indice_description < 3; indice_description++) {
            std::cout << iris_vector.at(i)[indice_description] << ",";
        }
        std::cout<<iris_vector.at(i).get_label()<<"\n";
    }*/




    return 0;
}
