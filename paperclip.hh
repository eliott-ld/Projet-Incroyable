#include "finishedProduct.hh"
#pragma once

/**
* a Paperclip is a Basic finished product
 */


class Paperclip : public FinishedProduct {
    public:
    Paperclip();

    protected:
    int _productionTime = 1;
    str _type : "Basic";
}