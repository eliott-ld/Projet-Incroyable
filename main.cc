#include "company.hh"
#include "jeu.hh"
#include "metal.hh"
#include "plastic.hh"
#include <iostream>

const int INITIAL_NB_EMPLOYEES = 1;
const float INITIAL_MONEY = 100;

int main() {
  // Initialisation des variables de base
  bool start = true;
  int tour = 0;
  bool choix = 0;
  int _quantity = 0;
  (void)_quantity; // TODO: remove this
  Company company(INITIAL_NB_EMPLOYEES, INITIAL_MONEY);
  Metal metal("metal", 0);
  Plastic plastic("plastic", 0);
  if (tour == 0) {
    Bienvenue();
  }
  while (start) {
    Tour(tour, company, metal, plastic);
    // MATIERE PREMIERE
    choix = choice("Souhaitez-vous acheter des matières premières ?");
    if (choix == 1) {
      choix = choice("Quelle de matière première voulez-vous acheter ?\n0. "
                     "Metal\n1. Plastique");
      // Si l'utilisateur saisit autre chose que 0 ou 1
      if (choix == 0) {
        _quantity = quantity("Combien de kg de métal voulez-vous acheter ?\n");
        // metal.buyRawMaterials(_quantity);
      }

      if (choix == 1) {
        _quantity =
            quantity("Combien de kg de plastique voulez-vous acheter ?\n");
        // plastic.buyRawMaterials(quantity);
      } else {
        std::cout << "Veuillez choisir une option valide (0 ou 1)\n";
      }
    }

    // PRODUCTION
    std::cout << "2. Produire des produits\n";
    std::cout
        << "Souhaitez-vous changer la production?\n  1(OUI) ou 0(NON) ?\n";
    std::cin >> choix;
    if (choix == 1) {
      // Ajoutez ici le code pour changer la production
    }

    // ENGAGER UN EMPLOYE
    std::cout << "3. Engager un employé\n";

    std::cout << "-------------------------------------------------------------"
                 "------\n";
    tour++;
    std::cout << "Voulez-vous continuer ? (1/0)\n";
    std::cin >> start;
  }
  return 0;
}
