//
// Created by DiKeLa M'Babane on 19/05/2020.
//

#ifndef PROJET_CPP_FONCTION_ACTIVATION_H
#define PROJET_CPP_FONCTION_ACTIVATION_H


class Fonction_activation {

    private:

    public:
        virtual double operator()(double val) = 0;
        virtual double prim(double val) = 0;

};


#endif //PROJET_CPP_FONCTION_ACTIVATION_H
