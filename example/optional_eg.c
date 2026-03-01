#include "../coptional.h"

#include <stdio.h>

int_opt GetOpt()
{
	//return none : 
	return int_opt_none();
	//return value :
	return int_opt_return(5);
}

int main()
{
	int_opt o = GetOpt();
	if(o.valid)
	{
		printf("int opt %d\n", o.val);
	}
}