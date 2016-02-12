#include <stdio.h>

#include "functions.h"

int main(){
	int i;
	
	char **tab;
	
	system("clear");
	tab = allocate_matrix_table(80, 24);

	randomise(80);

	for(i = 0; i < 20000; i++){
		refresh_tab(tab, 80, 24);
	}

	free_tab(tab, 80);
	return 0;
}