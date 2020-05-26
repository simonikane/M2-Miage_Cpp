#include <iostream>
#include "Input/Iris.h"
#include "Input/Image.h"
#include <vector>
using namespace std;

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

/*    for (int i = 0; i < iris_vector.size(); i++) {
        for (int j = 0; j < 4; j++) {
            std::cout <<" Iris  " << i << "  "<< iris_vector.at(i)[j]<<"\n";
        }
        cout<<"Pour l'iris  "<< i << "  Le label correspondant est "<<iris_vector.at(i).get_label()<<"\n";
    }*/

    // Rajouter les training0, training1, [...] training59999 au vecteur d'Images
    for (int indiceImage = 0; indiceImage < 2; indiceImage++) {
        Image newImage(indiceImage);
        image_vector.push_back(newImage);
        std::cout << "Label : " << static_cast<unsigned>(image_vector.at(indiceImage).get_label()) << "\n";
        for (int i = 0; i < 700; i++) {
            std::cout << "Nuance de gris du " << i << "eme pixel/indice : " << image_vector.at(indiceImage)[i] << "\n";
        }
    }
    // Afficher les données du vecteur d'Iris
    for (int i = 0; i < NB_IRIS; i++) {
        for (int indice_description = 0; indice_description < 4; indice_description++) {
            std::cout << iris_vector.at(i)[indice_description] << "\n";
        }
        //std::cout << static_cast<unsigned>(iris_vector.at(i).get_label())
        //<< "\n"; // on fait un static_cast pour transformer la valeur acsii inconnue en vraie valeur
    }

    // Afficher les données du vecteur d'Images

    for (int indiceImage = 0; indiceImage < 1; indiceImage++) {
        std::cout << "Label : " << static_cast<unsigned>(image_vector.at(indiceImage).get_label()) << "\n";
        for (int i = 0; i < 700; i++) {
            std::cout << "Nuance de gris du " << i << "eme pixel/indice : " << image_vector.at(indiceImage)[i] << "\n";
        } // print
    }

    return 0;
}
