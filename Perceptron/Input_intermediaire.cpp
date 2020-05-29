//
// Created by CRYSTA on 29/05/2020.
//

#include "Input_intermediaire.h"

Input_intermediaire::Input_intermediaire(char label) {
    this->set_label(label);
}

double Input_intermediaire::operator[](int indiceCoordonneeVecteur) {
    return this->reels.at(indiceCoordonneeVecteur);
}

void Input_intermediaire::add(double reel) {
    reels.push_back(reel);
}
