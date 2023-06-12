#ifndef COMPAT_H
#define COMPAT_H

#include <vector>
#include <list>
#include <sstream>
using std::vector;
using std::list;
using std::string;

#include <ginac/matrix.h>
#include <ginac/ex.h>
#include <ginac/mul.h>
#include <ginac/add.h>
#include <ginac/parser.h>
#include <ginac/operators.h>
using GiNaC::parser;
using GiNaC::lst;
using GiNaC::ex;
namespace g = GiNaC;

const char* addMatrices(const char* s, const char* t);
g::matrix toMatrix(string s);
string toString(g::matrix a);
vector<string> split(string target, string delimiter);

#endif // COMPAT_H
