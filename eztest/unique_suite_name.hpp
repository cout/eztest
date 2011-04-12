#ifndef eztest__unique_suite_name__hpp_
#define eztest__unique_suite_name__hpp_

// TODO: not sure how to append __LINE__ correctly here
#define UNIQUE_SUITE_NAME(prefix, name) \
prefix ## __ ## name \

#endif

