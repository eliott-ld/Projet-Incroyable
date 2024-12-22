#pragma once
#include "rawMaterials.hh"

class Metal : public RawMaterial {
public:
  Metal(std::string materialType, int nbRawMaterials);

protected:
  // il hérite des attributs de rawMaterials
};
