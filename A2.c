/*
 -------------------------------------
 File:    A2.c
 Project: A2
 file description
 -------------------------------------
 Author:  your name here
 ID:      your ID here
 Email:   your Laurier email here
 Version  2022-05-21
 -------------------------------------
 */

# include <stdio.h>
# include "matrix.h"

//----------- Task 1: Symmetric Matrix ------------

/**
 * ----------------------------------------------------------------
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid symmetric matrix
 * 		A symmetric matrix is a matrix which equals to its transpose
 * 		For more info check: https://mathinsight.org/matrix_transpose
 * 		Notes:
 * 		- an empty matrix is a VALID symmetric matrix
 * 		- a symmetric matrix need to be a square matrix
 * ----------------------------------------------------------------
 */
int is_symmetric_matrix() {
	int rows;
	int column;
	int i = get_row_length(SIZE);
	int j = get_column_length(SIZE);
	int count = 1;
	int a[j][i];
	for (rows = 0; rows < i; rows++) {
		for (column = 0; column < j; column++) {
			a[rows][column] = matrix[column][rows];
		}
	}
	for (rows = 0; rows < i; rows++) {
		for (column = 0; column < j; column++) {
			if (matrix[rows][column] != a[rows][column]) {
				count = 0;
				break;
			}
		}
	}
	if (count == 1) {
		printf("\n The Matrix is symmetric");
	} else {
		printf("\n The matrix is not symmetric");
	}

	//your code here
	return 0;
}

//----------- Task 2: Incremental Matrix ------------
/**
 * ----------------------------------------------------------------
 * Parameters:		None
 * return:			True(1)/False(0)
 * Description:
 * 		inspect the current contents of matrix
 * 		return True if the contents represent a valid incremental matrix
 * 		An incremental matrix is:
 * 		a matrix which every element is greater than or equal to the one before it
 * 		Order: left to right, then top to bottom.
 * ----------------------------------------------------------------
 */
int is_incremental_matrix() {
	int count = 1;
	int r, c;

	if (is_empty_matrix()) {
		return False;

	} else if (!is_matrix()) {
		return False;
	} else {
		for (r = 0; r < get_row_length(SIZE); r++) {
			for (c = 0; c < get_column_length(SIZE); c++) {
				if ((matrix[r][c] > matrix[r][c + 1])
						&& matrix[r][c + 1] != -1) {
					count = 0;
					break;
				}
			}
			if (matrix[r][c] > matrix[r + 1][0] && matrix[r + 1][0] != -1) {
				count = 0;
				break;
			}
		}
		if (count == 1) {
			return True;

		} else {
			return False;
		}
	}
}

//----------- Task 3: Triangular Matrix  ------------

/**
 * ----------------------------------------------------------------
 * Parameters:	length(int): square side length
 * 				corner(char): 'T'= top corner, 'B' = bottom corner
 * 				side(char): 'L' = left side, 'R' = right side
 * 				fill(int): number to fill the matrix with
 * return:		no returns
 * Description:
 * 		Initialize a matrix then fill it in a triangular manner
 * 		The corner and side determine the position of the triangle right angle
 * 		All cells in the triangle are set to "fill", and the other cells to 0
 * Errors: 		invalid length, invalid corner, invalid side
 * ----------------------------------------------------------------
 */
void create_triangular_matrix(int length, char corner, char side, int fill) {
	//your code here
	int matrix[length][length];
	int error = 0;
	if (length < 1) {
		printf("invalid length\n");
		error = 1;
	}
	if (corner != 'T' && corner != 'B') {
		printf("invalid corner\n");
		error = 1;
	}
	if (side != 'L' && side != 'R') {
		printf("invalid side\n");
		error = 1;
	}

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			matrix[i][j] = 0;
		}
	}
	if (corner == 'T' && side == 'L') {
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length - i; j++) {
				matrix[i][j] = fill;
			}
		}
	} else if (corner == 'T' && side == 'R') {
		for (int i = 0; i < length; i++) {
			for (int j = i; j < length; j++) {
				matrix[i][j] = fill;
			}
		}
	} else if (corner == 'B' && side == 'L') {
		for (int i = 0; i < length; i++) {
			for (int j = 0; j <= i; j++) {
				matrix[i][j] = fill;
			}
		}
	} else if (corner == 'B' && side == 'R') {
		for (int i = 0; i < length; i++) {
			for (int j = length - i - 1; j < length; j++) {
				matrix[i][j] = fill;
			}
		}
	}

	if ((!error) == 1) {
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				printf("%d ", matrix[i][j]);
			}
			printf("\n");
		}
	}
	return;
}

//----------- Task 4: Flip Matrix  ------------
/**
 * ----------------------------------------------------------------
 * Parameters:	mode(char): 'h': horizontal, 'v': vertical
 * return:		no returns
 * Description:
 * 		flips the contents of the global matrix
 * 		For horizontal flip, the first row is swapped with the last row
 * 			the second row is swapped with the second to last row, and so forth
 * 		For vertical flip, the first column is swapped with the last column
 * 			the second column is swapped with the second to last column, and so forth
 * Errors: 	invalid mode, invalid matrix
 * ----------------------------------------------------------------
 */
void flip_matrix(char mode) {
	switch (mode) {

	case 'h':

		for (int x = 0; x < get_row_length(SIZE) / 2; x++) {
			for (int y = 0; y < get_column_length(SIZE); y++) {
				int new = matrix[x][y];
				matrix[x][y] = matrix[get_row_length(SIZE) - x - 1][y];
				matrix[get_row_length(SIZE) - x - 1][y] = new;
			}

		}
		break;
	case 'v':
		for (int z = 0; z < get_row_length(SIZE); z++) {
			for (int d = 0; d < get_column_length(SIZE); d++) {
				matrix[z][d] = matrix[z][get_column_length(SIZE) - 1 - d];
			}
		}
		break;
	default:
		printf("Invalid mode or invalid matrix");
	}

	//your code here
	return;
}
