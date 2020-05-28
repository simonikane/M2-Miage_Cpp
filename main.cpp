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
    // printInputs();
    srand(time(NULL));
    testPerceptron();
    return 0;
}

void testPerceptron() {
//    Tanh *tanh = new Tanh();
//    Perceptron *perceptron = new Perceptron(4, tanh, 1);
//    Input *iris = new Iris(121);
//
//
//    cout << "\n";
//    perceptron->calcul_delta(*iris);
//    cout << "result forward : " << perceptron->forward(*iris) << "\n";
//    cout << "calcul_delta : " << perceptron->get_delta();
    NN1 *reseau = new NN1(4, 3);
    Apprentissage<Iris, 150> apprentissage(reseau);
    apprentissage.apprendre_base(500, 0.1);
    int nombreCorrect = apprentissage.evaluer();
    std::cout << "\nNombre de bons : " << nombreCorrect << " || " << "Pourcentage de correct : "
              << nombreCorrect / 150.0 * 100 << "% de correct";



//    NN1 *reseau2 = new NN1(784, 10);
//    Apprentissage<Image, 60000> apprentissageImage(reseau2);
//    apprentissageImage.apprendre_base(100000, 1);
//    std::cout << "\n Nombre de bons : " << apprentissageImage.evaluer();

}

void printInputs() {

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

}
