#ifndef eztest__Assertion_Failed__hpp_
#define eztest__Assertion_Failed__hpp_

#include <string>
#include <stdexcept>

namespace eztest
{

class Assertion_Failed
  : public std::runtime_error
{
public:
  Assertion_Failed(std::string const & what)
    : std::runtime_error(what)
  {
  }
};

} // namespace eztest

#endif // eztest__Assertion_Failed__hpp_
