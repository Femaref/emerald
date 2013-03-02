#ifndef STATE_H_
#define STATE_H_

#include <object.h>

struct {
  int filling;
  obj_type cube;
} state;

void state_init();

#endif // STATE_H_