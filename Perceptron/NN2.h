//
// Created by CRYSTA on 29/05/2020.
// Version améliorée du réseau de neurones NN1. Rajout d'une couche intermédiaire .

#ifndef PROJET_CPP_NN2_H
#define PROJET_CPP_NN2_H


#include <vector>
#include "../Input/Input.h"
#include "Perceptron_cachee.h"

class NN2 {
private:
    std::vector<Perceptron *> coucheSortie;
    std::vector<Perceptron_cachee> coucheCachee;
public:
    NN2(int inputSize, int nbCategories, int nbPerceptronsCaches);

    char evaluation(Input &input);

    void apprentissage(Input &input, double mu);
};


#endif //PROJET_CPP_NN2_H
