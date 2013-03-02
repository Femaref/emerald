#ifndef STATE_H_
#define STATE_H_

#include <model.h>

struct {
  int filling;
  model_type cube;
} state;

void state_init();

#endif // STATE_H_