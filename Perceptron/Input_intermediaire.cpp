//
// Created by CRYSTA on 29/05/2020.
// Sert à stocker la valeur des inputs intermédiaires évalués (la première couche)

#include "Input_intermediaire.h"

/** @brief Constructeur de la classe
   @param char label : affecte le label à l'input
   */
Input_intermediaire::Input_intermediaire(char label) {
    this->set_label(label);
}

/** @brief Operateur [] qui permet de récupérer tel input_intermédiaire à tel emplacement
   @param int indiceCoordonneeVecteur : l'indice du tableau
   @return bool : input désiré */
double Input_intermediaire::operator[](int indiceCoordonneeVecteur) {
    return this->reels.at(indiceCoordonneeVecteur);
}

/** @brief Rajouter la valeur dans le vecteur
   @param double reel : parametre à ajouter dans le vecteur*/
void Input_intermediaire::add(double reel) {
    reels.push_back(reel);
}
