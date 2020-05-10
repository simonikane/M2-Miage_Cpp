/**
* Ces classes permettent de charger les inputs
**/
// Fonction permettant d'acceder à toutes les informations input
class Input{

  public:
    //Input(char label);
    virtual double& operator[](int i);// permet d'accéder à une valeur du tableau
    char get_label();// Renvoie le label de l'input
    ~Input();

  private:
    char label;// le label de l'input
};

//La fonction hérite de la fonction Input
// Stocke la courbe descriptive des fleurs sous la forme d'un tableau de 4 réels
/*
  trois type de fleurs à 4 variable
  En tout 150 descriptions ( les 4 réels et le label)
*/
class Iris: public Input{
  public:
    Iris(int indice);//charge la description de la fleur et son label
    double& operator[](int i);
    //get_label deja defini
  private:
};

/**
* Permet de stocker les images en noir et blanc
*Les images sont dans MNIST_Training (sotké dans un fichier binaire)
*Les label sont contenus dans trains-label-idx1- (sotké dans un fichier binaire)
*
**/
class Image: public Innput{

  public:
    Image(int i);//constructeur indice i correspondant à l'indice de l'image
    double& operator[](int i);//Renvoie le niveau de gris du pixel correspondant
    //get_label deja utilisé dans Input même signature donc pas bésoin de le redefinir
  private:

};
