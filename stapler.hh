#include "finishedProduct.hh"
#pragma once

/**
* a Stappler is a Deluxe finished product
 */


class Rubber : public FinishedProduct {
    public:
    Stapler();

    protected:
    int _productionTime = 5;
    str _type : "Deluxe";
}