#include <stdio.h>
#include "rops/adder.h"
#include "rops/multer.h"
#include <vector>

int main(int argc, char* argv[]) {
    double x = 0.27;
    double y = 3.7;
    double sum = adder(x, y);
    double prod = multer(x, y);
    std::cout << x << " + " << y << " = " << sum << std::endl;
    std::cout << x << " * " << y << " = " << prod << std::endl;

    std::string str1 = "[1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]";
    std::string str2 = "[x 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]";
    g::matrix result1 = toMatrix(str1);
    g::matrix result2 = toMatrix(str2);
    g::ex res1(result1);
    g::ex res2(result2);
    res1.print(g::print_latex());
    std::cout << std::endl;
    res2.print(g::print_latex());
    std::cout << std::endl;
    return 0;
}