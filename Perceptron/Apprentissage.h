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
    Apprentissage(NN1 *reseau);

    void apprendre_base(int nbIterations, double mu);

    int evaluer();

private:
    NN1 *reseauNeurones;
};

template<class input, int nbInput>
Apprentissage<input, nbInput>::Apprentissage(NN1 *reseau) {
    this->reseauNeurones = reseau;
}

template<class classInput, int nbInput>
void Apprentissage<classInput, nbInput>::apprendre_base(int nbIterations, double mu) {
    int min = 0, max = nbInput;
    int randNum = 0;
    //Input input1;
    Iris *iris1;
    for (int i = 0; i < nbInput; i++) {
        randNum = rand() % (max - min + 1) + min;
        //input1 = new classInput(randNum);
        iris1 = new Iris(i);
        this->reseauNeurones->apprentissage(*iris1, mu);
    }
}

template<class classInput, int nbInput>
int Apprentissage<classInput, nbInput>::evaluer() {
    int nbCorrectInput = 0;
    Input *in;
    for (int i = 0; i < nbInput; i++) {
        in = new classInput(i);
        if (in->get_label() == reseauNeurones->evaluation(*in)) {
            nbCorrectInput++;
        }
        std::cout << "in->get_label() : " << in->get_label() << "|| reseauNeurones->evaluation(*in) : "
                  << static_cast<unsigned>(reseauNeurones->evaluation(*in)) << "\n";
    }
    return nbCorrectInput;
}


#endif //PROJET_CPP_APPRENTISSAGE_H
