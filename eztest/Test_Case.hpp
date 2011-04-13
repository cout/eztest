#ifndef eztest__Test_Case__hpp_
#define eztest__Test_Case__hpp_

#include <string>

namespace eztest
{

//! Test case class.
class Test_Case
{
public:
  typedef void (*Func)();

  //! Construct a new test case.
  /*! \param  name  name of the test case
   *  \param  f     function to be called when the test case is run
   */
  Test_Case(
      std::string const & name,
      Func f)
    : name_(name)
    , f_(f)
  {
  }

  //! Run the test case.
  void run()
  {
    f_();
  }

  //! Returns the name of the test case.
  std::string const & name() const { return name_; }

  //! Returns the number of members in the test case (always 1).
  size_t size() const { return 1; }

private:
  std::string name_;
  Func f_;
};

} // namespace eztest

#endif // eztest__Test_Case__hpp_
