#ifndef SORT_TIMER
#define SORT_TIMER

#include <chrono>

class Timer {
    using clock = std::chrono::steady_clock;
    using point = clock::time_point;
    using duration = std::chrono::duration<double, std::milli>;

public:
    Timer() { 
        start();
    }

    void start() {
        m_start = clock::now();
    }

    void stop() {
        m_stop = clock::now();
    }

    double getDurationMs() {
        duration d = m_stop - m_start;
        return d.count();
    }

private:
    point m_start;
    point m_stop;
};

#endif