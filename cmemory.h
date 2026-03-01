/**
 * cnew
 * cdelete
 * cswap
 * ccount
 * cmin
 * cmax
 */

#ifndef CMEMORY_CUILB_H
#define CMEMORY_CUILB_H

#include <stdlib.h>
#include <stdio.h>

//alloc and init to 0
#define cnew(type) (type*)calloc(1, sizeof(type))
//alloca check
#define ccheck(ptr) do { if(!(ptr)) { fprintf(stderr,"cmemory ccheck error : out of memory\n"); exit(EXIT_FAILURE); } } while(0)
//safe delete
#define cdelete(inst) do { free(inst); inst = NULL; } while(0)
//swap two variables
#define cswap(type, a, b) do { type tmp = a; a = b; b = tmp; } while(0)
//static array size (number of elements)
#define ccount(arr) (sizeof(arr)/sizeof(arr[0]))
//min/max (int, float, double, uint, ...)
#define cmin(a, b) ((a) < (b) ? (a) : (b))
#define cmax(a, b) ((a) > (b) ? (a) : (b))


#endif