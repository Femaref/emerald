#include <stdio.h>
#include <GLUT/glut.h>

#include <engine.h>
#include <ui.h>
#include <state.h>

int main(int argc, char **argv) {
    state_init();

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
   glutMouseFunc(mouse_down);
   glutMotionFunc(motion);
   
   engine_init(640, 480);
   glutMainLoop();

  return 0;
}