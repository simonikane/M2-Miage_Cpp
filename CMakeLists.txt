cmake_minimum_required(VERSION 3.15)
project(Projet_CPP)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projet_CPP main.cpp Input/Input.cpp Input/Input.h Input/Iris.cpp Input/Iris.h Input/Image.cpp Input/Image.h Perceptron/Fonction_activation.cpp Perceptron/Fonction_activation.h Perceptron/Tanh.cpp Perceptron/Tanh.h Perceptron/Sigmoide.cpp Perceptron/Sigmoide.h Perceptron/Perceptron.cpp Perceptron/Perceptron.h Perceptron/NN1.cpp Perceptron/NN1.h Perceptron/Apprentissage.h Perceptron/Perceptron_cachee.cpp Perceptron/Perceptron_cachee.h Perceptron/Input_intermediaire.cpp Perceptron/Input_intermediaire.h Perceptron/NN2.cpp Perceptron/NN2.h)