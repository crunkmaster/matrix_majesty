#include <cstdio>

typedef struct {
	double comp[3];
} vec;

void print_vec(vec x);
double dot(vec a, vec b);
vec make_vec(double a, double b, double c);
void gen_dcm(vec *ground, vec *capitals, vec *lowercase);

int main(int argc, char *argv[]) {

	vec capitals[3];
	vec lowercase[3];
	vec ground[3];

	// initialize the vectors with some simple values
	// for actual testing, make some vectors with make_vec
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			capitals[i].comp[j] = j + 1;
			lowercase[i].comp[j] = j + 2;
		}
	}

	//	ground[0] = ig = {I.i, J.i, K.i}
	//	ground[1] = jg = {I.j, J.j, K.j}
	//	ground[2] = kg = {I.k, J.k, K.k}
	gen_dcm(ground, capitals, lowercase);

	for (int i = 0; i < 3; i++) {
		printf("capitals[%d] ", i);
		print_vec(capitals[i]);

		printf("lowercase[%d] ", i);
		print_vec(lowercase[i]);

		printf("ground[%d] ", i);
		print_vec(ground[i]);

		printf("\n");
	}

	return 0;
}

// capitals should be an array of 3 vecs {I, J, K}
// lowercase should be an array of 3 vecs {i, j, k}
void gen_dcm(vec *ground, vec *capitals, vec *lowercase) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			ground[i].comp[j] = dot(capitals[j], lowercase[i]);
}

void print_vec(vec x) {
	for (int i = 0; i < 3; i++) {
		printf("%f ", x.comp[i]);
	}
	printf("\n");
}

// builds a vector from three values
vec make_vec(double a, double b, double c) {
	vec temp;
	temp.comp[0] = a; temp.comp[1] = b;
	temp.comp[2] = c;

	return temp;
}


// this function assumes only 3d vectors
// computes the dot product of two vectors
double dot(vec a, vec b) {
	double sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += (a.comp[i] * b.comp[i]);
	}	
	return sum;
}