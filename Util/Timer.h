#ifndef TIMER
#define TIMER

#ifdef WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

class Timer
{
private:
    double startTime, endTime;
    int stopped;
#ifdef WIN32
    LARGE_INTEGER frequency, startCount, endCount;
#else
    timeval startCount, endCount;
#endif

public:
    Timer(void);
    void start(void);
    void stop(void);
    double getElapsedTime(void);
};

#endif
