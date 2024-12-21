#include "company.hh"
#pragma once

/**
 * Represents one Worker
 */
class Worker
 
{
 public:
  Worker();
  bool IsWorking();
  void currentJob();
  void assignJob();

protected:

  static int _salary = 50;
  _job;
};