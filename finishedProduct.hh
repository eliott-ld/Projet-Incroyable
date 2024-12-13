#include "items.hh"
#pragma once

/**
 * a finished product can be selled
 */

class FinishedProduct : public Items {
 public:
  FinishedProduct();
  
protected:
    float price_table;    //map : product / price
};