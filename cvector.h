/**
 * //for a vector of int :
 * for(int i = 0; i < vector.size; i++)
 * {
 *   printf("%d ", vector[i]);
 * }
 * 
 * freevec
 * pushback
 * find
 * findall
 * at
 * remove
 * pop
 * front
 * back
 * insert
 * erase
 * clear
 * shrink_to_fit
 * append
 * contains
 */

#ifndef CVECTOR_UCLIB_H
#define CVECTOR_UCLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

//define vector for a type
//Type, Name, Equal Operator (==)
#define CVECTOR(T, n, eq) \
typedef struct { \
	T* data; \
	size_t size; \
	size_t capacity; \
}n##_vec; \
void n##_freevec(n##_vec* v) \
{ \
	free(v->data); \
	v->data = NULL; \
	v->size = 0; \
	v->capacity = 0; \
} \
void n##_pushback(n##_vec* v, T elem) \
{ \
	if(v->size == v->capacity) \
	{ \
		v->capacity = v->capacity ? v->capacity * 2 : 4; \
		v->data = realloc(v->data, v->capacity * sizeof(T)); \
	} \
	v->data[v->size++] = elem; \
} \
size_t n##_find(n##_vec* v, T elem) \
{ \
	for(size_t i = 0; i < v->size; i++) \
	{ \
		if(eq(&v->data[i], &elem)) return i; \
	} \
	return v->size; \
} \
size_t_vec n##_findall(n##_vec* v, T elem) \
{ \
	size_t_vec vec = {0}; \
	for(size_t i = 0; i < v->size; i++) \
	{ \
		if(eq(&v->data[i], &elem)) size_t_pushback(&vec, i); \
	} \
	return vec; \
} \
T n##_at(n##_vec* v, size_t index) \
{ \
	if(index < v->size) \
		return v->data[index]; \
	fprintf(stderr, "cvector at error: Attempted to access index %zu, size is %zu\n", index, v->size); \
	exit(EXIT_FAILURE); \
} \
void n##_remove(n##_vec* v, size_t index) \
{ \
	if(index+1 > v->size) \
	{ \
		fprintf(stderr, "cvector remove error: Index %zu out of bounds. Vector size is %zu.\n", index, v->size); \
		return; \
	} \
	for(size_t i = index; i < v->size - 1; i++) \
	{ \
		v->data[i] = v->data[i+1]; \
	} \
	v->size--; \
} \
void n##_pop(n##_vec* v) \
{ \
	if(v->size == 0) { return; } \
	n##_remove(v, v->size-1); } \
T n##_front(n##_vec* v) { return n##_at(v, 0); } \
T n##_back(n##_vec* v) { return n##_at(v, v->size-1); } \
void n##_insert(n##_vec* v, size_t index, T elem) \
{ \
	if(index > v->size) index = v->size; \
	if(v->size == v->capacity) \
	{ \
		v->capacity = v->capacity ? v->capacity*2 : 4; \
		v->data = realloc(v->data, v->capacity*sizeof(T)); \
	} \
	for(size_t i = v->size; i > index; i--) \
		{ v->data[i] = v->data[i-1]; } \
	v->data[index] = elem; \
	v->size++; \
} \
void n##_erase(n##_vec* v, size_t start, size_t end) \
{ \
	if(start >= v->size) return; \
	if(end > v->size) end = v->size; \
	size_t count = end - start; \
	for(size_t i = start; i + count < v->size; i++) v->data[i] = v->data[i + count]; \
	v->size -= count; \
} \
void n##_clear(n##_vec* v) \
{ \
	free(v->data); \
	v->data = NULL; \
	v->size = 0; \
	v->capacity = 0; \
} \
void n##_shrink_to_fit(n##_vec* v) \
{ \
	if(v->size < v->capacity) \
	{ \
		v->capacity = v->size; \
		v->data = realloc(v->data, v->capacity * sizeof(T)); \
	} \
} \
void n##_append(n##_vec* v0, const n##_vec* v1) \
{ \
	for(size_t i = 0; i < v1->size; i++) \
		{ n##_pushback(v0, v1->data[i]); } \
} \
int n##_contains(n##_vec* v, T elem) \
{ \
	return n##_find(v, elem) != v->size; \
}

/* Register every primitive types */
int size_t_eq(const size_t* a, const size_t* b)
{
	return *a == *b;
}
CVECTOR(size_t, size_t, size_t_eq)

int char_eq(const char* a, const char* b)
{
	return *a == *b;
}
CVECTOR(char, char, char_eq)

int schar_eq(const signed char* a, const signed char* b)
{
	return *a == *b;
}
CVECTOR(signed char, schar, schar_eq)

int uchar_eq(const unsinged char* a, const unsigned char* b)
{
	return *a == *b;
}
CVECTOR(unsigned char, uchar, uchar_eq)

int short_eq(const short* a, const short* b)
{
	return *a == *b;
}
CVECTOR(short, short, short_eq)

int ushort_eq(const unsigned short* a, const unsigned short* b)
{
	return *a == *b;
}
CVECTOR(unsigned short, ushort, ushort_eq)

int int_eq(const int* a, const int* b)
{
	return *a == *b;
}
CVECTOR(int, int, int_eq)

int uint_eq(const unsigned int* a, const unsigned int* b)
{
	return *a == *b;
}
CVECTOR(unsigned int, uint, uint_eq)

int long_eq(const long* a, const long* b)
{
	return *a == *b;
}
CVECTOR(long, long, long_eq)

int ul_eq(const unsigned long* a, const unsigned long* b)
{
	return *a == *b;
}
CVECTOR(unsigned long, ul, ul_eq)

int ll_eq(const long long* a, const long long* b)
{
	return *a == *b;
}
CVECTOR(long long, ll, ll_eq)

int ull_eq(const unsigned long long* a, const unsigned long long* b)
{
	return *a == *b;
}
CVECTOR(unsigned long long, ull, ull_eq)

int float_eq(const float* a, const float* b)
{
	//IEEE precision
	return fabsf(*a - *b) < 1e-6f;
}
CVECTOR(float, float, float_eq)

int double_eq(const double* a, const double* b)
{
	return 0;  //not valid, change
}
CVECTOR(double, double, double_eq)

int ldouble_eq(const long double* a, const long double* b)
{
	return 0;  //same
}
CVECTOR(long double, ldouble, ldouble_eq)

//at least C99 (for bool)
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <stdbool.h>
int bool_eq(const bool* a, const bool* b)
{
	return *a == *b;
}
CVECTOR(bool, bool, bool_eq)
#endif

//CVECTOR(void*, void_ptr)
int str_char_eq(char* const* a, char* const* b)
{
	if(*a == NULL || *b == NULL) { return *a == *b; }
	return strcmp(*a, *b) == 0;
}
CVECTOR(char*, char_ptr, str_char_eq)

#endif