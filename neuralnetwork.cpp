#include "neuralnetwork.h"
#include <math.h>

#define NR_END 1

NetworkNeural Matrix;			// Pre-instantiate
//Matrix Multiplication Routine
// C = A*B
void NetworkNeural::MultiplyMatrix(float* A, float* B, int m, int p, int n, float* C) {
	// A = input matrix (m x p)
	// B = input matrix (p x n)
	// m = number of rows in A
	// p = number of columns in A = number of rows in B
	// n = number of columns in B
	// C = output matrix = A*B (m x n)
	int i, j, k;
	for (i = 0; i < m; i++)
		for(j = 0; j < n; j++)
		{
			C[n * i + j] = 0;
			for (k = 0; k < p; k++)
				C[n * i + j] = C[n * i + j] + A[p * i + k] * B[n * k + j];
		}
}

void NetworkNeural::Print(float* A, int m, int n, String label) {
	// A = input matrix (m x n)
	int i, j;
	Serial.println();
	Serial.println(label);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			Serial.print(A[n * i + j]);
			Serial.print("\t");
		}
		Serial.println();
	}
}

void NetworkNeural::Sigmoid(float* X, int m, int n, float* Y) {
	   float exp_value;
     float return_value;
		 for(int i=0; i<m; i++) {
			 for(int j = 0; j < n; j++){
		     // Exponential calculation
		     exp_value = exp((double) -X[i *n + j]);
		     //Final sigmoid value
		     return_value = 1 / (1 + exp_value);
				 Y[i *n + j] = return_value;
		 	 }
	 	 }
}

float NetworkNeural::MaxMatrix(float* X, int m, int n) {
   float max=-32000;
	 int num_elements = m*n;
   for (int i=0; i<num_elements; i++) {
		 if (X[i]>max) {
		    max=X[i];
		 }
   }
   return max;
}
