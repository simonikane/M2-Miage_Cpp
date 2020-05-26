//
// Created by CRYSTA on 10/05/2020.
//

#include "Image.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <sstream>
#include <vector>
#include <bitset>
#include <cmath>

using namespace std;


Image::Image(int indice) : Input() {
    //string pathFolder = "C:\\Users\\DiKeLa M'Babane\\Documents\\M2IF DAUPHINE\\M2-C++\\M2-Miage_Cpp\\Data_Source\\iris_training\\";
    string MNIST_folderPath = PROJECT_FOLDER_PATH + "Data_Source\\MNIST_training\\";
    string training_filePath = MNIST_folderPath.append("training" + to_string(indice));

    // Partie traitement des data training
    ifstream imageFile(training_filePath, ios::in | ios::binary);
    std::cout << training_filePath;
    if (imageFile) {
        // cout << "\nSuccessfully opened file training" << to_string(indice);
        char buffer[784]; // 28 * 28 = 784 pixels
        imageFile.seekg(1078, ios::beg);
        imageFile.read(buffer, 784); // mettre les octets dans buffer[].. montrer pour 785

        cout << "\nThe number of bytes read is " << imageFile.gcount();
        int compteurPixel = 0;
        for (int i = 0; i < 28; i++) {
            for (int j = 0; j < 28; j++) {
                this->pixel[i][j] = buffer[compteurPixel];
                cout << "\n" << static_cast<signed>(buffer[compteurPixel]);
                // cout << "\n" << std::bitset<8>(buffer[compteurPixel]);
                compteurPixel++;
            }
        }
        if (!imageFile) {
            cerr << "\nAn error occurred! The number of bytes read is " << imageFile.gcount();
            imageFile.clear();
        }
    } else {
        cerr << "\nERREUR : impossible d'ouvrir le fichier " << training_filePath << "\n";
    }
    imageFile.close();

    // Partie traitement des train labels
    string train_labels_folderPath = PROJECT_FOLDER_PATH + "Data_Source\\train-labels-idx1-ubyte\\";
    string train_labels_filePath = train_labels_folderPath.append("train-labels.idx1-ubyte");

    ifstream train_labelsFile(train_labels_filePath, ios::in | ios::binary);

    if (train_labelsFile) {
        cout << "\n";
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

double Image::operator[](int indice) {
    int indiceLignes = 0, indiceColonnes = 0;
    indiceLignes = indice / 28;
    indiceColonnes = indice % 28;
    // cout << "\nIndice Lignes : " << indiceLignes << ", Indice Colonnes : " << indiceColonnes << "\n";
    return (double) this->pixel[indiceLignes][indiceColonnes];
}
