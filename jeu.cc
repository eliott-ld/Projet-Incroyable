#include "company.hh"
#include "jeu.hh"
#include "mini_jeu_impots.hh"
#include "text_box.hh"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>

int load(std::string message, int time_secs) {
  std::cout << message;
  std::cout.flush();
  for (int j = 0; j < time_secs; j++) {
    for (int i = 0; i < 3; i++) {
      std::cout << ".";
      std::cout.flush();
      std::this_thread::sleep_for(std::chrono::milliseconds(333));
    }
    std::cout << "\b\b\b   \b\b\b";
  }
  std::cout << std::endl;

  return 0;
}

void loading_screen() {
  std::string original = "Game Loading...\n"
                         "\n\n\n\n"
                         "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀@@@@@@@@@@\n"
                         "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀@@@@@@@@ \n"
                         "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀@@@⠀@@⠀ \n"
                         "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⢸⣿⠀ \n"
                         "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⢸⣿⠀ \n"
                         "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⢸⣿⠀ \n"
                         "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⢸⣿⡇⠀⢸⣿⠀ \n"
                         "⠀⠀⢠⣷⡀⠀⠀⠀⠀⣼⣦⠀⠀⠀⠀⢠⣷⣄⠀⠀⠀⠀⢸⣿⡇⠀⢸⣿⠀ \n"
                         "⠀⠀⢸⣿⣿⣆⠀⠀⠀⣿⣿⣷⡀⠀⠀⢸⣿⣿⣧⠀⠀⠀⢸⣿⡇⠀⢸⣿⠀ \n"
                         "⠀⠀⣾⣿⣿⣿⣷⡀⢠⣿⣿⣿⣿⣆⠀⣼⣿⣿⣿⣷⣄⠀⢸⣿⡇⠀⢸⣿⠀ \n"
                         "⠀⠀⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣶⣼⣿⣧⣤⣾⣿⠀ \n"
                         "⠀⠀⣿⡟⠉⠉⢹⣿⡏⠉⠉⢻⣿⠉⠉⠉⣿⣿⠉⠉⢹⣿⣿⣿⣿⣿⣿⣿⠀ \n"
                         "⠀⠀⣿⣷⣶⣶⣾⣿⣷⣶⣶⣾⣿⣶⣶⣶⣿⣿⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⠀ \n"
                         "⠀⠀⣿⡏⠉⠉⢹⣿⡏⠉⠉⢹⣿⠉⠉⠉⣿⣿⠉⠉⢹⣿⣿⣿⣿⣿⣿⣿⠀ \n"
                         "⠀⠀⣿⣿⣶⣶⣾⣿⣷⣶⣶⣿⣿⣷⣶⣾⣿⣿⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⠀ \n"
                         "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ \n";
  std::string text = original;

  // Seed random number generator
  std::srand(std::time(nullptr));

  // Duration for the animation in milliseconds
  const int duration = 5000;    // 3 seconds
  const int tickDuration = 100; // 100 ms per frame
  const int iterations = duration / tickDuration;

  for (int i = 0; i < iterations; ++i) {
    // Modify the smoke (top rows with '@' characters)
    for (size_t j = 0; j < text.length(); ++j) {
      if (original[j] == '@') {
        text[j] = (std::rand() % 2 == 0) ? '@' : ' ';
      }
    }

    // Clear the console
    std::cout << "\x1B[2J\x1B[H"; // ANSI escape codes to clear screen and reset
                                  // cursor

    // Print the updated text
    // std::cout << text << std::endl;
    printBoxedText(text, "\e[0;33m");

    // Wait for the next frame
    std::this_thread::sleep_for(std::chrono::milliseconds(tickDuration));
  }
  // Clear the console
  std::cout << "\x1B[2J\x1B[H"; // ANSI escape codes to clear screen and reset
                                // cursor
}
void Bienvenue() {
  const std::string text =
      "👋 Bienvenue dans le jeu Fantastic Factory\n"
      "📜 Règles du jeu : Vous etes propiétaire d'une usine de production. "
      "Vous fournissez des supermarchés ayant une demande infinie !\n"
      " 🫡 Vous devez manufacturer des produits à partir de matière "
      "première et la vente de ces produits est automatique 🤑\n"

      "🛑 Attention vous ne devez pas trop vous endetter! "
      "Si vous allez à -200 pièces magiques, VOUS PERDEZ 💀\n";
  printBoxedText(text, "\e[3m\e[1;32m");
}
void game_over() {
  // clang-format off
  printBoxedText( 
" ░▒▓██████▓▒░ ░▒▓██████▓▒░░▒▓██████████████▓▒░░▒▓████████▓▒░       ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓███████▓▒░ \n"
"░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░\n"
"░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒▒▓█▓▒░░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░\n"
"░▒▓█▓▒▒▓███▓▒░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓██████▓▒░        ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒▒▓█▓▒░░▒▓██████▓▒░ ░▒▓███████▓▒░ \n"
"░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▓█▓▒░ ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░\n"
"░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▓█▓▒░ ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░\n"
" ░▒▓██████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓████████▓▒░       ░▒▓██████▓▒░   ░▒▓██▓▒░  ░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░\n",
 "\e[0;31m");
  // clang-format on
}

