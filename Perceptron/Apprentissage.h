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
    int randNum = 0;
    Input *input1;
    //Iris *iris1;
    for (int i = 0; i < nbIterations; i++) {
        randNum = rand() % nbInput;
        //input1 = new classInput(randNum);
        input1 = new classInput(randNum);
        std::cout << "iteration " << i << "\n";
        this->reseauNeurones->apprentissage(*input1, mu);
    }
}

template<class classInput, int nbInput>
int Apprentissage<classInput, nbInput>::evaluer() {
    int nbCorrectInput = 0;
    Input *in;

    char old, back;
    for (int i = 0; i < nbInput; i++) {
        in = new classInput(i);
        old = in->get_label();
        back = reseauNeurones->evaluation(*in);
        //if (in->get_label() == reseauNeurones->evaluation(*in)) {
        if (old == back) {
            //std::cout << "in->get_label() : " << in->get_label() << "|| reseauNeurones->evaluation(*in) : "
            //        << static_cast<unsigned>(reseauNeurones->evaluation(*in)) << "\n";
            nbCorrectInput++;
        }
        std::cout << "old " << static_cast<unsigned>(old) << " || back : " << static_cast<unsigned>(back) << "\n";
//        std::cout << (old == back);
    }
    return nbCorrectInput;
}


#endif //PROJET_CPP_APPRENTISSAGE_H
