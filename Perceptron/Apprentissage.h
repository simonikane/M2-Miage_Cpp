//
// Created by CRYSTA on 27/05/2020.
//

#ifndef PROJET_CPP_APPRENTISSAGE_H
#define PROJET_CPP_APPRENTISSAGE_H


#include "NN1.h"
/**
 *
 * @tparam Input Iris ou Image
 * @tparam nbInput 150 pour Iris et 60 000 pour Images
 */
template<class Input, int nbInput>
class Apprentissage {
public:
    Apprentissage(NN1 *nn1);

    void apprendre_base(int nbIterations, double mu);

    int evaluer();

private:
    NN1 *reseauNeurones;
};

template<class input, int nbInput>
Apprentissage<input, nbInput>::Apprentissage(NN1 *reseauNeurones) {
    this->reseauNeurones = reseauNeurones;
}

template<class classInput, int nbInput>
void Apprentissage<classInput, nbInput>::apprendre_base(int nbIterations, double mu) {
    int min = 0, max = nbInput;
    int randNum = 0;
    Input *input1;

    for (int i = 0; i < nbIterations; i++) {
        randNum = rand() % (max - min + 1) + min;
        input1 = new classInput(randNum);
        this->reseauNeurones->apprentissage(input1, mu);
    }
}

template<class Input, int nbInput>
int Apprentissage<Input, nbInput>::evaluer() {
    int nbCorrectInput = 0;
    Input *input1;

    for (int i = 0; i < nbInput; i++) {
        if (Input(i)->get_label() == reseauNeurones->evaluation(input1));
        nbCorrectInput++;
    }
    return nbCorrectInput;
}


#endif //PROJET_CPP_APPRENTISSAGE_H
