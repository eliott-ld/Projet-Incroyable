#pragma once

/**
 * Represents the Company
 */
class Company

{
public:
  Company(int nb_employees, float money);
  // maybe void hireworker(int nb);
  void hireWorker();
  // maybe fireworker();
  int getLevel() { return _level; }
  float getBalance() { return _money; }
  int getNbEmployees() { return _nb_employees; }

protected:
  int _level;
  int _age;
  // maybe _nb_employees variable statique
  int _nb_employees;
  float _money;
};
