#include "items.hh"
#pragma once

/**
 * a raw Material can be bought and used to make finished products
 */

class rawMaterial : public Items {
 public:
  rawMaterial();
  
protected:
    float price_table;    //map : product / price
};