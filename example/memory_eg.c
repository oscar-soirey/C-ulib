#include "../cmemory.h"

typedef struct {
	int a;
	int b;
	float c;
}mystruct;

int main()
{
	int arr[4] = {0,0,0,0};
	printf("count : %d\n", ccount(arr));

	mystruct* a = cnew(mystruct);
	ccheck(a);
	printf("auto alloc value : %d %d %f\n", a->a, a->b, a->c);
	cdelete(a);
	//use after free, crash
	printf("auto alloc value : %d\n", a->a);
	return 0;
}
