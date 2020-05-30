//
// Created by CRYSTA on 29/05/2020.
//

#include <iostream>
#include "NN2.h"
#include "Sigmoide.h"
#include "Input_intermediaire.h"

/**
 *
 * @param inputSize ex: 784
 * @param nbCategories ex: 3
 * @param nbPerceptrons ex: 3
 */
NN2::NN2(int inputSize, int nbCategories, int nbPerceptronsCaches) {
    Fonction_activation *fonctionActivation = new Sigmoide();
    for (int i = 0; i < nbCategories; i++) {
        Perceptron *perceptron = new Perceptron(nbPerceptronsCaches, fonctionActivation, i);
        this->coucheSortie.push_back(perceptron);
    }
    for (int j = 0; j < nbPerceptronsCaches; j++) {
        Perceptron_cachee perceptron_cachee = Perceptron_cachee(inputSize, fonctionActivation, j, this->coucheSortie);
        this->coucheCachee.push_back(perceptron_cachee);
    }
}

char NN2::evaluation(Input &input) {
    char labelMax;
    double max = -1;
    Input_intermediaire inputIntermediaire = Input_intermediaire(input.get_label());
    for (int i = 0; i < coucheCachee.size(); i++) {
        inputIntermediaire.add(coucheCachee.at(i).forward(input));
    }

    for (int j = 0; j < coucheSortie.size(); j++) {
        double newForward = coucheSortie.at(j)->forward(inputIntermediaire);
        if (newForward > max) {
            max = newForward;
            labelMax = j;
        }
    }

    return labelMax;
}

/**
 * input : (xj, yj)
 * mu : pas du gradient
 */
void NN2::apprentissage(Input &input, double mu) {
    Input_intermediaire inputIntermediaire = Input_intermediaire((input).get_label());
    // Ajout des A(x) à inputIntermediaire
    for (int i = 0; i < coucheCachee.size(); i++) {
        inputIntermediaire.add(coucheCachee.at(i).forward(input));
    }

    // Calcul du DeltaL des perceptrons de la couche de sortie
    for (int j = 0; j < coucheSortie.size(); j++) {
        coucheSortie.at(j)->calcul_delta(inputIntermediaire);
    }
    // Calcul du DeltaS des perceptrons de la couche de sortie
    for (int k = 0; k < coucheCachee.size(); k++) {
        coucheCachee.at(k).calcul_delta(input);
    }
    for (int l = 0; l < coucheCachee.size(); l++) {
        coucheCachee.at(l).backprop(input, mu);
    }
    for (int m = 0; m < coucheSortie.size(); m++) {
        coucheSortie.at(m)->backprop(inputIntermediaire, mu);
    }
}
