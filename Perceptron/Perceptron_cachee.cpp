//
// Created by CRYSTA on 29/05/2020.
// Permet de définir la structure d'un perceptron multicouche avec couche cachée

#include "Perceptron_cachee.h"

/** @brief Constructeur du perceptron avec couche cachée
   @param int inputSize : Taille de l'input
   @param Fonction_activation *fonctionActivation : la fonction d'activation qu'on décide d'utiliser (Sigmoide ou Tanh)
   @param char labelPerceptron : Le label du perceptron associé
   @param vector<Perceptron *> pPerceptronsCoucheSortie : l'emplacement de sortie de ces perceptrons (va servir d'entrée à la couche suivante)
   @return bool : valeur de retour */

Perceptron_cachee::Perceptron_cachee(int inputSize, Fonction_activation *fonctionActivation, char labelPerceptron,
                                     std::vector<Perceptron *> pPerceptronsCoucheSortie) : Perceptron(inputSize,
                                                                                                      fonctionActivation,
                                                                                                      labelPerceptron) {
    this->pPerceptronsCoucheSortie = pPerceptronsCoucheSortie;
}

/** @brief Evaluation de la fonction 𝛿(1) = 𝜑′ (𝑧(1)) ∑𝑟 𝛿(2)𝑤(2) = 𝜑′ (𝑤(1) + ∑𝑛 𝑤(1)𝑥 ) ∑𝑟 𝛿(2)𝑤(2)
   @param Input &input : L'input en entrée (Iris ou Image)
   @return bool : valeur de retour */
double Perceptron_cachee::calcul_delta(Input &input) {
    double calculDelta = 0;
    double produitScalaire = get_poids(0), result1 = 0; // deltaS = wS0
    for (int i = 1; i < poids.size() - 1; i++) {
        produitScalaire += poids.at(i) * input[i]; // delta = wS0 + somme des wSi * xi
    }
    produitScalaire = fonction_activation->prim(produitScalaire); // delta = phi(wS0 + somme des wSi * xi)



    double produitScalaire2 = 0;
    for (int j = 1; j < pPerceptronsCoucheSortie.size(); j++) {
        // somme des deltaL * les poids
        produitScalaire2 +=
                (*pPerceptronsCoucheSortie.at(j)).get_delta() * (*pPerceptronsCoucheSortie.at(j)).get_poids(j);
    }
    calculDelta = produitScalaire * produitScalaire2;
    return calculDelta;
}


/** @brief Va apprendre les poids à partir des inputs en training
 * @param input : l'input choisi en entrée
 * @param mu : pas du gradient
 */

void Perceptron_cachee::backprop(Input &input, double mu) {
    calcul_delta(input);
    for (int i = 1; i < poids.size(); i++) {
        this->poids[i] = (i == 0) ? this->poids[i] - mu * get_delta() : this->poids[i] = this->poids[i] -
                                                                                         mu * input[i] * get_delta();
    }
}
