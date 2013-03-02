#include "engine.h"
#include <state.h>
#include <model.h>
#include <GLUT/glut.h>

void engine_init(int width, int height) {
  state.width = width;
  state.height = height;


  glClearColor(0.0, 0.0, 0.2, 0.0);
  glShadeModel(GL_SMOOTH);
  glViewport(0,0,width,height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,1.0f,1000.0f);
  glEnable(GL_DEPTH_TEST);
  glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
}

void render_cube(void) {
  glBegin(GL_TRIANGLES);
  for (int l_index=0;l_index<12;l_index++) {
    glColor3f(1.0,0.0,0.0);
    glVertex3f(state.cube.vertex[state.cube.polygon[l_index].a].x, state.cube.vertex[ state.cube.polygon[l_index].a ].y, state.cube.vertex[ state.cube.polygon[l_index].a ].z);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(state.cube.vertex[ state.cube.polygon[l_index].b ].x, state.cube.vertex[ state.cube.polygon[l_index].b ].y, state.cube.vertex[ state.cube.polygon[l_index].b ].z);
    glColor3f(0.0,0.0,1.0);
    glVertex3f( state.cube.vertex[ state.cube.polygon[l_index].c ].x, state.cube.vertex[ state.cube.polygon[l_index].c ].y, state.cube.vertex[ state.cube.polygon[l_index].c ].z);
  }
  glEnd();
}

void engine_camera(void) {
  glRotatef(state.camera.pitch, 1.0f, 0.0f, 0.0f);
  glRotatef(state.camera.yaw, 0.0f, 1.0f, 0.0f);
  glRotatef(state.camera.roll, 0.0f, 0.0f, 1.0f);
  glTranslatef(-state.camera.x, -state.camera.y, -state.camera.z);
}


void engine_display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);

  for(int x = 0; x < 4; x++) {
    for(int y = 0; y < 4; y++) {
      for(int z = 0; z < 4; z++) {
        glLoadIdentity();
        engine_camera();
        glTranslatef(0 + 20*x,0+20*y,0 + 20*z);
        
        render_cube();
      }
    }
  }
  
  glFlush();
  glutSwapBuffers();
}

void engine_resize(int width, int height)
{
  state.width = width;
  state.height = height;

  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0,0,width,height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,1.0f,1000.0f);
  glutPostRedisplay ();
}