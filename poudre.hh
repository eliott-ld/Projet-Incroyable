#pragma once

#include "rawMaterials.hh"
#include <string>

class Poudre : public RawMaterial {
public:
  Poudre(int nbRawMaterials);
  std::string getPoudreType() { return _PoudreType; }

protected:
  std::string _PoudreType;
};
