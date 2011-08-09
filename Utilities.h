#ifndef UTILITIES_H
#define UTILITIES_H

#include "stdafx.h"

// Utility functions
static inline int xcom(int index){
	return index%WIDTH;
}
static inline int ycom(int index){
	return index/WIDTH;
}
static inline int ind(int x, int y){
	return x+WIDTH*y;
}

static inline float distxy(int a, int b, int c, int d){
	float x1=a, y1=b, x2=c, y2=d;
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
static inline float distind(int index1, int index2){
	return distxy(xcom(index1), ycom(index1), xcom(index2), ycom(index2));
}

#endif
