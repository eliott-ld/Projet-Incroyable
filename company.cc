#include "company.hh"
#include "plastic.hh"
#include "worker.hh"

Company::Company(int nb_employees, float money)
    : metal(0), plastic(0), _age(0), _money(money), _accumulatedMoney(0),
      _workers{Worker()} {}

void Company::hireWorker() {
  _workers.push_back(Worker());
  _money -= 50;
}

int Company::priceRawMaterials(std::string material, int nb) {
  if (material == "plastic") {
    Plastic new_plastic(nb);
    return new_plastic.getPrice();
  }
  if (material == "metal") {
    Metal new_metal(nb);
    return new_metal.getPrice();
  }
  throw "material should be metal or plastic";
}

void Company::buyRawMaterials(std::string material, int nb) {
  if (material == "plastic") {
    Plastic new_plastic(nb);
    _money -= new_plastic.getPrice();
    plastic.add(new_plastic.getNbRawMaterials());
  } else if (material == "metal") {
    Metal new_metal(nb);
    _money -= new_metal.getPrice();
    metal.add(new_metal.getNbRawMaterials());
  } else {
    throw "material should be metal or plastic";
  }
}

void Company::produce() {
  for (auto worker : _workers) {
    if (worker.IsWorking()) {
      auto job = worker.currentJob().value();
      for (auto input : job.input) {
        if (input.getMaterialType() == "metal") {
          if (metal.getNbRawMaterials() >= input.getNbRawMaterials()) {
            metal.remove(input.getNbRawMaterials());
          } else {
            throw "Not enough metal";
          }
        } else if (input.getMaterialType() == "plastic") {
          if (plastic.getNbRawMaterials() >= input.getNbRawMaterials()) {
            plastic.remove(input.getNbRawMaterials());
          } else {
            throw "Not enough plastic";
          }
        } else {
          throw "Impossible";
        }
      }
      add_product(job.output);
    }
  }
}

void Company::add_product(FinishedProduct product) {
  storage.push_back(product);
}

float Company::sellStorage() {
  auto res = 0;
  for (auto product : storage) {
    res += product.price();
  }
  storage.clear();
  addMoney(res);
  return res;
}

void Company::addMoney(float newMoney) {
  _money += newMoney;
  _accumulatedMoney += newMoney;
}

int Company::getLevel() {
  switch ((int)_accumulatedMoney) {
  case 0 ... 199:
    return 1;
  case 200 ... 349:
    return 2;
  case 350 ... 799:
    return 3;
  case 800 ... 999:
    return 4;
  default:
    return 5;
  }
}
int Company::getNextLevelGoal() {
  switch ((int)_accumulatedMoney) {
  case 0 ... 199:
    return 200;
  case 200 ... 349:
    return 350;
  case 350 ... 799:
    return 800;
  case 800 ... 999:
    return 1000;
  default:
    return 0; // never reached
  }
}

float Company::payWorkers() {
  float sum = _workers.size() * Worker::salary;
  _money -= sum;
  return sum;
}

void Company::payImpots(float dollars) { _money -= dollars; }
