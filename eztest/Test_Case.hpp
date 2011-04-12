#ifndef eztest__Test_Case__hpp_
#define eztest__Test_Case__hpp_

#include <string>

namespace eztest
{

class Test_Case
{
public:
  typedef void (*Func)();

  Test_Case(
      std::string const & name,
      Func f)
    : name_(name)
    , f_(f)
  {
  }

  void run()
  {
    f_();
  }

  std::string const & name() const { return name_; }

  size_t size() const { return 1; }

private:
  std::string name_;
  Func f_;
};

} // namespace eztest

#endif // eztest__Test_Case__hpp_
