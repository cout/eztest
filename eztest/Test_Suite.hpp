#ifndef eztest__Test_Suite__hpp_
#define eztest__Test_Suite__hpp_

#include "Test_Case.hpp"

#include <string>
#include <vector>
#include <map>

namespace eztest
{

class Test_Result;

//! Test suite class.
class Test_Suite
{
public:
  //! Construct a new test suite.
  /*! \param  name  name of the test suite
   */
  Test_Suite(std::string const & name = "");

  //! Add a test case to the suite.
  /*! \param  test_case  test case to add to the suite
   */
  void add_test_case(Test_Case const & test_case)
  {
    test_cases_.push_back(test_case);
  }

  //! Defines a function to be called at the start of every test case in
  //! the suite.
  /*! \param  f  function to be called
   */
  void setup(void (*f)()) { setup_ = f; }

  //! Defines a function to be called at the end of every test case in
  //! the suite.
  /*! \param  f  function to be called
   */
  void teardown(void (*f)()) { teardown_ = f; }

  //! Run all the test cases in the suite.
  /*! \param  result  a Test_Result instance in which the results will
   *          be stored.
   */
  void run(Test_Result & result);

  //! Returns the name of the suite.
  std::string const & name() const { return name_; }

  //! Returns the number of cases in the suite.
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
