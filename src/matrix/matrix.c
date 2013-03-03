#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "matrix.h"

#define PI 3.14125

matrix4* malloc_matrix() {
  matrix4 *output = malloc(16*sizeof(float));
  memset(output, 0, 16*sizeof(float));

  return output;
}

vector* malloc_vector() {
  vector *output = malloc(4*sizeof(float));
  memset(output, 0, 4*sizeof(float));

  return output;
}

void copy_matrix(matrix4 *dst, matrix4 *src) {
  memcpy(dst, src, 16*sizeof(float));
}

void copy_vector(vector *dst, vector *src) {
  memcpy(dst, src, 4*sizeof(float));
}



void identity4(matrix4 *matrix) { 
  matrix->data[0] = 1.0;
  matrix->data[5] = 1.0;
  matrix->data[10] = 1.0;
  matrix->data[15] = 1.0;
}

void translate4(matrix4 *matrix, float x, float y, float z) {
  matrix->data[3] += x;
  matrix->data[7] += y;
  matrix->data[11] += z;
}

void rotate4x(matrix4 *matrix, float degree) {
  float rad = degree*(PI/180);

  matrix4 rot = {{
    1.0, 0.0, 0.0, 0.0,
    0.0, cos(rad), -sin(rad), 0.0,
    0.0, sin(rad), cos(rad), 0.0,
    0.0, 0.0, 0.0, 1.0
  }};
  
  matrix4 *temp = malloc_matrix();
  memcpy(temp, matrix, 16*sizeof(float));
  
  multiply(matrix, &rot, temp);
  
  free4(temp);
}

void rotate4y(matrix4 *matrix, float degree) {
  float rad = degree*(PI/180);

  matrix4 rot = {{
    cos(rad), 0.0, sin(rad), 0.0,
    0.0, 1.0, 0.0, 0.0,
    -sin(rad), 0.0, cos(rad), 0.0,
    0.0, 0.0, 0.0, 1.0
  }};
  
  matrix4 *temp = malloc_matrix();
  memcpy(temp, matrix, 16*sizeof(float));
  
  multiply(matrix, &rot, temp);
  
  free4(temp);
}

void rotate4z(matrix4 *matrix, float degree) {
  float rad = degree*(PI/180);

  matrix4 rot = {{
    cos(rad), -sin(rad), 0.0, 0.0,
    sin(rad), cos(rad), 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0
  }};
  
  matrix4 *temp = malloc_matrix();
  memcpy(temp, matrix, 16*sizeof(float));
  
  multiply(matrix, &rot, temp);  
  free4(temp);
}

void multiply(matrix4 *output, matrix4 *a, matrix4 *b) {
  free4(output);
  output = malloc_matrix();
  
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      for(int k = 0; k < 4; k++) {
        output->data[i*4 + j] += a->data[i*4 + k]*b->data[k*4 + j];
      }
    }
  }
}

void apply(vector *vec, matrix4 *matrix) {
  vector *output = malloc_vector();

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 1; j++) {
      for(int k = 0; k < 4; k++) {
        output->data[i] += (matrix->data[i*4 + k])*(vec->data[k]);
      }
    }
  }
  
  copy_vector(vec, output);
  freeVector(output);
}

void normalize(vector *vec) {
  float total = fabs(vec->data[0]) + fabs(vec->data[1]) + fabs(vec->data[2]);
  vec->data[0] /= total;
  vec->data[1] /= total;
  vec->data[2] /= total;
}

void scale(vector *vec, float scalar) {
  vec->data[0] *= scalar;
  vec->data[1] *= scalar;
  vec->data[2] *= scalar;
}

void free4(matrix4 *matrix) {
  free(matrix);
}

void freeVector(vector *vec) {
  free(vec);
}

void print_matrix(matrix4 *matrix) {
  printf(" |");
  for(int i = 0; i < 4; i++) {
    printf("          %d|", i);
  }
  printf("\n");
  
  for(int i = 0; i < 4; i++) {
    printf("%d|", i);
    
    for(int j = 0; j < 4; j++) {      
      printf("%+3.8f|", matrix->data[i*4 + j]);
    }
    printf("\n");
  }
}

void print_vector(vector *vec) {
  printf(" |");
  printf("\n");
  
  for(int i = 0; i < 4; i++) {
    printf("%d|", i);  
    printf("%+3.8f|", vec->data[i]);
    printf("\n");
  }
}