#pragma once

#include <stdexcept>
#include <functional>
#include <string>
#include <sstream>

struct TestCase {
  std::string const name;
  std::function<void()> const test;
};

class TestGroup {
public:
  TestGroup(std::string name, std::initializer_list<TestCase> const & testcases);
};

template<typename T>
using Matcher = std::function<void(T const &)>;

template<typename T>
Matcher<T> Is(T const & expected) {
  return [&](T const & actual) {
    if(actual != expected) {
      std::ostringstream os;
      os << "is " << actual << " but expected is " << expected;
      throw std::logic_error{os.str()};
    }
  };
}

template<typename T>
Matcher<T> IsNot(T const & not_expected) {
  return [&](T const & actual) {
    if(actual == not_expected) {
      std::ostringstream os;
      os << "not expected to be " << not_expected;
      throw std::logic_error{os.str()};
    }
  };
}

template<typename T>
void Require(T const & actual, Matcher<T> match) {
  match(actual);
}
