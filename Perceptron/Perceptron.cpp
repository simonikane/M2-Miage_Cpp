//
// Created by DiKeLa M'Babane on 21/05/2020.
//

#include "Perceptron.h"

Perceptron::Perceptron(int inputSize, Fonction_activation *funcActivation, char labelPerceptron) {
    //initialisation des poids de manière aléatoire ( {-1, 1})

}

double Perceptron::get_poids(int indice) {
    return this->poids.at(indice);
}

double Perceptron::forward(Input &input) {
    return 0;
}

double Perceptron::calcul_delta(Input &input) {
    return 0;
}

double Perceptron::get_delta() {
    return this->delta;
}

void Perceptron::backprop(Input &input, double mu) {

}
