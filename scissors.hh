#include "finishedProduct.hh"
#pragma once

/**
* a Scissors is a Deluxe finished product
 */


class Scissors : public FinishedProduct {
    public:
    Scissors();

    protected:
    int _productionTime = 5;
    str _type : "Deluxe";
}