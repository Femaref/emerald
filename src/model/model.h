#ifndef MODEL_H_
#define MODEL_H_

#define MAX_VERTICES 2000
#define MAX_POLYGONS 2000

#include "polygon.h"
#include "vertex.h"

typedef struct {
    vertex_type vertex[MAX_VERTICES];
    polygon_type polygon[MAX_POLYGONS];
} model_type,*model_type_ptr;

#endif // MODEL_H_