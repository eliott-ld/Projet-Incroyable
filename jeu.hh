#include "company.hh"
#include <string>

int choice(std::string Phrase);

int quantity(std::string Phrase);

void Bienvenue();

class Jeu {
public:
  Jeu(int initial_nb_employees, float initial_money, bool dev_mode);
  void Tour();
  void run();
  void increaseLevel();
  void ask_material(std::string material);

private:
  Company _company;
  bool _start;
  int _tour;
  bool _dev_mode;
};
