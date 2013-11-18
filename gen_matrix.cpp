#include <cmath>
#include <iostream>

double **pad_matrix(double **input_matrix);
double **gen_matrix(double theta, double phi, double ro);
double *get_positions(double **input_matrix, double L);

using namespace std;

int main(int argc, char *argv[]) {
    double L = 4;
    double x, y, z;
    double **matrix = gen_matrix(3, 3, 3);
    double **padded_matrix = pad_matrix(matrix);
    double *position_vector = get_positions(padded_matrix, L);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << padded_matrix[i][j] << " ";
        }
        cout << endl;
    }

    x = position_vector[0];
    y = position_vector[1];
    z = position_vector[2];

    cout << "position vector: " << endl;
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;

    return 0;
}

double **gen_matrix(double theta, double phi, double ro) {
    double **matrix;

    // allocate some space for a 3x3 in the heap
    matrix = (double **)malloc(sizeof(double *) * 3);
    for (int i = 0; i < 3; i++)
        matrix[i] = (double *)malloc(sizeof(double) * 3);

    // fill in the stuff in the matrix;
    matrix[0][0] = cos(phi)*cos(ro);
    matrix[0][1] = -sin(phi)*cos(theta) + cos(phi)*sin(ro)*sin(theta);
    matrix[0][2] = sin(phi)*sin(theta) + cos(phi)*sin(ro)*cos(theta);
    matrix[1][0] = sin(phi)*cos(ro);
    matrix[1][1] = cos(phi)*cos(theta) + sin(phi)*sin(ro)*sin(theta);
    matrix[1][2] = -cos(phi)*sin(theta) + sin(phi)*sin(ro)*cos(theta);
    matrix[2][0] = -sin(ro);
    matrix[2][1] = cos(ro)*sin(theta);
    matrix[2][2] = cos(ro)*cos(theta);

    return matrix;
}

double **pad_matrix(double **input_matrix) {
    double **padded_matrix;

    //allocate some space for a 4x4 matrix
    padded_matrix = (double **)malloc(sizeof(double *) * 4);
    for (int i = 0; i < 4; i++)
        padded_matrix[i] = (double *)malloc(sizeof(double) * 4);

    // fill in the inner columns and rows of the padded matrix
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            padded_matrix[i][j] = input_matrix[i][j];

    // fill in 4th column
    for (int i = 0; i < 3; i++) {
        padded_matrix[i][3] = 0;
    }
    padded_matrix[3][3] = 1;

    for (int i = 0; i < 3; i++) {
        padded_matrix[3][i] = 0;
    }

    return padded_matrix;
}

// where L is some value, i'm not really sure what L is supposed to be.
double *get_positions(double **input_matrix, double L) {
    double *position_vector;

    // allocated some space for a 4x1 vector
    position_vector = (double *)malloc(sizeof(double) * 4);

    position_vector[0] = L * (input_matrix[0][0] + input_matrix[0][1] +
                              input_matrix[0][2]);

    position_vector[1] = L * (input_matrix[1][0] + input_matrix[1][1] +
                              input_matrix[1][2]);

    position_vector[2] = L * (input_matrix[2][0] + input_matrix[2][1] +
                              input_matrix[2][2]);
    position_vector[3] = 1;

    return position_vector;
}
