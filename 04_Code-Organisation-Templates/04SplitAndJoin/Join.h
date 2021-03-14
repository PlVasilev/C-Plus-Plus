#ifndef JOIN_H
#define JOIN_H
#include <vector>


#include <vector>
#include <string>
#include <sstream>

template<typename T>
std::string join(const std::vector<T>& input, const std::string& joinStr) {
    std::ostringstream os;
    for (int i = 0; i < input.size(); i++) {
        os << input[i];
        if (i < input.size() - 1) {
            os << joinStr;
        }
    }
    return os.str();
};

#endif // !JOIN_H