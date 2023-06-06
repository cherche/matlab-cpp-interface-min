#include <stdio.h>
#include "rops/adder.h"
#include "rops/multer.h"
#include <vector>

int main(int argc, char* argv[]) {
    double x = 0.27;
    double y = 3.7;
    double sum = adder(x, y);
    double prod = multer(x, y);
    std::vector<double> v = {x, y, sum, prod};
    std::cout << x << " + " << y << " = " << sum << "\n";
    std::cout << x << " * " << y << " = " << prod << "\n";
    std::cout << "v has length " << v.size() << "\n";
    return 0;
}