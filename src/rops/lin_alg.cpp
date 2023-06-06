#include "lin_alg.h"

using std::vector;

namespace lin_alg {
    g::matrix bracket(g::matrix &x, g::matrix &y) {
        // Compute [x,y] = xy - yx
        return x.mul(y).sub(y.mul(x));
    }
}