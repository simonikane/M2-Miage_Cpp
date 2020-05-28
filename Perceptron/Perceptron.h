//
// Created by DiKeLa M'Babane on 21/05/2020.
//

#ifndef PROJET_CPP_PERCEPTRON_H
#define PROJET_CPP_PERCEPTRON_H


#include "Fonction_activation.h"
#include "../Input/Input.h"

#include <vector>

class Perceptron {

private:
    char label;// avant c'était categorie
    std::vector<double> poids;
    Fonction_activation *activation;
    double delta;

public:
    Perceptron(int inputSize, Fonction_activation *funcActivation, char labelPerceptron);

    double get_poids(int indice);

    double forward(Input &input);

    double calcul_delta(Input &input);

    double get_delta();

    void backprop(Input &input, double mu);// Definition du poids

};


#endif //PROJET_CPP_PERCEPTRON_H
