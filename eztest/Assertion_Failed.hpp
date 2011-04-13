#ifndef eztest__Assertion_Failed__hpp_
#define eztest__Assertion_Failed__hpp_

#include <string>
#include <stdexcept>

namespace eztest
{

//! Exception which is thrown when there is a failed assertion.
class Assertion_Failed
  : public std::runtime_error
{
public:
  //! Construct a new Assertion_Failed exception with the given failure
  //! message.
  /*! \param  what  description of the failure
   */
  Assertion_Failed(std::string const & what)
    : std::runtime_error(what)
  {
  }
};

} // namespace eztest

#endif // eztest__Assertion_Failed__hpp_
