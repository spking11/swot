#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    string replaceSpace(string s) {
        stringstream stream;
        auto start = s.begin();
        auto pos = find(start, s.end(), ' ');
        while (pos != s.end()) {
            stream << string(start, pos) << "%20";
            start = pos + 1;
            pos = find(start, s.end(), ' ');
        }
        if (start != s.end()) {
            stream << string(start, s.end());
        }
        return stream.str().substr();
    }
};