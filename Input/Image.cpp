//
// Created by CRYSTA on 10/05/2020.
//La classe Image s'occupe de représenter une image depuis le dataset "MNIST_training
//
//

#include "Image.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/**
   @brief Permet la lecture des images depuis le dataset et la génération de Image
   @param int indice : indice du tableau d'images
   */

Image::Image(int indice) : Input() {

    //Pour un Windows ou Linux
    string MNIST_folderPath = PROJECT_FOLDER_PATH + "\\Data_Source\\MNIST_training\\";

    //Pour un MacOS
    //string MNIST_folderPath = PROJECT_FOLDER_PATH + "/Data_Source/iris_training/";

    string training_filePath = MNIST_folderPath.append("training" + to_string(indice));

    ifstream imageFile(training_filePath, ios::in | ios::binary);
    if (imageFile) {
        char buffer[784]; // 28 * 28 = 784 pixels
        imageFile.seekg(1078, ios::beg);
        imageFile.read(buffer, 784); // mettre les octets dans buffer[].. montrer pour 785

        int compteurPixel = 0;
        for (int i = 0; i < 28; i++) {
            for (int j = 0; j < 28; j++) {
                this->pixel[i][j] = buffer[compteurPixel];
                compteurPixel++;
            }
        }
        if (!imageFile) {
            cerr << "\n An error occurred! The number of bytes read is " << imageFile.gcount();
            imageFile.clear();
        }
    } else {
        cerr << "\nERREUR : impossible d'ouvrir le fichier " << training_filePath << "\n";
    }
    imageFile.close();

    // Partie traitement des train labels

    //Pour un Windows ou Linux
    //string train_labels_folderPath = PROJECT_FOLDER_PATH + "Data_Source\\train-labels-idx1-ubyte\\";

    //Pour un MacOS
    string train_labels_folderPath = PROJECT_FOLDER_PATH + "/Data_Source/train-labels-idx1-ubyte/";

    string train_labels_filePath = train_labels_folderPath.append("train-labels.idx1-ubyte");

    ifstream train_labelsFile(train_labels_filePath, ios::in | ios::binary);

    if (train_labelsFile) {
        char buffer[1]; // 28 * 28 = 784 pixels
        train_labelsFile.seekg(8 + indice, ios::beg); // on se positionne au 8ème octet
        train_labelsFile.read(buffer,
                              1); // on lit le 8+ième octet (par exemple, pour l'indice 5 on lira le 13ème octet du fichier ubyte)
        this->set_label(buffer[0]); // on met le 8+ième octet dans le label
    } else {
        cerr << "\nERREUR : impossible d'ouvrir le fichier " << train_labels_filePath << "\n";
    }
    train_labelsFile.close();

}

/** @brief L'opérateur [] qui permet d'accéder au pixel désiré d'une Image
   @param int indice : l'indice du pixel désiré
   @return double  : le pixel souhaité */

double Image::operator[](int indice) {
    int indiceLignes = 0, indiceColonnes = 0;
    indiceLignes = indice / 28;
    indiceColonnes = indice % 28;
    return (double) this->pixel[indiceLignes][indiceColonnes];
}
