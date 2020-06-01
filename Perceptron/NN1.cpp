//
// Created by CRYSTA on 27/05/2020.
// Partie 3 du projet
// Permet de représenter un réseau de neurones sans multicouche cachée (classique)
//

#include <iostream>
#include "NN1.h"
#include "Perceptron.h"
#include "Tanh.h"
#include "Sigmoide.h"

/**
 *
 * @param inputSize la taille des input (4 pour fleurs et 784 pour images)
 * @param nbCategories le nombre de catégories et donc le nombre de perceptrons
 */
NN1::NN1(int inputSize, int nbCategories) {
    Fonction_activation *fonctionActivation = new Sigmoide();
    this->inputSize = inputSize;
    this->nbCategories = nbCategories;
    for (int i = 0; i < nbCategories; i++) {
        Perceptron perceptron = Perceptron(inputSize, fonctionActivation, i);
        this->reseauNeurones.push_back(perceptron);
    }
}

/**
 * @brief La fonction d'évaluation permet d'assimilier un input à un label. Cette methode renvoie la correspondance à un label (valeur entre 0 et 1)
 * @param Input input : l'input en entrée
 * @return char: le label correspondant à la plus grande valeur retournée par l'un des perceptrons
 */
char NN1::evaluation(Input &input) {
    double max = -1;
    char labelMax = 0;
    for (int i = 0; i < reseauNeurones.size(); i++) {
        double newForward = reseauNeurones.at(i).forward(input);
        // affichage des a(x) calculés
        // std::cout << "perceptron " << i << "|| newForward " << newForward << "\n";
        if (newForward >= max) {
            max = newForward;
            labelMax = i;
        }
    }
    return labelMax;
}

/**
 * @brief de l'algorithme d'apprentissage pour l'input
 * @param Input : l'input en entrée
 * @param double : pas du gradient
 */
void NN1::apprentissage(Input &input, double mu) {
    for (Perceptron perceptron : reseauNeurones)
        perceptron.backprop(input, mu);
}
