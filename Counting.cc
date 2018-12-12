#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>

#include "Timer.hpp"

std::vector<int> randGen(size_t N);

void countingSort(std::vector<int>& v);

int main(int argc, char* argv[]) {
    
    size_t N;
    std::cout << "N ==> ";
    std::cin >> N;

    std::vector<int> v = randGen(N);
    std::vector<int> vCopy(v);

    Timer t;
    countingSort(v);
    t.stop();
    double countingTime = t.getDurationMs();

    t.start();
    std::sort(vCopy.begin(), vCopy.end());
    t.stop();
    double stdTime = t.getDurationMs();

    std::cout << std::fixed << std::setprecision(3) << std::endl;
    std::cout << "Count time: " << countingTime << " ms" << std::endl;
    std::cout << "std time:   " << stdTime << " ms" << std::endl;

    std::cout << std::boolalpha << "Sort OK?    " << (v == vCopy) << std::endl;

    return 0;
}

std::vector<int> randGen(size_t N) {    
    std::random_device rd;
    std::mt19937 r(rd());
    std::uniform_int_distribution<int> dist(1, 9999);

    std::vector<int> v(N);

    std::for_each(v.begin(), v.end(), [&](int& i){ i = dist(r); });

    return v;
}

void countingSort(std::vector<int>& v) {
    int max = *std::max_element(v.begin(), v.end());

    std::vector<int> vCount(max + 1);

    std::for_each(v.begin(), v.end(), [&](const int& i){ ++vCount[i]; });

    for (size_t k = 0, vIndex = 0; k < vCount.size(); ++k) {
        while (vCount[k] > 0) {
            v[vIndex] = k;
            ++vIndex;
            --vCount[k];
        }
    }
}