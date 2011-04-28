#ifndef eztest__eztest__hpp_
#define eztest__eztest__hpp_

#include "Assertion_Failed.hpp"
#include "Failure.hpp"
#include "Test_Case.hpp"
#include "Test_Result.hpp"
#include "Test_Suite.hpp"

#include "assert.hpp"
#include "fixtures.hpp"
#include "is_equal.hpp"
#include "unique_suite_name.hpp"

//! Define a new test suite
/*! \param  name  name of the test suite
 */
#define TESTSUITE(name) \
struct UNIQUE_SUITE_NAME(testsuite_append, name) \
{ \
UNIQUE_SUITE_NAME(testsuite_append, name)() \
{ \
::eztest::new_test_suite(#name); \
} \
} UNIQUE_SUITE_NAME(testsuite_append__initializer, name)

//! Define a new test case
/*! \param  name  name of the test case
 */
#define TESTCASE(name) \
static void UNIQUE_SUITE_NAME(test, name)(); \
\
namespace \
{ \
struct UNIQUE_SUITE_NAME(test_append, name) \
{ \
UNIQUE_SUITE_NAME(test_append, name)() \
{ \
::eztest::test_suite().add_test_case( \
::eztest::Test_Case(#name, & UNIQUE_SUITE_NAME(test, name))); \
} \ } UNIQUE_SUITE_NAME(test_append__initializer, name); \ } \
\
static void UNIQUE_SUITE_NAME(test, name)()

namespace eztest
{

//! Run the test runner.
int eztest_main();

} // namespace eztest

#endif // eztest__eztest__hpp_

