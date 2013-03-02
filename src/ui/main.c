#include <stdio.h>
#include <GLUT/glut.h>

#include <engine.h>

int main(int argc, char **argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(640, 480);
   glutInitWindowPosition(0,0);
   glutCreateWindow("main");
   
   glutDisplayFunc(engine_display);
   glutIdleFunc(engine_display);
   
   init();
   glutMainLoop();

  return 0;
}