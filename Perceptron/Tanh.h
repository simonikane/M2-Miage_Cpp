//
// Created by DiKeLa M'Babane on 19/05/2020.
//

#ifndef PROJET_CPP_TANH_H
#define PROJET_CPP_TANH_H
#include "Fonction_activation.h"

/***
 * Cette classe permet de calculer la tangente
 */
class Tanh : public Fonction_activation{

    private:
    public:
        Tanh();
        double operator()(double val);
        double prim(double val);

};


#endif //PROJET_CPP_TANH_H
