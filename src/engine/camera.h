#ifndef CAMERA_H_
#define CAMERA_H_

#include <matrix.h>

typedef struct {
  float pitch, yaw, roll;
  float x, y, z;
} camera_type;

vector* camera_direction(float pitch, float yaw, float roll);

#endif // CAMERA_H_