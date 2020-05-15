//
// Created by CRYSTA on 10/05/2020.
//

#include "Image.h"
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <sstream>
#include <vector>

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
        /*
        cout << "\nReading imageFile bytes...\n";
        for (int i=0; i<784; i++) {
            cout << buffer[i] << "\n";
        } */        // à montrer à Laye et Sim
        int compteurPixel = 0;
        cout << "\nThe number of bytes read is " << imageFile.gcount();
        for (int i = 0; i < 28; i++) {
            for (int j = 0; j < 28; j++) {
                this->pixel[i][j] = buffer[compteurPixel++];
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
        cout << "\nSuccessfully opened file train-labels.idx1-ubyte";
        char buffer[1]; // 28 * 28 = 784 pixels
        imageFile.seekg(8, ios::beg);
        imageFile.read(buffer, 1); // mettre les octets dans buffer[].. montrer pour 785
        // this->set_label(buffer[0]);
    } else {
        cerr << "\nERREUR : impossible d'ouvrir le fichier " << train_labels_filePath << "\n";
    }
    imageFile.close();

}

double Image::operator[](int indice) {
    return 0;
}

