#include "job.hh"
#include "metal.hh"
#include "plastic.hh"

Job::Job(Jobs job) {
  this->job = job;
  switch (job) {
  case Jobs::CRAFT_RUBBER:
    input = {Plastic(1)};
    output = FinishedProduct(FinishedProductType::RUBBER, 2);
    break;
  case Jobs::CRAFT_PAPERCLIP:
    input = {Metal(1)};
    output = FinishedProduct(FinishedProductType::PAPERCLIP, 2);
    break;
  case Jobs::ASSEMBLE_STAPLER:
    input = {Plastic(1), Metal(1)};
    output = FinishedProduct(FinishedProductType::STAPLER, 1);
    break;
  case Jobs::ASSEMBLE_SCISSORS:
    input = {Plastic(1), Metal(1)};
    output = FinishedProduct(FinishedProductType::SCISORS, 1);
    break;
  default:
    throw "Impossible";
  };
}
