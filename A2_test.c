/*
 -------------------------------------
 File:    A2_test.c
 Project: A2
 file description
 -------------------------------------
 Author:  George Fotabong
 ID:      200484320
 Email:   fota4320@mylaurier.ca
 Version  2022-05-21
 -------------------------------------
 */

# include <stdio.h>
# include "A2.h"
# include "matrix.h"
# define SIZE 10

void test_task1(); 	//is_symmetric_matrix
void test_task2(); 	//is_incremental_matrix
void test_task3();	//create_triangular_matrix
void test_task4();	//flip a matrix

//-------------------------------------------------------------------
int main() {

	setbuf(stdout, NULL);
	test_task1();
	test_task2();
	test_task3();
	test_task4();
	return 0;
}

//-------------------------------------------------------------------------
// some matrices for testing

//Matrix (a) is a valid matrix with numbers 1 to 10
int a[10][10] = { { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, { 1, 2, 3, 4, 5, 6, 7, 8,
		9, 10 }, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, { 1, 2, 3, 4, 5, 6, 7, 8, 9,
		10 }, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, {
				1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } };

//Matrix (s3) is a valid square and symmetric matrix of size 3x3
int s3[10][10] = { { 1, 7, 3, -1, -1, -1, -1, -1, -1, -1 }, { 7, 4, 8, -1, -1,
		-1, -1, -1, -1, -1 }, { 3, 8, 6, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1 }, };

//Matrix (i2) is a valid square and identity matrix of size 2x2
int i2[10][10] = { { 1, 0, -1, -1, -1, -1, -1, -1, -1, -1 }, { 0, 1, -1, -1, -1,
		-1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1,
		-1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, {
		-1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1,
		-1, -1, -1 }, };

//Matrix (i3) is a valid square and identity matrix of size 2x2
int i3[10][10] = { { 1, 0, 0, -1, -1, -1, -1, -1, -1, -1 }, { 0, 1, 0, -1, -1,
		-1, -1, -1, -1, -1 }, { 0, 0, 1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1 }, };

//Matrix (vr) is a valid vector matrix of size 1x8
int vr[10][10] = { { 1, 2, 3, 4, 5, 6, 7, 8, -1, -1 }, { -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1 }, };

//Matrix (vc) is a valid column matrix of size 10x1
int vc[10][10] = { { 1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { 2, -1, -1, -1,
		-1, -1, -1, -1, -1, -1 }, { 3, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, {
		4, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { 5, -1, -1, -1, -1, -1, -1,
		-1, -1, -1 }, { 6, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { 7, -1, -1,
		-1, -1, -1, -1, -1, -1, -1 }, { 8, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		{ 9, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { 10, -1, -1, -1, -1, -1, -1,
				-1, -1, -1 }, };

//Matrix (vx) represent an invalid row vector
int vx[10][10] = { { -1, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, { -1, -1, -1, -1, -1, -1,
		-1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1,
		-1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1,
		-1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1,
		-1, -1, -1, -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1, -1, -1,
		-1, -1 }, };

void test_task1() {
	printf("------------------------------\n");
	printf("Testing Task 1: is_symmetric_matrix\n\n");

	printf("Case 1: empty Matrix:\n");
	clear_matrix();
	print_submatrix(3, 3);
	printf("is_symmetric_matrix() = %d\n\n", is_symmetric_matrix());

	printf("Case 2: single Element matrix:\n");
	set_matrix_item(0, 0, 8);
	print_submatrix(3, 3);
	printf("is_symmetric_matrix = %d\n\n", is_symmetric_matrix());

	printf("Case 3: identity Matrix 3x3:\n");
	copy_matrix(i3);
	print_submatrix(5, 5);
	printf("is_symmetric_matrix = %d\n\n", is_symmetric_matrix());

	printf("Case 4: valid symmetric matrix 3x3:\n");
	copy_matrix(s3);
	print_submatrix(5, 5);
	printf("is_symmetric_matrix = %d\n\n", is_symmetric_matrix());

	printf("Case 5: invalid symmetric matrix 3x3:\n");
	set_matrix_item(0, 2, 10);
	print_submatrix(5, 5);
	printf("is_symmetric_matrix = %d\n\n", is_symmetric_matrix());

	printf("Case 6: invalid Matrix:\n");
	set_matrix_item(2, 2, 7);
	set_matrix_item(2, 5, 10);
	print_submatrix(4, 8);
	printf("is_symmetric_matrix = %d\n\n", is_symmetric_matrix());

	printf("Case 7: a vector:\n");
	copy_matrix(vr);
	print_submatrix(3, 10);
	printf("is_symmetric_matrix = %d\n\n", is_symmetric_matrix());

	printf("Case 8: non-square matrix:\n");
	clear_matrix();
	copy_matrix(i3);
	set_matrix_item(0, 3, 1);
	set_matrix_item(1, 3, 0);
	set_matrix_item(2, 3, 1);
	print_submatrix(5, 5);

	printf("is_symmetric_matrix = %d\n\n", is_symmetric_matrix());

	printf("End of Task 1 Testing\n");
	printf("------------------------------\n\n");
	return;
}

void test_task2() {
	printf("------------------------------\n");
	printf("Testing Task 2: is_incremental_matrix\n\n");

	printf("Case 1: empty Matrix:\n");
	clear_matrix();
	print_submatrix(2, 2);
	printf("is_incremental_matrix = %d\n\n", is_incremental_matrix());

	printf("Case 2: single element matrix:\n");
	set_matrix_item(0, 0, 7);
	print_submatrix(2, 2);
	printf("is_incremental_matrix = %d\n\n", is_incremental_matrix());

	printf("Case 3: valid incremental vector:\n");
	set_matrix_item(0, 0, 7);
	set_matrix_item(0, 1, 9);
	set_matrix_item(0, 2, 10);
	set_matrix_item(0, 3, 10);
	print_submatrix(2, 10);
	printf("is_incremental_matrix = %d\n\n", is_incremental_matrix());

	printf("Case 4: valid 2x3 incremental matrix:\n");
	clear_matrix();
	set_matrix_item(0, 0, 1);
	set_matrix_item(0, 1, 5);
	set_matrix_item(0, 2, 7);
	set_matrix_item(1, 0, 8);
	set_matrix_item(1, 1, 8);
	set_matrix_item(1, 2, 10);
	print_submatrix(4, 4);
	printf("is_incremental_matrix = %d\n\n", is_incremental_matrix());

	printf("Case 5: invalid 2x3 incremental matrix:\n");
	set_matrix_item(1, 0, 6);
	print_submatrix(4, 4);
	printf("is_incremental_matrix = %d\n\n", is_incremental_matrix());

	printf("Case 6: invalid matrix:\n");
	set_matrix_item(1, 0, 8);
	set_matrix_item(2, 0, 10);
	set_matrix_item(2, 1, 11);
	print_submatrix(4, 4);
	printf("is_incremental_matrix = %d\n\n", is_incremental_matrix());

	printf("Case 7: valid 3x3 is_incremental_matrix:\n");
	set_matrix_item(2, 2, 11);
	print_submatrix(4, 4);
	printf("is_incremental_matrix = %d\n\n", is_incremental_matrix());

	printf("Case 8: invalid 3x3 incremental matrix:\n");
	set_matrix_item(1, 2, 7);
	print_submatrix(4, 4);
	printf("is_incremental_matrix = %d\n\n", is_incremental_matrix());

	printf("End of Task 2 Testing\n");
	printf("------------------------------\n\n");
	return;
}

void test_task3() {
	printf("------------------------------\n");
	printf("Testing Task 3: create_triangular_matrix\n\n");

	//error cases
	printf("Error cases:\n");
	create_triangular_matrix(0, 'T', 'L', 5);
	create_triangular_matrix(11, 'T', 'L', 5);
	create_triangular_matrix(5, 'R', 'L', 5);
	create_triangular_matrix(5, 'B', 'M', 5);
	printf("\n");

	int lengths[10] = { 2, 3, 4, 5, 6, 7, 8, 9 };
	char corners[10] = { 'T', 'T', 'T', 'T', 'B', 'B', 'B', 'B' };
	char sides[10] = { 'L', 'L', 'R', 'R', 'L', 'L', 'R', 'R' };
	int fills[10] = { 10, 5, 2, -6, 1, 7, 3, 4 };
	for (int i = 0; i < 8; i++) {
		printf("create_triangular_matrix(%d,%c,%c,%d):\n", lengths[i],
				corners[i], sides[i], fills[i]);
		create_triangular_matrix(lengths[i], corners[i], sides[i], fills[i]);
		print_submatrix(lengths[i], lengths[i]);
		printf("\n");
	}

	printf("End of Task 3 Testing\n");
	printf("------------------------------\n\n");
	return;
}

void test_task4() {
	printf("------------------------------\n");
	printf("Testing Task 4: flip\n\n");

	int i;
	int r[10] = { 3, 4, 3, 10, 10, 10, 10 };
	int c[10] = { 3, 4, 3, 10, 10, 10, 10 };
	for (i = 0; i < 7; i++) {
		printf("Case %d:\n", i);
		clear_matrix();
		if (i == 0)
			set_matrix_item(1, 1, 0);
		if (i == 2)
			copy_matrix(i3);
		if (i == 3)
			copy_matrix(a);
		if (i == 4)
			copy_matrix(vc);
		if (i == 5)
			copy_matrix(vr);
		if (i == 6)
			copy_matrix(s3);
		printf("Before:\n");
		print_submatrix(r[i], c[i]);
		flip_matrix('h');
		printf("Flip horizontal:\n");
		print_submatrix(r[i], c[i]);
		flip_matrix('v');
		printf("Flip vertical:\n");
		print_submatrix(r[i], c[i]);
		printf("\n");
	}

	printf("End of Task 4 Testing\n");
	printf("------------------------------\n\n");
	return;
}

