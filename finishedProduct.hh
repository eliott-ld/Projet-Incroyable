#include "items.hh"
#pragma once

/**
 * a finished product can be selled
 */

class FinishedProduct : public Items {
public:
  FinishedProduct();

  void sell();

protected:
  float price_table; // map : product / price
};
