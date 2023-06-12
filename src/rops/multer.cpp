#include "multer.h"
#include "lin_alg.h"

double multer(double x, double y) {
    g::matrix a = {{0, x}, {0, 0}};
    g::matrix b = {{0 ,0}, {y, 0}};
    g::matrix c = lin_alg::bracket(a, b);
    g::ex z = c(0,0);
    double d = 0;

    // ex_to<numeric> is an unsafe cast, so check the type first
    if (g::is_a<g::numeric>(z)) {
        d = g::ex_to<g::numeric>(z).to_double();
    } else {
        // error
    }

    return d;
}
