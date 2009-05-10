#include "Timer.h"

Timer::Timer()
{
#ifdef WIN32
    QueryPerformanceFrequency(&frequency);
    startCount.QuadPart = 0;
    endCount.QuadPart = 0;
#else
    startCount.tv_sec = startCount.tv_usec = 0;
    endCount.tv_sec = endCount.tv_usec = 0;
#endif

    stopped = 0;
    startTime = 0;
    endTime = 0;
}

/*
  Starts the timer
 */
void Timer::start()
{
    stopped = 0;
#ifdef WIN32
    QueryPerformanceCounter(&startCount);
#else
    gettimeofday(&startCount, 0);
#endif
}

/*
  Stops the timer
 */
void Timer::stop()
{
    stopped = 1;

#ifdef WIN32
    QueryPerformanceCounter(&endCount);
#else
    gettimeofday(&endCount, 0);
#endif
}

/*
  Returns the number of microseconds since the timer was started
 */
double Timer::getElapsedTime()
{
#ifdef WIN32
    if(!stopped)
        QueryPerformanceCounter(&endCount);

    startTime = startCount.QuadPart * (1000000.0 / frequency.QuadPart);
    endTime = endCount.QuadPart * (1000000.0 / frequency.QuadPart);
#else
    if(!stopped)
        gettimeofday(&endCount, 0);

    startTime = (startCount.tv_sec * 1000000.0) + startCount.tv_usec;
    endTime = (endCount.tv_sec * 1000000.0) + endCount.tv_usec;
#endif

    return endTime - startTime;
}
