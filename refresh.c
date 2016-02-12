#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "functions.h"

void randomise_first_bar(char** tab, int x){
	array[x].s1 = rand() % 25;
	array[x].e1 = rand() % (25 - array[x].s1) + array[x].s1;
	array[x].reset1 = rand() % 25;
	array[x].t1 = 0;
	array[x].white1 = -1;
	array[x].counter1 = 0;
	array[x].deleted1 = 0;
}

void randomise_second_bar(char** tab, int x){
	array[x].s2 = rand() % 25;
	array[x].e2 = rand() % (25 - array[x].s2) + array[x].s2;
	array[x].reset2 = rand() % 25;
	array[x].t2 = 0;
	array[x].white2 = -1;
	array[x].counter2 = 0;
	array[x].deleted2 = 0;
}

void start_removing(char **tab, int n, int m){
	int i;

	for(i = 0; i < n; i++){
		if(array[i].t1 == array[i].reset1){
			if(array[i].s2 + array[i].counter2 != 32)
				tab[i][array[i].s1 + array[i].deleted1] = 32;
			if(array[i].s1 + array[i].deleted1 < array[i].e1)
				array[i].deleted1++;
			else{
				randomise_first_bar(tab, i);
				//randomise_second_bar(tab, i);
			}
		}
	}


	for(i = 0; i < n; i++){
		if(array[i].t2 == array[i].reset2){
			if(array[i].s1 + array[i].counter1 != 32)
				tab[i][array[i].s2 + array[i].deleted2] = 32;
			if(array[i].s2 + array[i].deleted2 < array[i].e2)
				array[i].deleted2++;
			else{
				randomise_second_bar(tab, i);
				//randomise_first_bar(tab, i);
			}
		}
	}
}

void refresh_tab(char** tab, int n, int m){
	int i;
	int temp1, temp2, temp3, temp4;

	for(i = 0; i < n; i++){
		temp1 = array[i].s1 + array[i].counter1;
		temp2 = array[i].e1;
		if(array[i].t1 < array[i].reset1)
			array[i].t1++;		
		if(temp1 == temp2)
			array[i].white1 = -1;
		else if(temp1 < temp2)
			array[i].white1 = temp1;
		if(temp1 < temp2)
			tab[i][temp1] = generate_random_character();
		if(temp1 < temp2)
			array[i].counter1++;
	}
	for(i = 0; i < n; i++){
		temp3 = array[i].s2 + array[i].counter2;
		temp4 = array[i].e2;
		if(array[i].t2 < array[i].reset2)
			array[i].t2++;		
		if(temp3 == temp4)
			array[i].white2 = -1;
		else if(temp3 < temp4)
			array[i].white2 = temp3;
		if(temp3 < temp4)
			tab[i][temp3] = generate_random_character();
		if(temp3 < temp4)
			array[i].counter2++;
	}
	
	usleep(100000);
	print_tab(tab, n, m);
	start_removing(tab,n,m);
}

void randomise(int n){
	int i;
	for(i = 0; i < n; i++){
		array[i].s1 = rand() % 24;
		array[i].s2 = rand() % 24;
		array[i].e1 = rand() % (24 - array[i].s1) + array[i].s1;
		array[i].e2 = rand() % (24 - array[i].s2) + array[i].s2;
		array[i].reset1 = rand() % 25;
		array[i].reset2 = rand() % 25;
		array[i].t1 = 0;
		array[i].t2 = 0;
		array[i].white1 = -1;
		array[i].counter1 = 0;
		array[i].white2 = -1;
		array[i].counter2 = 0;
	}
}