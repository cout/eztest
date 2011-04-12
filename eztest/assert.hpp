#ifndef eztest__assert__hpp_
#define eztest__assert__hpp_

#include <sstream>
#include <string>

namespace eztest
{

extern size_t assertions;

template<typename T, typename U>
void assert_equal(
    T const & t,
    U const & u,
    std::string const & s_t,
    std::string const & s_u,
    std::string const & file,
    size_t line)
{
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

template<typename T, typename U>
void assert_not_equal(
    T const & t,
    U const & u,
    std::string const & s_t,
    std::string const & s_u,
    std::string const & file,
    size_t line)
{
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

#define ASSERT_EQUAL(x, y) \
do \
{ \
++assertions; \
assert_equal((x), (y), #x, #y, __FILE__, __LINE__); \
} while(0)

#define ASSERT_NOT_EQUAL(x, y) \
do \
{ \
++assertions; \
assert_not_equal((x), (y), #x, #y, __FILE__, __LINE__); \
} while(0)

#define ASSERT(x) \
ASSERT_EQUAL(true, !!x);

#define ASSERT_EXCEPTION_CHECK(type, code, check_exception) \
try \
{ \
++assertions; \
code; \
ASSERT(!"Expected exception"); \
} \
catch(type const & ex) \
{ \
check_exception; \
}

#define ASSERT_EXCEPTION(type, code) \
ASSERT_EXCEPTION_CHECK(type, code, )

#endif // eztest__assert__hpp_
