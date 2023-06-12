#include "compat.h"

// We assume the input is something like "[1 0; 0 1]"
// (exactly that much whitespace, no more, no less)
g::matrix toMatrix(string s) {
    string meat = s.substr(1, s.size() - 2);
    //std::cout << meat << std::endl;
    vector<string> rows = split(meat, "; ");

    // Make it into a 2d string vector ....
    // Can probably combine this with the next step.
    vector<vector<string>> mat = {};
    for (int i = 0; i < rows.size(); i++) {
        string rowString = rows[i];
        //std::cout << rowString << std::endl;
        vector<string> row = split(rowString, " ");
        mat.push_back(row);
    }

    parser reader;
    int r = mat.size();
    int c = mat[0].size();
    list<ex> els = {};
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            els.push_back(reader(mat[i][j]));
        }
    }
    lst myLst(els);

    g::matrix result = g::matrix(r, c, myLst);

    return result;
}

string toString(g::matrix a) {
    string result = "";
    for (int i = 0; i < a.rows(); i++) {
        if (i != 0) result += "; ";
        for (int j = 0; j < a.cols(); j++) {
            if (j != 0) result += " ";
            std::ostringstream s;
            s << g::dflt << a(i, j);
            result += s.str();
        }
    }
    return "[" + result + "]";
}

vector<string> split(string target, string delimiter) {
    vector<string> components;
    if (!target.empty()) {
        size_t start = 0;
        do {
            const size_t index = target.find(delimiter, start);
            if (index == string::npos) {
                break;
            }
            const size_t length = index - start;
            components.push_back(target.substr(start, length));
            start += (length + delimiter.size());
        } while (true);
        components.push_back(target.substr(start));
    }

    return components;
}