void bankrupt() {
  std::cout << "\n\n\n\nBankrupt 💸" << std::endl;
  game_over();
}

int choice(const std::string Phrase) {
  int choix_utilisateur = -1;
  std::cout << Phrase << "\n> ";

  while (true) {
    if (!(std::cin >> choix_utilisateur)) {
      if (std::cin.eof()) {
        std::cout << "\n👋🤓 Au revoir\n";
        exit(1);
      }
      std::cin.clear();
    } else if (choix_utilisateur == 0 || choix_utilisateur == 1) {
      std::cout << std::endl;
      return choix_utilisateur;
    } else {
      std::cout << std::endl;
      std::cout << "Veuillez choisir une option valide (0 ou 1).\n"
                << Phrase << "\n> ";
    }
  }
}
void Jeu::Tour() {
  auto level = _company.getLevel();
  if (level == 5) {
    printBoxedText("Félicitations Grand Industriel !!! Vous avez atteint le "
                   "niveau maximum ! 🫡 ",
                   "\e[1;93m");
    exit(0);
  }

  const auto y = "\e[0;33m";
  const auto r = "\e[0;0m";
  const auto bb = "\e[1;34m";
  const auto p = "\e[1;35m";
  std::stringstream text;
  text << bb << "Tour " << _tour << r << "\n";
  text << "Vous etes actuellement au niveau: " << p << level << r << "\n";
  text << "Vous avez actuellement " << y << _company.getBalance()
       << " pièces magiques " << r << "\n";
  text << "Vous avez actuellement " << _company.getNbEmployees()
       << " elf(s) employé(s)\n";
  text << "Vous avez actuellement " << _company.metal.getNbRawMaterials()
       << " kg de métal\n";
  text << "Vous avez actuellement " << _company.plastic.getNbRawMaterials()
       << " kg de plastique\n";
  printBoxedText(text.str());
}

int input(std::string phrase) {
  int res = -1;
  std::cout << phrase << "\n> ";
  std::cin >> res;
  std::cout << std::endl;
  return res;
}

Jeu::Jeu(int initial_nb_employees, float initial_money, bool dev_mode)
    : _company(initial_nb_employees, initial_money), _start(true), _tour(0),
      _dev_mode(dev_mode) {}
void Jeu::ask_material(std::string material) {
  std::cout << "Combien de kg de " << material << " voulez-vous acheter ?";
  int _quantity = input("");
  int price = _company.priceRawMaterials(material, _quantity);
  if (price > _company.getBalance()) {
    std::cout << "Vous n'avez pas assez d'argent pour acheter autant "
                 "de "
              << material << " (" << price << " > " << _company.getBalance()
              << ")" << std::endl;
  } else {
    std::cout << "Confirmez vous vouloir l'acheter pour " << price
              << " pièces magiques ?";
    int choix = choice("  1(OUI) ou 0(NON) ?");
    if (choix == 1) {
      _company.buyRawMaterials(material, _quantity);
    }
  }
}

