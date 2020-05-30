//
// Created by CRYSTA on 27/05/2020.
//

#ifndef PROJET_CPP_APPRENTISSAGE_H
#define PROJET_CPP_APPRENTISSAGE_H


#include "NN1.h"
#include "NN2.h"

/**
 *
 * @tparam Input Iris ou Image
 * @tparam nbInput 150 pour Iris et 60 000 pour Images
 */
template<class Input, int nbInput, class NN>
class Apprentissage {
public:
    Apprentissage(NN *reseau);

    void apprendre_base(int nbIterations, double mu);

    int evaluer();

private:
    NN *reseauNeurones;
};

template<class input, int nbInput, class NN>
Apprentissage<input, nbInput, NN>::Apprentissage(NN *reseau) {
    this->reseauNeurones = reseau;
}

template<class classInput, int nbInput, class NN>
void Apprentissage<classInput, nbInput, NN>::apprendre_base(int nbIterations, double mu) {
    int randNum = 0;
    Input *input1;
    //Iris *iris1;
    for (int i = 1; i < nbIterations; i++) {
        randNum = rand() % nbInput;
        input1 = new classInput(randNum);
        this->reseauNeurones->apprentissage(*input1, mu);
    }
}

template<class classInput, int nbInput, class NN>
int Apprentissage<classInput, nbInput, NN>::evaluer() {
    int nbCorrectInput = 0;
    Input *in;

    char inputLabel, predictedLabel;
    for (int i = 0; i < nbInput; i++) {
        in = new classInput(i);
        inputLabel = in->get_label();
        predictedLabel = reseauNeurones->evaluation(*in);
        if (inputLabel == predictedLabel) {
            nbCorrectInput++;
        }
        // std::cout << "inputLabel " << static_cast<unsigned>(inputLabel) << " || predictedLabel : " << static_cast<unsigned>(predictedLabel) << "\n";
    }
    return nbCorrectInput;
}


#endif //PROJET_CPP_APPRENTISSAGE_H
