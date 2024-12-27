#include "finishedProduct.hh"

const std::map<FinishedProductType, float> FinishedProduct::_price_table = {
    {FinishedProductType::RUBBER, 11.0},
    {FinishedProductType::PAPERCLIP, 25.0},
    {FinishedProductType::SCISORS, 50},
    {FinishedProductType::STAPLER, 70},
};
