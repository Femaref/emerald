#ifndef STATE_H_
#define STATE_H_

#include <model.h>
#include <camera.h>

struct {
  int filling;  
  camera_type camera;
  model_type cube;
  int mouse_x, mouse_y;
} state;

void state_init();

#endif // STATE_H_