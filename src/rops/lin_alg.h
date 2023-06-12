#ifndef LIN_ALG_H
#define LIN_ALG_H

#include "globals.h"

namespace lin_alg {
    /** Computes the lie bracket mn-nm. */
    g::matrix bracket(g::matrix &m, g::matrix &n);
}

#endif // LIN_ALG_H
