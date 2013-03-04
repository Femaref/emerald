#include "camera.h"

vector* camera_direction(float pitch, float yaw, float roll) {  
  matrix4 *matrix = malloc_matrix();
  vector *vec = malloc_vector();
  vec->data[2] = -1;
  vec->data[3] = 1;

  identity4(matrix); 
  
  rotate4z(matrix, roll);
  rotate4y(matrix, yaw);
  rotate4x(matrix, pitch);
  
  apply(vec, matrix);
  normalize(vec);
  if (vec->data[2] < 0) {
    vec->data[1] *= -1;
  }
  
  free4(matrix);
  
  return vec;
}