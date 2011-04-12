#ifndef eztest__is_equal__hpp_
#define eztest__is_equal__hpp_

#include <string>

namespace eztest
{

template<typename RHS_T, typename LHS_T>
inline bool is_equal(RHS_T const & rhs, LHS_T const & lhs)
{
  return rhs == lhs;
}

inline bool is_equal(char const * lhs, char const * rhs)
{
  return std::string(lhs) == std::string(rhs);
}

inline bool is_equal(char * lhs, char const * rhs)
{
  return std::string(lhs) == std::string(rhs);
}

inline bool is_equal(char const * lhs, char * rhs)
{
  return std::string(lhs) == std::string(rhs);
}

template<typename T, typename U>
inline bool is_not_equal(T const & t, U const & u)
{
  return !is_equal(t, u);
}

} // namespace eztest

#endif // eztest__is_equal__hpp_
