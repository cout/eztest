#include "eztest.hpp"
#include "Test_Suite.hpp"
#include "Test_Result.hpp"

#include <iostream>
#include <vector>

size_t assertions;

int
eztest::
eztest_main()
{
  Test_Result result;
  size_t num_tests = 0;

  for(Test_Suites::iterator it = test_suites().begin(),
      end = test_suites().end();
      it != end;
      ++it)
  {
    it->second.run(result);
    num_tests += it->second.size();
  }

  std::cout << std::endl;

  std::cout << num_tests << " test(s), "
            << assertions << " assertion(s), "
            << result.errors().size() << " error(s), "
            << result.failures().size() << " failure(s)"
            << std::endl;

  if(result.errors().size() > 0)
  {
    std::cout << std::endl << "Errors:" << std::endl;
    for(std::vector<Failure>::const_iterator it = result.errors().begin(),
        end = result.errors().end();
        it != end;
        ++it)
    {
      std::cout << *it << std::endl;
    }
  }

  if(result.failures().size() > 0)
  {
    std::cout << std::endl << "Failures:" << std::endl;
    for(std::vector<Failure>::const_iterator it = result.failures().begin(),
        end = result.failures().end();
        it != end;
        ++it)
    {
      std::cout << *it << std::endl;
    }
  }

  return result.errors().size() + result.failures().size();
}

