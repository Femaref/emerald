#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GLUT/glut.h>

#include <matrix.h>

#include "ui.h"
#include "state.h"


void keyboard (unsigned char key, int x, int y) {
  vector *vec = camera_direction(-state.camera.pitch, state.camera.yaw, state.camera.roll);
  print_vector(vec);
  
  scale(vec, 10);
  
  printf("pitch: %f, yaw: %f\n", state.camera.pitch, state.camera.yaw);

  switch(key) {
    case 'q':
      exit(0);
      break;
    case 'w':
      state.camera.x += vec->data[0];
      state.camera.y += vec->data[1];
      state.camera.z += vec->data[2];
      break;
    case 'a':
      break;
    case 's':
      state.camera.x -= vec->data[0];
      state.camera.y -= vec->data[1];
      state.camera.z -= vec->data[2];
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
  
  free_vector(vec);
  printf("x: %f, y: %f, z: %f\n", state.camera.x, state.camera.y, state.camera.z);
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
  
  
  state.camera.pitch += up ? change_y*90 : -change_y*90;
  state.camera.yaw += right ? -change_x*90 : change_x*90;
  
  printf("pitch: %f, yaw: %f\n", state.camera.pitch, state.camera.yaw);
  
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