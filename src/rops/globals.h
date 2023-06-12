#ifndef GLOBALS_H
#define GLOBALS_H

#include <ginac/matrix.h>
#include <ginac/ex.h>
#include <ginac/mul.h>
#include <ginac/add.h>

namespace g = GiNaC;

#if __has_include(<optional>)

#   include <optional>
namespace stdx {
  using namespace ::std;
}
#elif __has_include(<experimental/optional>)
#   include <experimental/optional>
namespace stdx {
  using namespace ::std;
  using namespace ::std::experimental;
}

#else
#   error <experimental/optional> and <optional> not found
#endif

#endif // GLOBALS_H
