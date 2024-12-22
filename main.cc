#include "company.hh"
#include "jeu.hh"
#include "metal.hh"
#include "plastic.hh"
#include <iostream>

const int INITIAL_NB_EMPLOYEES = 1;
const float INITIAL_MONEY = 100;

int main() {
  // Initialisation des variables de base
  Jeu jeu(INITIAL_NB_EMPLOYEES, INITIAL_MONEY);
  jeu.run();
  return 0;
}
