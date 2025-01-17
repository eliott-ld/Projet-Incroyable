#include "items.hh"
#include <map>
#include <string>
#pragma once

/**
 * a raw Material can be bought and used to make finished products
 */

class RawMaterial : public Items {
public:
  RawMaterial() {};
  int getNbRawMaterials() { return _nbRawMaterials; }
  std::string getMaterialType() { return _materialType; }
  float getPrice() {
    return _price_table.at(_materialType) * _nbRawMaterials *
           (1 - getReduction(_nbRawMaterials));
  }




//reduction appliquée si un gros volume est acheté (max 20%)
  static float getReduction(int nbRawMaterials) {
    if (nbRawMaterials < 0)
      throw "Impossible argument négatif 🤬";

    if (0 <= nbRawMaterials && nbRawMaterials < 10)
      return 0;
    if (10 <= nbRawMaterials && nbRawMaterials < 50)
      return 0.1;
    else
      return 0.2;
  }

  void add(int nb) { _nbRawMaterials += nb; }
  void remove(int nb) { _nbRawMaterials -= nb; }

protected:
  std::string _materialType;
  static std::map<std::string, float> _price_table; // map : product / price
  int _nbRawMaterials;
};
