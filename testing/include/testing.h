#pragma once

#include <stdexcept>
#include <functional>

struct TestCase {
  std::string const name;
  std::function<void()> const test;
};

class TestGroup {
public:
  TestGroup(std::string name, std::initializer_list<TestCase> const & testcases);
};

void Require(bool condition);

