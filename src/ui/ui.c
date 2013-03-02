#include <stdlib.h>

void keyboard (unsigned char key, int x, int y) {
  switch(key) {
    case 'q':
      exit(0);
      break;
    default:
      break;
  }
}
void keyboard_s (int key, int x, int y) {
}