/*
 -------------------------------------
 File:    matrix.h
 Project: A2
 file description
 -------------------------------------
 Author:  your name here
 ID:      your ID here
 Email:   your Laurier email here
 Version  2022-05-21
 -------------------------------------
 */

#ifndef MATRIX_H_
#define MATRIX_H_

# define SIZE 10
# define True 1;
# define False 0;
# define ERROR_CODE -99;

int matrix[SIZE][SIZE]; //global variable to store matrix

void initialize_matrix();
void clear_matrix();
void print_submatrix(int, int);

int set_matrix_item(int, int, int);
void copy_matrix(int[10][10]);

int is_equal_matrix(int[10][10]);
int get_row_length(int);
int get_column_length(int);
int get_matrix_item(int, int);
int contains_item_matrix(int[100], int);

int is_empty_matrix();
int is_vector_matrix();
int is_matrix();

#endif /* MATRIX_H_ */
