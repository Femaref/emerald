#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GLUT/glut.h>

#include <matrix.h>

#include "ui.h"
#include "state.h"


void keyboard (unsigned char key, int x, int y) {
  matrix4 *matrix = malloc_matrix();
  matrix4 *temp = malloc_matrix();

  identity4(matrix);
 
  rotate4x(matrix, state.camera.pitch);
  rotate4y(matrix, state.camera.yaw);
  
  print_matrix(matrix);
  

  switch(key) {
    case 'q':
      exit(0);
      break;
    case 'w':
      break;
    case 'a':
      break;
    case 's':
      break;
    case 'd':
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

void mouse_down(int button, int key_state, int x, int y) {
  if(button == GLUT_LEFT_BUTTON && button == GLUT_DOWN) {
    state.mouse_x = x;
    state.mouse_y = y;
  }
}

void motion(int x, int y) {
  float dx = x - state.mouse_x;
  float dy = y - state.mouse_y;
  
  state.mouse_x = x;
  state.mouse_y = y;
  
  float change_x = fabs(dx/(state.width/2));
  float change_y = fabs(dy/(state.height/2));
  
  int up = dy < 0;
  int right = dx > 0;
  
  
  state.camera.pitch += up ? -change_y*90 : change_y*90;
  state.camera.yaw += right ? change_x*90 : -change_x*90;
  
  if(state.camera.pitch > 360) {
    state.camera.pitch -= 360;
  } else if (state.camera.pitch < 0) {
    state.camera.pitch += 360;
  }
  
  if(state.camera.yaw > 360) {
    state.camera.yaw -= 360;
  } else if (state.camera.yaw < 0) {
    state.camera.yaw += 360;
  }
}