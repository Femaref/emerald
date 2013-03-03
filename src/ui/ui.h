#ifndef UI_H_
#define UI_H_

void keyboard (unsigned char key, int x, int y);
void keyboard_s (int key, int x, int y);
void motion (int x, int y);
void mouse_down(int button, int key_state, int x, int y);

#endif // UI_H_