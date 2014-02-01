#include <iostream>
#include <cstdio>

using namespace std;

typedef struct {
	double comp[3];
} vec;

void print_vec(vec x);
double dot(vec a, vec b);
int main(int argc, char *argv[]) {

	vec I, J, K;
	vec i, j, k;
	vec ig, jg, kg;
	vec capitals[3] = {I, J, K};
	vec lowercase[3] = {i, j, k}; 
	vec ground[3] = {ig, jg, kg};

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			capitals[i].comp[j] = j + 1;
			lowercase[i].comp[j] = j + 2;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ground[i].comp[j] = dot(capitals[j], lowercase[i]);
		}
	}

	for (int i = 0; i < 3; i++) {
		printf("capitals[%d] ", i);
		print_vec(capitals[i]);
		printf("lowercase[%d] ", i);
		print_vec(lowercase[i]);
		printf("ground[%d] ", i);
		print_vec(ground[i]);
	}

	return 0;
}

void print_vec(vec x) {
	for (int i = 0; i < 3; i++) {
		printf("%f ", x.comp[i]);
	}
	printf("\n");
}

// this function assumes only 3d vectors
double dot(vec a, vec b) {
	double sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += (a.comp[i] * b.comp[i]);
	}	
	return sum;
}