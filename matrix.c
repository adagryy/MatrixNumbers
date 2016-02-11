#include <stdio.h>

#include "functions.h"

int main(){
	int i;
	
	char **tab;

	tab = allocate_matrix_table(80, 24);
	//print_tab2(tab, 80, 24);
	print_tab(tab, 80, 24);

	free_tab(tab, 80);
	return 0;
}