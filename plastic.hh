#include "rawMaterials.hh"
#pragma once


class plastic : public rawMaterial {
 public:
  plastic();
  
protected:
    std::string type; //basic et recycled
    float price_table;    //map : product / price
};