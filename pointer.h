#ifndef PPP_h
#define PPP_H
#include <chrono>

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::hours hours;

typedef enum{
	IN, OUT
} MODE;

bool I_CAN_MARK(MODE m);

float getTotalTimeInMarked(std::time_t in, std::time_t out);

void markInFile(MODE mode);
#endif