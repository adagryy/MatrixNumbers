#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_ 

typedef struct data{
	int s1, s2;
	int e1, e2;
	int t1, t2;
	int reset1, reset2;
	int white;
	int counter1;
	int deleted1;
}data;
 
data* array;

char** allocate_matrix_table(int n, int m);
void free_tab(char **tab, int n);
int generate_random_character();
void print_tab(char** tab, int n, int m);
void print_tab2(char** tab, int n, int m);
void refresh_tab(char** tab, int n, int m);
void randomise(int n);
 
#endif