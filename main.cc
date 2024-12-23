#include "jeu.hh"

const int INITIAL_NB_EMPLOYEES = 1;
const float INITIAL_MONEY = 100;

int main() {
  // Initialisation des variables de base
  Jeu jeu(INITIAL_NB_EMPLOYEES, INITIAL_MONEY);
  jeu.run();
  return 0;
}
