#include "company.hh"
#include "plastic.hh"
#include "worker.hh"

Company::Company(int nb_employees, float money)
    : metal(0), plastic(0), _level(0), _age(0), _workers{Worker()},
      _money(money) {}



void Company::hireWorker() {
  _workers.push_back(Worker());
  _money -= 100;
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
          metal.remove(input.getNbRawMaterials());
        } else if (input.getMaterialType() == "plastic") {
          plastic.remove(input.getNbRawMaterials());
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
