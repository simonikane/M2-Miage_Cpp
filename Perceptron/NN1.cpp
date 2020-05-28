//
// Created by CRYSTA on 27/05/2020.
//

#include <iostream>
#include "NN1.h"
#include "Perceptron.h"

/**
 *
 * @param inputSize la taille des input (4 pour fleurs et 784 pour images)
 * @param nbCategories le nombre de catégories et donc le nombre de perceptrons
 */
NN1::NN1(int inputSize, int nbCategories) {
    Fonction_activation *fonctionActivation = nullptr;
    this->inputSize = inputSize;
    this->nbCategories = nbCategories;
    for (int i = 0; i < nbCategories; i++) {
        Perceptron perceptron = Perceptron(inputSize, fonctionActivation, i);
        this->reseauNeurones.push_back(perceptron);
    }
}

/**
 * @param input l'input
 * @return le label correspoindant à la plus grande valeur retournée par l'un des perceptrons
 */
char NN1::evaluation(Input &input) {
    double newForward = 0, max = -1;
    char labelMax = 0;
    for (int i = 0; i < reseauNeurones.size(); i++) {
        newForward = reseauNeurones.at(i).forward(input);
        if (newForward > max) {
            max = newForward;
            labelMax = (char) i;
        }
    }
    return labelMax;
}

/**
 * application de l'algorithme d'apprentissage pour l'input
 */
void NN1::apprentissage(Input &input, double mu) {
    for (Perceptron perceptron : reseauNeurones)
        perceptron.backprop(input, mu);
}
