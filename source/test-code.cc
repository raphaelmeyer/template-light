#include <testing.h>

#include "code.h"

namespace {

TestGroup group{
  "Test Group",
  {
    TestCase{"when ... then ...", []{
      Require(ns::answer(), Equals(23));
      Require(ns::answer(), Not(42));
    }},
  }
};

} // namespace

