#ifndef eztest__assert__hpp_
#define eztest__assert__hpp_

#include <sstream>
#include <string>

namespace eztest
{

extern size_t assertions;

//! Helper function for ASSERT_EQUAL macro
template<typename T, typename U>
void assert_equal(
    T const & t,
    U const & u,
    std::string const & s_t,
    std::string const & s_u,
    std::string const & file,
    size_t line)
{
  ++assertions;

  if(!is_equal(t, u))
  {
    std::stringstream strm;
    strm << "Assertion failed: "
      << s_t << " != " << s_u
      << " (" << t << " != " << u << ")"
      << " at " << file << ":" << line;
    throw Assertion_Failed(strm.str());
  }
}

//! Helper function for ASSERT_NOT_EQUAL macro
template<typename T, typename U>
void assert_not_equal(
    T const & t,
    U const & u,
    std::string const & s_t,
    std::string const & s_u,
    std::string const & file,
    size_t line)
{
  ++assertions;

  if(!is_not_equal(t, u))
  {
    std::stringstream strm;
    strm << "Assertion failed: "
      << s_t << " should != " << s_u
      << " (" << t << " should != " << u << ")"
      << " at " << file << ":" << line;
    throw Assertion_Failed(strm.str());
  }
}

} // namespace eztest

//! Throw an Assertion_Failed exception unless x==y
#define ASSERT_EQUAL(x, y) \
do \
{ \
assert_equal((x), (y), #x, #y, __FILE__, __LINE__); \
} while(0)

//! Throw an Assertion_Failed exception unless !(x==y)
#define ASSERT_NOT_EQUAL(x, y) \
do \
{ \
assert_not_equal((x), (y), #x, #y, __FILE__, __LINE__); \
} while(0)

//! Throw an Assertion_Failed exception unless x
#define ASSERT(x) \
ASSERT_EQUAL(true, !!x);

//! Throw an Assertion_Failed exception unless code throws an exception
/*! \param  type  C++ type of expected exception
 *  \param  code  code which is expected to throw the exception
 */
#define ASSERT_EXCEPTION(type, code) \
ASSERT_EXCEPTION_CHECK(type, code, )

//! Throw an Assertion_Failed exception unless code throws an exception
/*! \param  type  C++ type of expected exception
 *  \param  code  code which is expected to throw the exception
 *  \param  check_exception  code to validate the exception
 */
#define ASSERT_EXCEPTION_CHECK(type, code, check_exception) \
try \
{ \
code; \
ASSERT(!"Expected exception"); \
} \
catch(type const & ex) \
{ \
check_exception; \
}

#endif // eztest__assert__hpp_
