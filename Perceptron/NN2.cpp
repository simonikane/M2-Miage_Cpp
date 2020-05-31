//
// Created by CRYSTA on 29/05/2020.
// Version améliorée du réseau de neurones NN1. Rajout d'une couche intermédiaire .

#include <iostream>
#include "NN2.h"
#include "Sigmoide.h"
#include "Input_intermediaire.h"

/**
 * @brief Constructeur de la classe
 * @param int inputSize : ex: 784
 * @param int nbCategories :  ex: 3
 * @param int nbPerceptrons : ex: 3
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

/**
 * @brief La fonction d'évaluation permet d'assimilier un input à un label. Cette methode renvoie la correspondance à un label (valeur entre 0 et 1)
 * @param Input input : l'input en entrée
 * @return char: le label correspondant à la plus grande valeur retournée par l'un des perceptrons
 */

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
 * @brief Application de l'algorithme d'apprentissage sur un input
 * @param input &input : (xj, yj)
 * @param double mu : pas du gradient
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
