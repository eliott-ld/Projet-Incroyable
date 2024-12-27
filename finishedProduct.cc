#include "finishedProduct.hh"

const std::map<FinishedProductType, float> FinishedProduct::_price_table = {
    {FinishedProductType::RUBBER, 1.5},
    {FinishedProductType::PAPERCLIP, 2.0},
    {FinishedProductType::SCISORS, 10},
    {FinishedProductType::STAPLER, 12},
};
