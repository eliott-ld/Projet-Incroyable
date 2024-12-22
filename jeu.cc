#include "company.hh"
#include "jeu.hh"
#include "metal.hh"
#include "plastic.hh"
#include <iostream>

void Bienvenue() {
  std::cout
      << "Bienvenue dans le jeu Fantastic Factory,\n Bonne production !\n";
  std::cout
      << "Règles du jeu : Vous etes propiétaire d'une usine de production. "
         "Vous fournissez des supermarchés ayant une demande infinie !\n";
  std::cout << "Vous devez manufacturer des produits à partir de matière "
               "première et la vente de ces produits est automatique\n";
}

int choice(std::string Phrase) {
  int choix_utilisateur = -1;
  std::cout << Phrase << std::endl;
  std::cin >> choix_utilisateur;
  while ((choix_utilisateur != 0) && (choix_utilisateur != 1)) {
    std::cout << "Veuillez choisir une option valide.\n" << Phrase << std::endl;
    std::cin >> choix_utilisateur;
  }
  return choix_utilisateur;
}

void Jeu::Tour() {
  std::cout << "Tour " << _tour << "\n";
  std::cout << "Vous etes actuellement au niveau : " << _company.getLevel()
            << "\n";
  std::cout << "Vous avez actuellement " << _company.getBalance()
            << " pièces magiques\n";
  std::cout << "Vous avez actuellement " << _company.getNbEmployees()
            << " elfs employés\n";
  std::cout << "Vous avez actuellement " << _company.metal.getNbRawMaterials()
            << " kg de métal\n";
  std::cout << "Vous avez actuellement " << _company.plastic.getNbRawMaterials()
            << " kg de plastique\n";
  std::cout << "---------------------------------------------------------------"
               "----\n";
}

int input(std::string phrase) {
  int res = -1;
  std::cout << phrase;
  std::cin >> res;
  return res;
}

Jeu::Jeu(int initial_nb_employees, float initial_money)
    : _company(initial_nb_employees, initial_money), _start(true), _tour(0) {}

void Jeu::run() {
  int _quantity = 0;
  if (_tour == 0) {
    Bienvenue();
  }
  while (_start) {
    Tour();
    // MATIERE PREMIERE
    int choix = choice("Souhaitez-vous acheter des matières premières ?");
    if (choix == 1) {
      while (choix == 1) {
        choix = choice("Quelle de matière première voulez-vous acheter ?\n0. "
                       "Metal\n1. Plastique");
        // Si l'utilisateur saisit autre chose que 0 ou 1
        if (choix == 0) {
          _quantity = input("Combien de kg de métal voulez-vous acheter ?\n");
          int price = _company.priceRawMaterials("metal", _quantity);
          std::cout << "Confirmez vous vouloir l'acheter pour " << price
                    << " pièces magiques ?";
          int choix = choice("  1(OUI) ou 0(NON) ?");
          if (choix == 1) {
            _company.buyRawMaterials("metal", _quantity);
          }
        } else if (choix == 1) {
          _quantity =
              input("Combien de kg de plastique voulez-vous acheter ?\n");
          int price = _company.priceRawMaterials("plastic", _quantity);
          std::cout << "Confirmez vous vouloir l'acheter pour " << price
                    << " pièces magiques ?";
          int choix = choice("  1(OUI) ou 0(NON) ?");
          if (choix == 1) {
            _company.buyRawMaterials("plastic", _quantity);
          }
        } else {
          std::cout << "Veuillez choisir une option valide (0 ou 1)\n";
        }
        choix = choice(
            "Souhaitez-vous continuer d'acheter des matières premières ?");
      }
    }

    // PRODUCTION
    std::cout << "2. Manufacturer des produits\n";
    std::cout
        << "Souhaitez-vous changer la production?\n  1(OUI) ou 0(NON) ?\n";
    std::cin >> choix;
    while (choix == 1) {
      std::cout << "Quel employé voulez vous ré-affecter ? (";
      for (int i = 0; i < _company.getNbEmployees(); i++) {
        if (i != 0)
          std::cout << ", ";
        std::cout << i;
      }
      int employee_id = input(")");

      const std::string jobs[] = {
          "Fabriquer une gomme",
          "Fabriquer un trombonne",
          "Assembler des ciseaux",
          "Assembler une aggrapheuse",
      };
      const Jobs jobs_list[] = {
          Jobs::CRAFT_RUBBER,
          Jobs::CRAFT_PAPERCLIP,
          Jobs::ASSEMBLE_SCISSORS,
          Jobs::ASSEMBLE_STAPLER,
      };
      std::cout << "Quel métier voulez vous lui donner ?" << std::endl;
      for (std::size_t i = 0; i < sizeof(jobs) / sizeof(jobs[0]); i++) {
        std::cout << jobs[i] << "(" << i << ")" << std::endl;
      }
      int job_id = input("");

      _company.getWorker()[employee_id].assignJob(jobs_list[job_id]);

      std::cout << "Souhaitez-vous continuer de changer la production?\n  "
                   "1(OUI) ou 0(NON) ?\n";
      std::cin >> choix;
    }

    // ENGAGER UN EMPLOYE
    // TODO
    std::cout << "3. Engager un employé\n";

    std::cout << "-------------------------------------------------------------"
                 "------\n";
    _tour++;

    _company.produce();
    // FIN DU TOUR
    std::cout << "4. Bilan du jour\n";
    std::cout << "\tItems produits";
    for (auto product : _company.getStorage()) {
      std::cout << "\t" << product.to_string()
                << " Prix total: " << product.price() << "\n";
    }
    std::cout << std::endl;

    std::cout << "Voulez-vous continuer ? (1/0)\n";
    std::cin >> _start;
  }
}
