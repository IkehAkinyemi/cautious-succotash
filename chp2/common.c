#include <sys/time.h>

double GetTime() {
    struct timeval t;
    int rc = gettimeofday(&t, NULL);
    return t.tv_sec + t.tv_usec/1e6;
}

void Spin(int howlong) {
    double t = GetTime();
    while ((GetTime() - t) < howlong);
}