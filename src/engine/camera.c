#include "camera.h"

vector* camera_direction(float pitch, float yaw, float roll) {  
  vector *vec = malloc_vector();
  vec->data[2] = -1;
  vec->data[3] = 1;
  
  if(pitch > 360) {
    pitch -= 360;
  } else if (pitch < 0) {
    pitch += 360;
  }
  
  if(yaw > 360) {
    yaw -= 360;
  } else if (yaw < 0) {
    yaw += 360;
  }
  
  if(roll > 360) {
    roll -= 360;
  } else if (roll < 0) {
    roll += 360;
  }

  rotate(vec, pitch, yaw, roll);
  
  if (vec->data[2] < 0) {
    vec->data[1] *= -1;
  }
  
  if(pitch > 90 && pitch < 270) {
    vec->data[1] *= -1;
  }
  
  return vec;
}