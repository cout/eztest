#include "Test_Suite.hpp"
#include "Test_Result.hpp"
#include "Assertion_Failed.hpp"

#include <iostream>

namespace
{
  eztest::Test_Suite * last_test_suite;
}

eztest::Test_Suite & test_suite()
{
  return *last_test_suite;
}

void new_test_suite(std::string const & name)
{
  eztest::test_suites()[name] = eztest::Test_Suite(name);
  last_test_suite = &eztest::test_suites()[name];
}

eztest::Test_Suite::
Test_Suite(std::string const & name)
  : name_(name)
  , setup_(0)
  , teardown_(0)
{
}

void eztest::Test_Suite::
run(Test_Result & result)
{
  for(Test_Cases::iterator it = test_cases_.begin(),
      end = test_cases_.end();
      it != end;
      ++it)
  {
    try
    {
      std::cout << "" << name() << ":" << it->name() << " ";
      std::cout.flush();
      if(setup_)
      {
        setup_();
      }
      it->run();
      std::cout << ".";
    }
    catch(Assertion_Failed const & ex)
    {
      std::cout << "F";
      result.add_failure(Failure(name(), it->name(), ex.what()));
    }
    catch(std::exception const & ex)
    {
      std::cout << "E";
      result.add_error(Failure(name(), it->name(), ex.what()));
    }
    catch(...)
    {
      std::cout << "E";
      result.add_error(Failure(name(), it->name(), "Unknown exception"));
    }
    if(teardown_)
    {
      teardown_();
    }
    std::cout << std::endl;
  }
}

eztest::Test_Suites &
eztest::
test_suites()
{
  static Test_Suites test_suites;
  return test_suites;
}

