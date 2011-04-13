#ifndef eztest__Failure__hpp_
#define eztest__Failure__hpp_

#include <string>
#include <iosfwd>

namespace eztest
{

//! Abstraction for a test failure.
class Failure
{
public:
  //! Construct a new Failure object.
  /*! \param  test_suite_name  name of the test suite in which the
   *          failure occurred.
   *  \param  test_case_name  name of the test case in which the
   *          failure occurred.
   *  \param  what  description of the failure
   */
  Failure(
      std::string const & test_suite_name,
      std::string const & test_case_name,
      std::string what)
    : test_suite_name_(test_suite_name)
    , test_case_name_(test_case_name)
    , what_(what)
  {
  }

  friend std::ostream & operator<<(std::ostream & out, Failure const & failure);

private:
  std::string test_suite_name_;
  std::string test_case_name_;
  std::string what_;
};

std::ostream & operator<<(std::ostream & out, Failure const & failure);

} // namespace eztest

#endif // eztest__Failure__hpp_

