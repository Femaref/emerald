#include <stdio.h>
#include <GLUT/glut.h>

#include <engine.h>
#include <ui.h>

int main(int argc, char **argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(640, 480);
   glutInitWindowPosition(0,0);
   glutCreateWindow("main");
   
   glutDisplayFunc(engine_display);
   glutIdleFunc(engine_display);
   glutReshapeFunc(engine_resize);
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(keyboard_s);
   
   engine_init(640, 480);
   glutMainLoop();

  return 0;
}