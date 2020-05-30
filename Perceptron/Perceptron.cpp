//
// Created by DiKeLa M'Babane on 21/05/2020.
//

#include "Perceptron.h"
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <typeinfo>
#include <cstring>

/**
 * @param inputSize la taille de l'input (ex: 4 pour les fleurs, 784 pour les images)
 * @param funcActivation (pointeur pour fonction d'activation commune à tous les perceptrons)
 * @param labelPerceptron le label du perceptron
 */
Perceptron::Perceptron(int inputSize, Fonction_activation *funcActivation, char labelPerceptron) {
    int min = -1, max = 1;
    int randNum = 0;
    for (int i = 0; i < inputSize + 1; i++) {
        randNum = rand() % (max - min + 1) + min; // -1 0 ou 1
        this->poids.push_back(randNum);
    }
    this->fonction_activation = funcActivation;
    this->label = labelPerceptron;
    this->delta = 0;
}

double Perceptron::get_poids(int indice) {
    return this->poids.at(indice);
}


double Perceptron::forward(Input &input) {
    double produitScalaire = this->poids.at(0), resultForward = 0; // y = w0
    for (int i = 1; i < this->poids.size() - 1; i++) {
        produitScalaire += input[i] * this->poids.at(i); // y = w0 + somme des xi * wi
    }
    resultForward = this->fonction_activation->operator()(produitScalaire); // y = phi(w0+somme des xi*wi)
    // resultForward = resultForward < 0.5 ? 0 : 1;
    return resultForward;
}

double Perceptron::calcul_delta(Input &input) {
    double calculDelta = 0;
    double produitScalaire = this->poids.at(0), result1 = 0;
    for (int i = 1; i < this->poids.size() - 1; i++) {
        produitScalaire += input[i] * this->poids.at(i); // somme des xi * wi
    }
    result1 = this->fonction_activation->prim(produitScalaire); // phi'(w0+somme des xi*wi)
    calculDelta = result1 * (forward(input) - input.get_label());
    this->delta = calculDelta;
    // calculDelta = calculDelta < 0.5 ? 0 : 1;
    return calculDelta;
}

double Perceptron::get_delta() {
    return this->delta;
}

void Perceptron::backprop(Input &input, double mu) {
    calcul_delta(input);
    for (int i = 0; i < this->poids.size() - 1; i++) {
        this->poids[i] = (i == 0) ? this->poids[i] - mu * get_delta() : this->poids[i] = this->poids[i] -
                                                                                         mu * input[i] * get_delta();
    }
}
