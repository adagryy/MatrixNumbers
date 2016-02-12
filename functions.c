#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "functions.h"

#define KGRN  "\x1B[32m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

void initialize_arr(char **tab, int n, int m){
	int i,j;
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
				tab[i][j] = 32;//space ASCII code
		}
	}
}

char** allocate_matrix_table(int n, int m){
	array = malloc(100 * sizeof(*array));
	int i;
	char** tab;
	srand(time(NULL));

	tab = (char**) malloc(sizeof(char*) * n);
	for(i = 0; i < n; i++){
		tab[i] = (char*) malloc(sizeof(char) * m);
	}
	initialize_arr(tab, n, m);
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
	system("clear");
	int i, j;
	//
	char** temp = tab;
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){			
			if(i == array[j].white1 || i == array[j].white2){
				printf(KWHT);
				printf( "%c", tab[j][i]);
				printf(RESET);
			}
			else{
				printf(KGRN);
				printf( "%c", tab[j][i]);
				printf(RESET);
			}			
		}	
		printf("\n");
	}
}

void free_tab(char **tab, int n){
	int i;
	for(i = 0; i < n; i++){
		free(tab[i]);
	}
	free(array);
	free(tab);
}
























// void fill_tab(char** tab, int n, int m){
// 	int i, j;

// 	for(i = 0; i < n; i++){
// 		start_fall[i] = rand() % 75;
// 		end_fall[i] = rand() % (80 - start_fall[i]) + start_fall[i] + 5;
// 		last_printed[i] = start_fall[i];
// 	}

// 	char** temp = tab;
// 	for(i = 0; i < n; i++){
// 		for(j = 0; j < m; j++){
// 			if(j > start_fall[i] && j <= end_fall[i])
// 				tab[i][j] = generate_random_character();
// 			else
// 				tab[i][j] = 32;//space ASCII code
// 		}
// 	}
// }