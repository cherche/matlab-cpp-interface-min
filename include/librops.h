#ifndef LIBROPS_H
#define LIBROPS_H

#include <vector>
double adder(double, double);
double multer(double, double);
// We can't at all use the MATLAB-C++ compat stuff
// without using it somewhere in the exposed interface.
// No way to force it .... Makes sense, but really caught me off-guard
std::vector<double> id(std::vector<double>);

#endif // LIBROPS_H