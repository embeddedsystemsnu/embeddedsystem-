#include "ap_int.h"

#define DIM 16

void matMul(int a[DIM][DIM], int b[DIM][DIM], int c[DIM][DIM]){
	#pragma HLS INTERFACE m_axi port=a offset=slave depth=16 bundle=gmem
	#pragma HLS INTERFACE m_axi port=b offset=slave depth=16 bundle=gmem
	#pragma HLS INTERFACE m_axi port=c offset=slave depth=16 bundle=gmem

	#pragma HLS INTERFACE s_axilite port=a bundle=control
	#pragma HLS INTERFACE s_axilite port=b bundle=control
	#pragma HLS INTERFACE s_axilite port=c bundle=control
	#pragma HLS INTERFACE s_axilite port=return bundle=control

	static int a_t[DIM][DIM];
	static int b_t[DIM][DIM];
	static int c_t[DIM][DIM];

	for(int i = 0; i < DIM; ++i){
		for(int j = 0; j < DIM; ++j){
			a_t[i][j] = a[i][j];
			b_t[i][j] = b[i][j];

			c_t[i][j] = a_t[i][j] * b_t[i][j];

			c[i][j] = c_t[i][j];
		}
	}

	return;
}
