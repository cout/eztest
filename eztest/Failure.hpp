#ifndef eztest__Failure__hpp_
#define eztest__Failure__hpp_

#include <string>
#include <iosfwd>

namespace eztest
{

class Failure
{
public:
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

