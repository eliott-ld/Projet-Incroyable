#include "finishedProduct.hh"
#pragma once

/**
* a Rubber is a Basic finished product
 */


class Rubber : public FinishedProduct {
    public:
    Rubber();

    protected:
    int _productionTime = 1;
    str _type : "Basic";
}