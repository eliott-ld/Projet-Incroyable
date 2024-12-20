#pragma once

#include <cstdint>
#include <string>

/**
 * Represents the Company
 */
class Company
 
{
 public:
  Company();
  float getBalance();
  void hireWorker();
protected:
  int _level;
  int _age;
  int _nb_employees;
  float _money;
};
