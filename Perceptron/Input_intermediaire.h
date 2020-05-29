//
// Created by CRYSTA on 29/05/2020.
//

#ifndef PROJET_CPP_INPUT_INTERMEDIAIRE_H
#define PROJET_CPP_INPUT_INTERMEDIAIRE_H


#include <vector>
#include "../Input/Input.h"

class Input_intermediaire : public Input {
public:
    explicit Input_intermediaire(char label);

    void add(double reel);

    double operator[](int indiceCoordonneeVecteur) override;

private:
    std::vector<double> reels;

};


#endif //PROJET_CPP_INPUT_INTERMEDIAIRE_H
