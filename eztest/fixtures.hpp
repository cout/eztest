#ifndef eztest__fixtures__hpp_
#define eztest__fixtures__hpp_

#define TESTFIXTURE(name, type) \
static void UNIQUE_SUITE_NAME(fixture ## __ ## name, type)(); \
\
namespace \
{ \
struct UNIQUE_SUITE_NAME(fixture_append ## __ ## name, type) \
{ \
UNIQUE_SUITE_NAME(fixture_append ## __ ## name, type)() \
{ \
::eztest::test_suite().type(UNIQUE_SUITE_NAME(fixture ## __ ## name, type)); \
} \
} UNIQUE_SUITE_NAME(fixture_append__initializer ## __ ## name, type); \
} \
\
static void UNIQUE_SUITE_NAME(fixture ## __ ## name, type)()

#define SETUP(name) TESTFIXTURE(name, setup)

#define TEARDOWN(name) TESTFIXTURE(name, teardown)

#endif // eztest__fixtures__hpp_

