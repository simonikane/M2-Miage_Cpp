# M2-Miage_Cpp
Projet C++ 2020 Miage M2

###### **Résumé**

Nous avons choisi le projet sur l'implémentation de réseau de neurones. 
Le projet que nous avons réalisé compile et s'execute.
Notre algorithme de prédiction renvoie souvent un pourcentage de réussite de 33%. L'algorithme est à perfectionner.

###### **Execution du projet**

Pour executer le code, s'assurer d'adapter le chemin de lecture des fichiers en fonction de sa machine.
Dans `Input.h`, modifier la variable `PROJECT_FOLDER_PATH` pour la remplacer avec le chemin de votre machine.

Dans `Iris.cpp` et `Image.cpp`, décommenter la ligne qui correspond à votre OS : 
 
 Exemple Iris.cpp :
 
 `Pour un Windows ou Linux`
 
 `string pathFolder = PROJECT_FOLDER_PATH + "\\Data_Source\\iris_training\\"`

 `Pour un MacOS`
 
 `string pathFolder = PROJECT_FOLDER_PATH + "/Data_Source/iris_training/";`
