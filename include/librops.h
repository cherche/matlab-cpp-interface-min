#ifndef LIBROPS_H
#define LIBROPS_H

#include <vector>
double adder(double x, double y);
double multer(double x, double y);
// We can't at all use the MATLAB-C++ compat stuff
// without using it somewhere in the exposed interface.
// No way to force it .... Makes sense, but really caught me off-guard
std::vector<double> id(std::vector<double> v);
const char* id(const char* s);
const char* addMatrices(const char* s, const char* t);
const char* bracketMatrices(const char* s, const char* t);

#endif // LIBROPS_H
