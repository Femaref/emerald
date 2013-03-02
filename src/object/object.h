#ifndef OBJECT_H_
#define OBJECT_H_

#define MAX_VERTICES 2000
#define MAX_POLYGONS 2000

#include "polygon.h"
#include "vertex.h"

typedef struct {
    vertex_type vertex[MAX_VERTICES];
    polygon_type polygon[MAX_POLYGONS];
} obj_type,*obj_type_ptr;

#endif // OBJECT_H_