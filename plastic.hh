#pragma once

#include "rawMaterials.hh"
#include <string>

class Plastic : public RawMaterial {
public:
  Plastic(int nbRawMaterials);
  std::string getPlasticType() { return _PlasticType; }

protected:
  std::string _PlasticType; // basic et recycled
};
