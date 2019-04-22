#include <testing.h>

#include "code.h"

namespace {

Feature feature{
  "Feature xyz",
  {
    Scenario{"when ... then ...", []{
      Require(ns::answer(), Equals(23));
      Require(ns::answer(), Not(42));
    }},
  }
};

} // namespace

