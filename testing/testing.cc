#include "testing.h"

#include <iostream>
#include <map>
#include <vector>

namespace
{
  using Tests = std::map<std::string, std::vector<TestCase>>;
  Tests & tests() {
    static Tests _tests;
    return _tests;
  }

  void register_test(std::string group, TestCase const & testcase) {
    tests()[group].push_back(testcase);
  }

  bool run_tests() {
    std::size_t passed = 0;
    std::size_t failed = 0;
    for(auto const & testgroup : tests()) {
      std::cout << testgroup.first << "\n";
      for(auto const & testcase : testgroup.second) {
        std::cout << "  RUN  " << testcase.name << "\n";
        try {
          testcase.test();
          std::cout << "  OK   " << testcase.name << "\n";
          ++passed;
        } catch(std::exception const & e) {
          std::cout << "  FAIL " << testcase.name << "\n";
          std::cout << "       " << e.what() << "\n";
          ++failed;
        }
      }
      std::cout << "\n";
    }
    std::cout << "Passed : " << passed << "  Failed : " << failed << "\n";
    return failed == 0;
  }

} // namespace

TestGroup::TestGroup(std::string group, std::initializer_list<TestCase> const & testcases) {
  for(auto const & testcase : testcases) {
    register_test(group, testcase);
  }
}

int main() {
  if(not run_tests()) {
    return 1;
  }
  return 0;
}
