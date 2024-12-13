#include "rawMaterials.hh"
#pragma once


class plastic : public rawMaterial {
 public:
  plastic();
  
protected:
    str type; //basic et recycled
    float price_table;    //map : product / price
};