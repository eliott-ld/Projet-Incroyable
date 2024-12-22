#include "finishedProduct.hh"
#include "rawMaterials.hh"
#include <vector>
#pragma once

enum class Jobs {
  CRAFT_RUBBER,
  CRAFT_PAPERCLIP,
  ASSEMBLE_STAPLER,
  ASSEMBLE_SCISSORS
};

class Job {
public:
  Job(Jobs job);
  Jobs job;
  std::vector<RawMaterial> input;
  FinishedProduct output;
};
