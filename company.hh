#pragma once

/**
 * Represents the Company
 */
#include "finishedProduct.hh"
#include "metal.hh"
#include "plastic.hh"
#include "worker.hh"
#include <vector>
class Company

{
public:
  Company(int nb_employees, float money);
  // maybe void hireworker(int nb);
  void hireWorker();
  // maybe fireworker();
  int getLevel() { return _level; }
  float getBalance() { return _money; }
  int getNbEmployees() { return _workers.size(); }
  std::vector<Worker> getWorker() { return _workers; }
  int priceRawMaterials(std::string material, int nb);
  void buyRawMaterials(std::string material, int nb);
  void produce();
  void add_product(FinishedProduct product);
  std::vector<FinishedProduct> getStorage() { return storage; }
  void setLevel(int level) { _level = level; }
  
  Metal metal;
  Plastic plastic;

protected:
  int _level;
  int _age;
  std::vector<Worker> _workers;
  float _money;

  // inventaire vendu à la fin de la semaine
  std::vector<FinishedProduct> storage;
};
