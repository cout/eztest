#include "Failure.hpp"

#include <iostream>

std::ostream &
eztest::
operator<<(std::ostream & out, Failure const & failure)
{
  out << "" << failure.test_suite_name_ << ":" << failure.test_case_name_ << ": " << failure.what_;
  return out;
}

