#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

// void fill_tab(char** tab, int n, int m){
// 	int i, j;
// 	char** temp = tab;
// 	for(i = 0; i < n; i++){
// 		for(j = 0; j < m; j++){
// 			tab[i][j] = generate_random_character();
// 		}
// 	}
// }

char** allocate_matrix_table(int n, int m){
	int i;
	char** tab;
	srand(time(NULL));
	tab = (char**) malloc(sizeof(char*) * n);
	for(i = 0; i < n; i++){
		tab[i] = (char*) malloc(sizeof(char) * m);
	}
	//fill_tab(tab, n, m);
	return tab;
}



int generate_random_character(){
	//(48,57)
	//(65,90)
	//(97,122)	
	int random_number = rand() % 62;
	if(random_number < 10)
		return 48 + random_number;
	else if(random_number >= 10 && random_number < 36)
		return 55 + random_number; //equivalent to: "return 65 + random_number - 10;" - it saves time needed for differenting two numbers
	else
		return 61 + random_number; //equivalent to: "return 97 + random_number - 36" - it saves time needed for differenting two numbers 
}

void print_tab(char** tab, int n, int m){
	int i, j;
	char** temp = tab;
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%c", tab[j][i]);
		}
		printf("\n");
	}
}

void free_tab(char **tab, int n){
	int i;
	for(i = 0; i < n; i++){
		free(tab[i]);
	}
	free(tab);
}