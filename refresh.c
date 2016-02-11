#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "functions.h"

void randomise(int n){
	int i;
	for(i = 0; i < n; i++){
		array[i].l1 = rand() % 24;
		array[i].l2 = rand() % 24;
		array[i].s1 = rand() % (24 - array[i].l1);
		array[i].s2 = rand() % (24 - array[i].l2);
		array[i].reset1 = rand() % 25;
		array[i].reset2 = rand() % 25;
		array[i].t1 = 0;
		array[i].t2 = 0;
	}
}

void refresh_tab(char** tab, int n, int m){
	int i,j;

	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			if(array[i].s1 >= j && j <= array[i].s1 + array[i].l1){
				tab[i][j] = generate_random_character();
			
			// if(array[i].s2 >= j && i <= array[i].s2 + array[i].l2)
			// 	tab[i][j] = generate_random_character();
			usleep(100000);
			print_tab(tab, n, m);
		}
		}
	}

}

// typedef struct data{
// 	int s1, s2;
// 	int l1, l2;
// 	int t1, t2;
// 	int reset1, reset2;
// }data