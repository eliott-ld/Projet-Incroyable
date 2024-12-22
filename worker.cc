#include "worker.hh"

bool Worker::IsWorking() const { return _job.has_value(); }
void Worker::assignJob(Jobs newJobs) {
  auto a = std::optional(Job(newJobs));
  _job.swap(a);
}
void Worker::stopJob() { _job.reset(); }
