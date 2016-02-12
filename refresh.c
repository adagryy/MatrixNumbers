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
		array[i].white = -1;
		array[i].counter1 = 0;
	}
}

void refresh_tab(char** tab, int n, int m){
	int i;
	int temp1, temp2;

	for(i = 0; i < n; i++){
		temp1 = array[i].s1 + array[i].counter1;
		temp2 = array[i].s1 + array[i].l1;

		
		if(temp1 == temp2)
			array[i].white = -1;
		else
			array[i].white = temp1;
		
		tab[i][temp1] = generate_random_character();
		if(temp1 < temp2)
			array[i].counter1++;
	}

	usleep(100000);
	print_tab(tab, n, m);
}