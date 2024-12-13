#include "rawMaterials.hh"
#pragma once


class metal : public rawMaterial {
 public:
  metal();
  
protected:
    str type; //aluminium or steel
    float price_table;    //map : product / price
};