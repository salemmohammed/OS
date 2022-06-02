#ifndef __common_h__
#define __common_h__

#include <sys/time.h>
#include <sys/stat.h>
#include <assert.h>

/*
struct timeval {
   time_t      tv_sec;   // Number of whole seconds of elapsed time
   long int    tv_usec;  // Number of microseconds of rest of elapsed time minus tv_sec. Always less than one million
};
*/
double GetTime() {
    struct timeval t;
    // Elapsed time is the amount of time that passes 
    // from the start of an event to its finish. 
    //int gettimeofday(struct timeval *restrict tv,
    //                 struct timezone *restrict tz);
    int rc = gettimeofday(&t, NULL);
    assert(rc == 0);
    return (double) t.tv_sec + (double) t.tv_usec/1e6;
}

void Spin(int howlong) {
    double t = GetTime();
    while ((GetTime() - t) < (double) howlong)
	; // do nothing in loop
}

#endif // __common_h__