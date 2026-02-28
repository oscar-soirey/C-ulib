#include "../cvector.h"

typedef struct {
	int a;
	int b;
	float c;
}mystruct;
int mystruct_eq(const mystruct* a, const mystruct* b)
{
	//compare que la valeur 'a' de la structure
	return a->a == b->a;
}

CVECTOR(mystruct, mystruct, mystruct_eq)

int main()
{
	//always init to 0 !
	int_vec vec = {0};

	//add
	int_pushback(&vec, 10);
	int_pushback(&vec, 120);
	int_pushback(&vec, 65);
	int_pushback(&vec, 65);
	int_pushback(&vec, 65);

	//loop around
	for(int i = 0; i < vec.size; i++)
	{
		printf("%d, ", vec.data[i]);
	}

	//find index
	printf("\nfind elem 120, index : %d\n", int_find(&vec, 120));

	//find all
	size_t_vec all = int_findall(&vec, 65);
	printf("find all : ");
	for(size_t i = 0; i < all.size; i++)
	{
		printf("%d, ", all.data[i]);
	}

	//use of Type_at recommended instead of vec.data[i]
	printf("At 2 : %d\n", int_at(&vec, 2));
	printf("At 4 : %d\n", int_at(&vec, 4));

	//remove index
	int_remove(&vec, 0);
	for(int i = 0; i < vec.size; i++)
	{
		printf("%d, ", vec.data[i]);
	}

	//free
	int_freevec(&vec);


	mystruct_vec v = {0};
	mystruct_pushback(&v, (mystruct){10, 30, 3.14f});
	for (int i = 0; i < v.size; i++)
	{
		printf("a : %d, b : %d, c : %f\n", mystruct_at(&v, i).a, mystruct_at(&v, i).b, mystruct_at(&v, i).c);
	}
	printf("find : %d\n", mystruct_contains(&v, (mystruct){10, 3, 3}));
	mystruct_freevec(&v);
}