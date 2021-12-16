#include <iostream>

#define DIM 16
void matMul(int a[DIM][DIM], int b[DIM][DIM], int c[DIM][DIM]);

int main(void){
	
	int in1[DIM][DIM];
	int in2[DIM][DIM];
	int out[DIM][DIM];

	for(int i = 0; i < DIM; ++i){
		for(int j = 0; j < DIM; ++j){
			in1[i][j] = 2;
			in2[i][j] = 3;
			out[i][j] = 0;
		}
	}

	matMul(in1, in2, out);

	for(int i = 0; i < DIM; ++i){
		for(int j = 0; j < DIM; ++j){
			if(out[i][j] != 6){
				std::cout << "Error at (col, row): (" << i << ", " << j << ")" << std::endl;
			}
		}
	}

	return 0;
}
