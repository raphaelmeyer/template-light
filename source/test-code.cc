#include <testing.h>

#include "code.h"

namespace {

TestGroup group{
  "Test Group",
  {
    TestCase{"when ... then ...", []{
      Require(ns::answer(), IsNot(42));
    }}
  }
};

} // namespace
