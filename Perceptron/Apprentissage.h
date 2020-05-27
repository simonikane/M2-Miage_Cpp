//
// Created by CRYSTA on 27/05/2020.
//

#ifndef PROJET_CPP_APPRENTISSAGE_H
#define PROJET_CPP_APPRENTISSAGE_H


#include "NN1.h"

class Apprentissage {
public:
    Apprentissage(NN1 *nn1);

    void apprendre_base(int iterations, double mu);

    int evaluer();
};


#endif //PROJET_CPP_APPRENTISSAGE_H
