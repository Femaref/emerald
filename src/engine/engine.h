#ifndef ENGINE_H_
#define ENGINE_H_

void engine_init(int width, int height);
void engine_display(void);
void engine_resize(int width, int height);

void engine_camera();

void render_cube(float r, float g, float b);


#endif // ENGINE_H_
