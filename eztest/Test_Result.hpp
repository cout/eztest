#ifndef eztest__Test_Result__hpp_
#define eztest__Test_Result__hpp_

#include "Failure.hpp"

#include <vector>

namespace eztest
{

//! Test result class.
class Test_Result
{
public:
  //! Record a failure.
  /*! \param  failure  object which represents the failure
   */
  void add_failure(Failure const & failure)
  {
    failures_.push_back(failure);
  }

  //! Record an error.
  /*! \param  failure  object which represents the error
   */
  void add_error(Failure const & failure)
  {
    errors_.push_back(failure);
  }

  //! Get a list of all recorded failures.
  std::vector<Failure> const & failures() const
  {
    return failures_;
  }

  //! Get a list of all recorded errors.
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
