#pragma once

#include <functional>
#include <sstream>
#include <stdexcept>

struct TestCase {
  std::string const name;
  std::function<void()> const test;
};

class TestGroup {
public:
  TestGroup(std::string name, std::initializer_list<TestCase> const & testcases);
};

template<typename E>
struct Equals {
  Equals(E expected) : expected_(expected) {}

  template<typename A>
  void operator()(A actual) {
    if(actual != expected_) {
      std::ostringstream message;
      message << "expecting '" << expected_ << "' but is '" << actual << "'";
      throw std::logic_error{message.str()};
    }
  }

  E expected_;
};

template<typename E>
struct Not {
  Not(E unexpected) : unexpected_(unexpected) {}

  template<typename A>
  void operator()(A actual) {
    if(actual == unexpected_) {
      std::ostringstream message;
      message << "not expecting '" << actual << "'";
      throw std::logic_error{message.str()};
    }
  }

  E unexpected_;
};

template<typename T, typename Matcher>
void Require(T actual, Matcher match) {
  match(actual);
}

