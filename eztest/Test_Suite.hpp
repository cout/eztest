#ifndef eztest__Test_Suite__hpp_
#define eztest__Test_Suite__hpp_

#include "Test_Case.hpp"

#include <string>
#include <vector>
#include <map>

namespace eztest
{

class Test_Result;

class Test_Suite
{
public:
  Test_Suite(std::string const & name = "");

  void add_test_case(Test_Case const & test_case)
  {
    test_cases_.push_back(test_case);
  }

  void setup(void (*f)()) { setup_ = f; }
  void teardown(void (*f)()) { teardown_ = f; }

  void run(Test_Result & result);

  std::string const & name() const { return name_; }

  size_t size() const { return test_cases_.size(); }

private:
  std::string name_;

  typedef std::vector<Test_Case> Test_Cases;
  Test_Cases test_cases_;

  void (*setup_)();
  void (*teardown_)();
};


Test_Suite & test_suite();
void new_test_suite(std::string const & name);

typedef std::map<std::string, Test_Suite> Test_Suites;
Test_Suites & test_suites();

} // namespace eztest

#endif // eztest__Test_Suite__hpp_
