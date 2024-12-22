#include "items.hh"
#include <map>
#include <string>

#pragma once

/**
 * a finished product can be selled
 */

enum class FinishedProductType {
  RUBBER,
  PAPERCLIP,
  SCISORS,
  STAPLER,
};

class FinishedProduct : public Items {
public:
  FinishedProduct() = default;
  FinishedProduct(FinishedProductType type, int quantity)
      : type(type), quantity(quantity) {}

  float price() { return _price_table.at(type) * quantity; }

  FinishedProductType type;

  std::string to_string() const {
    switch (type) {
    case FinishedProductType::RUBBER:
      return "gomme";
    case FinishedProductType::PAPERCLIP:
      return "trombonne";
    case FinishedProductType::SCISORS:
      return "ciseaux";
    case FinishedProductType::STAPLER:
      return "aggrapheuse";
    default:
      throw "impossible";
    }
  }

protected:
  // TODO
  // map : product / price
  const static std::map<FinishedProductType, float> _price_table;
  int quantity;
};
