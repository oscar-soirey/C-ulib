#ifndef COPTIONAL_CULIB_H
#define COPTIONAL_CULIB_H

#define COPTIONAL(T, n) \
typedef struct { \
	int valid; \
	union \
	{ \
		T val; \
	}; \
}n##_opt; \
static inline n##_opt T##_opt_return(T val) \
{ \
	return (n##_opt){1, val}; \
} \
static inline n##_opt T##_opt_none() \
{ \
	return (n##_opt){0}; \
}


COPTIONAL(size_t, size_t)
COPTIONAL(char, char)
COPTIONAL(signed char, schar)
COPTIONAL(unsigned char, uchar)
COPTIONAL(short, short)
COPTIONAL(unsigned short, ushort)
COPTIONAL(int, int)
COPTIONAL(unsigned int, uint)
COPTIONAL(long, long)
COPTIONAL(unsigned long, ul)
COPTIONAL(long long, ll)
COPTIONAL(unsigned long long, ull)
COPTIONAL(float, float)
COPTIONAL(double, double)
COPTIONAL(long double, ldouble)

//C99
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <stdbool.h>
COPTIONAL(bool, bool)
#endif

COPTIONAL(char*, char_ptr)

#endif