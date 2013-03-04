#ifndef MATRIX_H_
#define MATRIX_H_

typedef struct matrix4 {
  float data[16];
} matrix4;
typedef struct vector {
  float data[4];
} vector;

matrix4* malloc_matrix();
vector* malloc_vector();
void copy_matrix(matrix4 *dst, matrix4 *src);
void copy_vector(vector *dst, vector *src);
void identity4(matrix4 *matrix);
void translate4(matrix4 *matrix, float x, float y, float z);
void rotate4x(matrix4 *matrix, float degree);
void rotate4y(matrix4 *matrix, float degree);
void rotate4z(matrix4 *matrix, float degree);
void multiply(matrix4 *output, matrix4 *a, matrix4 *b);
void apply(vector *vec, matrix4 *matrix);
void normalize(vector *vec);
void scale(vector *vec, float scalar);
void print_matrix(matrix4 *matrix);
void print_vector(vector *vector);
void free4(matrix4 *matrix);
void free_vector(vector *vec);


#endif // MATRIX_H_