#include <stdio.h>

int main(void) {

	int humanNumber = 0;
	int relationNumber = 0;
	int relationA = 0, relationB = 0;

	scanf("%d %d", &humanNumber, &relationNumber);

	int matrix[2001][2001] = { 0, };

	for (int i = 0; i < relationNumber; i++) {

		scanf("%d %d", &relationA, &relationB);

		matrix[relationA][relationB] = 1;
		matrix[relationB][relationA] = 1;

	}

	if(matrix[])


	return 0;

}