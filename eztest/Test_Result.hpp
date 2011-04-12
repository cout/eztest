#ifndef eztest__Test_Result__hpp_
#define eztest__Test_Result__hpp_

#include "Failure.hpp"

#include <vector>

namespace eztest
{

class Test_Result
{
public:
  void add_failure(Failure const & failure)
  {
    failures_.push_back(failure);
  }

  void add_error(Failure const & failure)
  {
    errors_.push_back(failure);
  }

  std::vector<Failure> const & failures() const
  {
    return failures_;
  }

  std::vector<Failure> const & errors() const
  {
    return errors_;
  }

private:
  std::vector<Failure> failures_;
  std::vector<Failure> errors_;
};

} // namespace eztest

#endif // eztest__Test_Result__hpp_
