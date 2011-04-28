eztest -- a simple unit testing framework for C++
=================================================

Usage
-----

  #include <eztest/eztest.hpp>

  TESTSUITE(name_of_test_suite);

  SETUP(name_of_test_suite)
  {
    // ...
  }

  TEARDOWN(name_of_test_suite)
  {
    // ...
  }

  TESTCASE(name_of_test_1)
  {
    // ...
  }

  TESTCASE(name_of_test_2)
  {
    // ...
  }

Advantages
-----------

* Simple, easy to use
* No dependencies

Limitations
-----------

* No inheritance of test suites
* No way to hook into the test suite to override default behavior

