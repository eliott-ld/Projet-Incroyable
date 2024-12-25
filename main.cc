#include "jeu.hh"

#include <ctime>
#include <iostream>
#include <thread>
#include <unistd.h>

const int INITIAL_NB_EMPLOYEES = 1;
const float INITIAL_MONEY = 100;
const bool DEV_MODE = true;

using namespace std;
int main() {
  // Initialisation des variables de base
  Jeu jeu(INITIAL_NB_EMPLOYEES, INITIAL_MONEY, DEV_MODE);
  jeu.run();
  return 0;
}

