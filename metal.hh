#pragma once
#include "rawMaterials.hh"

class Metal : public RawMaterial {
public:
  Metal(int nbRawMaterials);

protected:
  // il hérite des attributs de rawMaterials
};
