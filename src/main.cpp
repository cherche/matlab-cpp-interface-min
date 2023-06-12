#include <stdio.h>
#include "rops/adder.h"
#include "rops/multer.h"
#include <vector>

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    double x = 0.27;
    double y = 3.7;
    double sum = adder(x, y);
    double prod = multer(x, y);
    cout << x << " + " << y << " = " << sum << endl;
    cout << x << " * " << y << " = " << prod << endl;

    std::string str1 = "[1 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]";
    std::string str2 = "[x 0 0 0; 0 1 0 0; 0 0 1 0; 0 0 0 1]";
    g::matrix result1 = toMatrix(str1);
    g::matrix result2 = toMatrix(str2);
    // g::ex res1(result1);
    // res1.print(g::print_latex());
    // cout << endl;
    // g::ex res2(result2);
    // res2.print(g::print_latex());
    // cout << endl;
    cout << toString(result1) << endl;
    cout << toString(result2) << endl;

    g::parser reader;
    g::ex e = reader("1+z/3");
    cout << g::dflt << e << endl;

    return 0;
}
