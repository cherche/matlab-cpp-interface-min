#include "multer.h"
#include "lin_alg.h"

float multer(float x, float y) {
    g::matrix a = {{0, x}, {0, 0}};
    g::matrix b = {{0 ,0}, {y, 0}};
    g::matrix c = lin_alg::bracket(a, b);
    g::ex z = c(0,0);
    float d = 0;

    // ex_to<numeric> is an unsafe cast, so check the type first
    if (g::is_a<g::numeric>(z)) {
        d = (float) g::ex_to<g::numeric>(z).to_double();
    } else {
        // error
    }

    return d;
}