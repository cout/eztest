#ifndef eztest__is_equal__hpp_
#define eztest__is_equal__hpp_

#include <string>

namespace eztest
{

//! Returns true if lhs == rhs.
template<typename LHS_T, typename RHS_T>
inline bool is_equal(LHS_T const & lhs, RHS_T const & rhs)
{
  return lhs == rhs;
}

//! Returns true if std::string(lhs) == std::string(rhs).
inline bool is_equal(char const * lhs, char const * rhs)
{
  return std::string(lhs) == std::string(rhs);
}

//! Returns true if std::string(lhs) == std::string(rhs).
inline bool is_equal(char * lhs, char const * rhs)
{
  return std::string(lhs) == std::string(rhs);
}

//! Returns true if std::string(lhs) == std::string(rhs).
inline bool is_equal(char const * lhs, char * rhs)
{
  return std::string(lhs) == std::string(rhs);
}

//! Returns true if !is_equal(t, u).
template<typename T, typename U>
inline bool is_not_equal(T const & t, U const & u)
{
  return !is_equal(t, u);
}

} // namespace eztest

#endif // eztest__is_equal__hpp_
