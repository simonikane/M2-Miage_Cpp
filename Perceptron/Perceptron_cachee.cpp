//
// Created by CRYSTA on 29/05/2020.
//

#include "Perceptron_cachee.h"

#include <utility>

Perceptron_cachee::Perceptron_cachee(int inputSize, Fonction_activation *fonctionActivation, char labelPerceptron,
                                     std::vector<Perceptron *> pPerceptronsCoucheSortie) : Perceptron(inputSize,
                                                                                                      fonctionActivation,
                                                                                                      labelPerceptron) {
    this->pPerceptronsCoucheSortie = pPerceptronsCoucheSortie;
}

double Perceptron_cachee::calcul_delta(Input &input) {
    double calculDelta = 0;
    double produitScalaire = get_poids(0), result1 = 0; // deltaS = wS0
    for (int i = 1; i < poids.size() - 1; i++) {
        produitScalaire += poids.at(i) * input[i]; // delta = wS0 + somme des wSi * xi
    }
    produitScalaire = fonction_activation->prim(produitScalaire); // delta = phi(wS0 + somme des wSi * xi)



    double produitScalaire2 = 0;
    for (int j = 1; j < pPerceptronsCoucheSortie.size(); j++) {
        // somme des deltaL * les poids
        produitScalaire2 +=
                (*pPerceptronsCoucheSortie.at(j)).get_delta() * (*pPerceptronsCoucheSortie.at(j)).get_poids(j);
    }
    calculDelta = produitScalaire * produitScalaire2;
    return calculDelta;
}

void Perceptron_cachee::backprop(Input &input, double mu) {
    calcul_delta(input);
    for (int i = 1; i < poids.size(); i++) {
        this->poids[i] = (i == 0) ? this->poids[i] - mu * get_delta() : this->poids[i] = this->poids[i] -
                                                                                         mu * input[i] * get_delta();
    }
}