void Jeu::run() {
  loading_screen();
  if (_tour == 0) {
    Bienvenue();
  }
  while (_start) {
    Tour();
    // MATIERE PREMIERE
    int choix = choice(
        "Souhaitez-vous acheter des matières premières ?\n 1(OUI) ou 0(NON)");
    if (choix == 1) {
      while (choix == 1) {
        choix = choice("Quelle de matière première voulez-vous acheter ?\n0. "
                       "Metal\n1. Plastique");
        // Si l'utilisateur saisit autre chose que 0 ou 1
        if (choix == 0) {
          ask_material("metal");
        } else if (choix == 1) {
          ask_material("plastic");
        }
      }
    }

    // ENGAGER UN EMPLOYE
    // TODO
    std::cout << "2. Engager un employé\n";
    std::cout << "🛑 ATTENTION 🛑: le salaire quotidien de chaque employer est "
                 "de 10 pièces\n";
    choix = choice("Souhaitez-vous engager un employé pour 100 pièces "
                   "magiques ?\n 1(OUI) ou 0(NON)");
    if (choix == 1) {
      _company.hireWorker();
    }
    // PRODUCTION
    std::cout << "3. Manufacturer des produits\n";
    choix =
        choice("Souhaitez-vous changer la production?\n  1(OUI) ou 0(NON) ?");
    while (choix == 1) {
      std::cout << "Quel employé voulez vous ré-affecter ? (";
      for (int i = 0; i < _company.getNbEmployees(); i++) {
        if (i != 0)
          std::cout << ", ";
        std::cout << i;
      }
      int employee_id = input(")");

      if (employee_id >= _company.getNbEmployees()) {
        std::cout << "L'employé doit être compris entre 0 et "
                  << _company.getNbEmployees() - 1 << std::endl;
        continue;
      }

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
      const std::size_t jobs_count = sizeof(jobs) / sizeof(jobs[0]);
      std::cout << "Quel métier voulez vous lui donner ?" << std::endl;
      for (std::size_t i = 0; i < jobs_count; i++) {
        std::cout << jobs[i] << "(" << i << ")" << std::endl;
      }
      int job_id = input("");

      if (job_id >= (int)jobs_count) {
        std::cout << "L'employé doit être compris entre 0 et "
                  << _company.getNbEmployees() - 1 << std::endl;
        continue;
      }

      _company.getWorker()[employee_id].assignJob(jobs_list[job_id]);
      choix = choice("Souhaitez-vous continuer de changer la production?\n"
                     "1(OUI) ou 0(NON) ?");
    }

    std::cout << "-------------------------------------------------------------"
                 "------\n";
    _tour++;

    _company.produce();

    if (!_dev_mode)
      load("L'usine tourne à plein régime", 10);

    printBoxedText(
        "Avant de passer au bilan, c'est l'heure de payer vos impôts! 🏦💸",
        "\033[38;2;0;255;0m");

    int taux_impot = mini_jeu_impots();

    // FIN DU TOUR
    std::cout << "4. Bilan du jour\n";
    std::cout << "\tItems produits\n";
    for (auto product : _company.getStorage()) {
      std::cout << "\t" << product.getQuantity() << " " << product.to_string()
                << "(s)"
                << " Prix total: " << product.price() << std::endl;
    }
    auto revenue = _company.sellStorage();
    std::cout << "Vos gains d'aujourd'hui: " << revenue << std::endl;

    auto impots_dollars = revenue * taux_impot / 100;
    std::cout << "Impôts = " << revenue << " * " << taux_impot
              << "% = " << impots_dollars << "$\n";
    auto salaries = _company.payWorkers();
    std::cout << "Coût des salaire d'aujourd'hui: " << salaries << std::endl;

    _company.payImpots(impots_dollars);

    if (_company.getBalance() < -200) {
      bankrupt();
      break;
    }

    _start = choice("Voulez-vous continuer ? (1/0)");
  }
}
