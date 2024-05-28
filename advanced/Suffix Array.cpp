/*****************************************
 * Author: Jordan Grewe
 * Email: gp0569@wayne.edu
 * Date: 2024-05-27
 *****************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class SuffixArray {
private:
    std::vector<int> suffixArray;

    struct Suffix {
        int index;
        std::string suffix;
    };

    static bool compareSuffixes(Suffix a, Suffix b) {
        return a.suffix < b.suffix;
    }

public:
    SuffixArray(const std::string& text);
    void buildSuffixArray(const std::string& text);
    void printSuffixArray();
};

SuffixArray::SuffixArray(const std::string& text) {
    buildSuffixArray(text);
}

void SuffixArray::buildSuffixArray(const std::string& text) {
    int n = text.size();
    std::vector<Suffix> suffixes(n);

    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].suffix = text.substr(i);
    }

    std::sort(suffixes.begin(), suffixes.end(), compareSuffixes);

    suffixArray.resize(n);
    for (int i = 0; i < n; i++) {
        suffixArray[i] = suffixes[i].index;
    }
}

void SuffixArray::printSuffixArray() {
    for (int i : suffixArray) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::string text = "banana";
    SuffixArray sa(text);

    sa.printSuffixArray();

    return 0;
}
