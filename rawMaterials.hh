#include "items.hh"
#pragma once

/**
 * a raw Material can be bought and used to make finished products
 */

class RawMaterial : public Items {
 public:
  RawMaterial();
  float getNbRawMaterials(){return _NbRawMaterials;}
  float getPriceTable(){return _price_table;}
  std::string getMaterialType(){return _MaterialType;}
protected:
    std::string _MaterialType;
    float _price_table;    //map : product / price
    float _NbRawMaterials;
};