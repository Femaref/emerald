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

void render_cube(float r, float g, float b) {
  glBegin(GL_TRIANGLES);
  glColor3f(r, g, b);
  for (int l_index=0;l_index<12;l_index++) {  
    glVertex3f(state.cube.vertex[state.cube.polygon[l_index].a].x, state.cube.vertex[ state.cube.polygon[l_index].a ].y, state.cube.vertex[ state.cube.polygon[l_index].a ].z);
    glVertex3f(state.cube.vertex[ state.cube.polygon[l_index].b ].x, state.cube.vertex[ state.cube.polygon[l_index].b ].y, state.cube.vertex[ state.cube.polygon[l_index].b ].z);
    glVertex3f( state.cube.vertex[ state.cube.polygon[l_index].c ].x, state.cube.vertex[ state.cube.polygon[l_index].c ].y, state.cube.vertex[ state.cube.polygon[l_index].c ].z);
  }
  glEnd();
}

void engine_camera(void) {
  glRotatef(360 - state.camera.pitch, 1.0f, 0.0f, 0.0f);
  glRotatef(360 - state.camera.yaw, 0.0f, 1.0f, 0.0f);
  glRotatef(360 - state.camera.roll, 0.0f, 0.0f, 1.0f);
  glTranslatef(-state.camera.x, -state.camera.y, -state.camera.z);
}


void engine_display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  
  glLoadIdentity();
  engine_camera();
  glTranslatef(0, 0, 0);   
  render_cube(1.0, 0.0, 0.0);
  
  glTranslatef(0, 0, 0);   
  render_cube(1.0, 0.0, 0.0);
  
  glTranslatef(0, 0, -200);   
  render_cube(0.0, 1.0, 0.0);
  
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