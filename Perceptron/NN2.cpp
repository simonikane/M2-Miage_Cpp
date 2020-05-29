//
// Created by CRYSTA on 29/05/2020.
//

#include "NN2.h"
#include "Sigmoide.h"

/**
 *
 * @param inputSize ex: 784
 * @param nbCategories ex: 3
 * @param nbPerceptrons ex: 3
 */
NN2::NN2(int inputSize, int nbCategories, int nbPerceptronsCaches) {
    Fonction_activation *fonctionActivation = new Sigmoide();
    for (int i = 0; i < nbCategories; i++) {
        Perceptron perceptron = Perceptron(inputSize, fonctionActivation, i);
        this->coucheSortie.push_back(&perceptron);
    }
    for (int j = 0; j < nbPerceptronsCaches; j++) {
        Perceptron_cachee perceptron_cachee = Perceptron_cachee(inputSize, fonctionActivation, j, this->coucheSortie);
        this->coucheCachee.push_back(perceptron_cachee);
    }
}

char NN2::evaluation(Input &input) {
    return 0;
}

void NN2::apprentissage(Input &input, double mu) {

}
