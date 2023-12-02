Oui, il est possible d'avoir un enum dont les valeurs sont des entiers arbitraires et de faire une fonction qui renvoie la chaîne associée à chaque valeur de l'enum. Par exemple, avec une chaîne "Voyelles" qui contient toutes les voyelles, et une chaîne "Consonnes" qui contient toutes les consonnes, on pourrait faire quelque chose comme ceci :

```cpp
#include <iostream>
#include <string>

// Définition de l'enum
enum Lettre {
  VOYELLES = 1,
  CONSONNES = 2
};

// Définition de la fonction
std::string getChaine(Lettre l) {
  switch (l) {
    case VOYELLES:
      return "AEIOUY";
    case CONSONNES:
      return "BCDFGHJKLMNPQRSTVWXZ";
    default:
      return "";
  }
}

// Exemple d'utilisation
int main() {
  Lettre l = VOYELLES;
  std::cout << getChaine(l) << std::endl; // affiche AEIOUY
  l = CONSONNES;
  std::cout << getChaine(l) << std::endl; // affiche BCDFGHJKLMNPQRSTVWXZ
  return 0;
}
```