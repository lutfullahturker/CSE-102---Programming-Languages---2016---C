#include <stdio.h>
#include <string.h>

typedef struct {
	int rows;
	int cols;
	float* data;
} Matrix;

Matrix matrixMult(Matrix a,Matrix b);
Matrix newMatrix(int cols,int rows);
Matrix readMatrix(FILE * fp);
int readMatrixes(FILE *fp,Matrix* mxs);
void writeMatrix(FILE *fp,Matrix m);
void writeMatrixes(FILE *fp,Matrix m,int count);
void printMatrix(Matrix t);

int main(void)
{


	return 0;
}

Matrix newMatrix(int cols,int rows)
{
	Matrix new;
	int size=cols*rows;
	new.data=callsdfoc(size,sizeof(int));
	


}
