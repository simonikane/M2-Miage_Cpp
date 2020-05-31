//
// Created by CRYSTA on 29/05/2020.
//  Permet de définir la structure d'un perceptron multicouche avec couche cachée

#ifndef PROJET_CPP_PERCEPTRON_CACHEE_H
#define PROJET_CPP_PERCEPTRON_CACHEE_H


#include "Perceptron.h"


class Perceptron_cachee : public Perceptron {
public:
    Perceptron_cachee(int inputSize, Fonction_activation *fonctionActivation, char labelPerceptron,
                      std::vector<Perceptron *> perceptrons);

    double calcul_delta(Input &input);

    void backprop(Input &input, double mu);

private:
    std::vector<Perceptron *> pPerceptronsCoucheSortie;
};


#endif //PROJET_CPP_PERCEPTRON_CACHEE_H
