#include <stdlib.h>
#include <GLUT/glut.h>

#include "ui.h"
#include "state.h"

void keyboard (unsigned char key, int x, int y) {
  switch(key) {
    case 'q':
      exit(0);
      break;
      
    case 'r': case 'R':
      if(state.filling) {
        glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
      } else {
        glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
      }
      state.filling = !state.filling;
      break;
    default:
      break;
  }
}
void keyboard_s (int key, int x, int y) {
}

void motion(int x, int y) {
  int dx = x - state.mouse_x;
  int dy = y - state.mouse_y;
}