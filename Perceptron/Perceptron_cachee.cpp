//
// Created by CRYSTA on 29/05/2020.
//

#include "Perceptron_cachee.h"

#include <utility>

Perceptron_cachee::Perceptron_cachee(int inputSize, Fonction_activation *fonctionActivation, char labelPerceptron,
                                     std::vector<Perceptron *> pPerceptronsCoucheSortie) : Perceptron(inputSize,
                                                                                                      fonctionActivation,
                                                                                                      labelPerceptron) {
    this->pPerceptronsCoucheSortie = std::move(pPerceptronsCoucheSortie);
}

double Perceptron_cachee::calcul_delta(Input &input) {
    double calculDelta = 0;
    double produitScalaire = get_poids(0), result1 = 0;
    for (int i = 1; i < poids.size(); i++) {
        produitScalaire += poids.at(i) * input[i - 1];
    }
    produitScalaire = fonction_activation->prim(produitScalaire);
    double produitScalaire2 = 0;
    for (int j = 0; j < pPerceptronsCoucheSortie.size(); j++) {
        produitScalaire2 +=
                (*pPerceptronsCoucheSortie.at(j)).get_delta() * (*pPerceptronsCoucheSortie.at(j)).get_poids(j);
    }
    calculDelta = produitScalaire * produitScalaire2;
    return calculDelta;
}

void Perceptron_cachee::backprop(Input &input, double mu) {
    poids.at(0) = poids.at(0) - mu * get_delta();
    for (int i = 1; i < poids.size(); i++) {
        poids.at(i) = poids.at(i) - mu * get_delta() * input[i - 1];
    }
}
