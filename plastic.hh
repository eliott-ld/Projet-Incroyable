#include "rawMaterials.hh"
#pragma once


class Plastic : public RawMaterial {
 public:
  Plastic();
  std::string getPlasticType(){return _PlasticType;}
protected:
    std::string _PlasticType; //basic et recycled
};