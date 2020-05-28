//
// Created by DiKeLa M'Babane on 21/05/2020.
//

#include "Perceptron.h"
#include <cstdlib>
#include <iostream>

/**
 * @param inputSize la taille de l'input (ex: 4 pour les fleurs, 784 pour les images)
 * @param funcActivation (pointeur pour fonction d'activation commune à tous les perceptrons)
 * @param labelPerceptron le label du perceptron
 */
Perceptron::Perceptron(int inputSize, Fonction_activation *funcActivation, char labelPerceptron) {
    int min = -1, max = 1;
    int randNum = 0;
    for (int i = 0; i < inputSize + 1; i++) {
        randNum = rand() % (max - min + 1) + min;
        this->poids.push_back(randNum);
    }

    for (int i = 0; i < this->poids.size(); ++i)
        std::cout << this->poids.at(i) << ' ';

    this->activation = funcActivation;
    this->label = labelPerceptron;
    this->delta = 0;
}

double Perceptron::get_poids(int indice) {
    return this->poids.at(indice);
}


double Perceptron::forward(Input &input) {
    double produitScalaire = 0, resultForward = 0;
    produitScalaire += this->poids.at(0); // w0
    for (int i = 1; i < this->poids.size(); i++) {
        produitScalaire += input[i] * this->poids.at(i); // somme des xi * wi
    }
    resultForward = this->activation->operator()(produitScalaire); // phi(w0+somme des xi*wi)
    return resultForward;
}

double Perceptron::calcul_delta(Input &input) {
    double calculDelta = 0;
    double produitScalaire = 0, result1 = 0;
    produitScalaire += this->poids.at(0); // w0

    for (int i = 1; i < this->poids.size(); i++) {
        produitScalaire += input[i] * this->poids.at(i); // somme des xi * wi
    }

    std::cout << "produitScalaire : " << produitScalaire << "\n";
    result1 = this->activation->prim(produitScalaire); // phi'(w0+somme des xi*wi)

    calculDelta = result1 * (forward(input) - input.get_label());
    this->delta = calculDelta;

    return calculDelta;
}

double Perceptron::get_delta() {
    return this->delta;
}

void Perceptron::backprop(Input &input, double mu) {
    this->poids[0] = this->poids[0] - mu * get_delta();
    for (int i = 1; i < this->poids.size(); i++) {
        this->poids[i] = this->poids[i] - mu * input[i] * get_delta();
    }
}
