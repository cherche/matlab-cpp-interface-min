#include <stdio.h>
#include "adder.h"

double adder(double x, double y) {
    return x + y;
}

vector<double> id(vector<double> v) {
    return v;
}

const char* id(const char* s) {
    return s;
}
