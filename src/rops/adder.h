#ifndef ADDER_H
#define ADDER_H

#include "globals.h"
#include <vector>

using std::vector;
using std::list;
using std::string;

#include <ginac/parser.h>
#include <ginac/print.h>
using GiNaC::parser;
using GiNaC::lst;
using GiNaC::ex;

double adder(double, double);
vector<double> id(vector<double>);
const char* id(const char* s);
const char* addMatrices(const char* s, const char* t);
g::matrix toMatrix(string s);
vector<string> split(string target, string delimiter);

#endif // ADDER_H