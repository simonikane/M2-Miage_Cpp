#include <iostream>
#include "Input/Iris.h"
#include "Input/Image.h"
#include "Perceptron/Fonction_activation.h"
#include "Perceptron/Tanh.h"
#include "Perceptron/Sigmoide.h"
#include "Perceptron/Perceptron.h"
#include "Perceptron/NN1.h"
#include "Perceptron/Apprentissage.h"
#include <vector>
#include <ctime>

void printInputs();

void testPerceptron();

using namespace std;

int main() {
    std::cout << "--------------------- M2 MASTER MIAGE IF - RESEAU DE NEURONES ---------------------\n";
    // printInputs();
    srand(time(NULL));
    testPerceptron();
    return 0;
}

void testPerceptron() {

    NN1 *reseau = new NN1(4, 3);
    Apprentissage<Iris, 150, NN1> apprentissageIris(reseau);
    apprentissageIris.apprendre_base(15000, 0.1);
    int nombreCorrect = apprentissageIris.evaluer();
    std::cout << "NN1 | Iris | Nombre d'Iris corrects : " << nombreCorrect << " || " << "Pourcentage de correct : "
              << nombreCorrect / 150.0 * 100 << "% de correct" << "\n";


    NN1 *reseau2 = new NN1(784, 10);
    Apprentissage<Image, 60000, NN1> apprentissageImage(reseau2);
    apprentissageImage.apprendre_base(100000, 1);
    int nombreCorrect2 = apprentissageImage.evaluer();
    std::cout << "NN1 | Image | Nombre d'Image corrects : " << nombreCorrect2 << " || " << "Pourcentage de correct : "
              << nombreCorrect2 / 60000.0 * 100 << "% de correct" << "\n";


    NN2 *reseau3 = new NN2(4, 3, 3);
    Apprentissage<Iris, 150, NN2> apprentissageIris2(reseau3);
    apprentissageIris2.apprendre_base(10000, 0.01);
    int nombreCorrect3 = apprentissageIris2.evaluer();
    std::cout << "NN2 | Iris | Nombre d'Iris corrects " << nombreCorrect3 << " || " << "Pourcentage de correct : "
              << nombreCorrect3 / 150.0 * 100 << "% de correct" << "\n";

    NN2 *reseau4 = new NN2(784, 10, 10);
    Apprentissage<Image, 60000, NN2> apprentissageImage2(reseau4);
    apprentissageImage2.apprendre_base(100000, 0.1);
    int nombreCorrect4 = apprentissageImage2.evaluer();
    std::cout << "NN2 | Image | Nombre d'Image corrects " << nombreCorrect4 << " || " << "Pourcentage de correct : "
              << nombreCorrect4 / 60000.0 * 100 << "% de correct" << "\n";
}

void printInputs() {
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

}
