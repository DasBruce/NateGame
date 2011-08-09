#ifndef STDAFX_H
#define STDAFX_H

#include <windows.h>		// Header File For Windows
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <list>
#include <ctime>
#include <vector>
#include <math.h>
#include <iostream>

#include "vector3f.h"

// PATHFINDING
#define MAPSIZE 256
#define WIDTH 16
#define HEIGHT 16

#define NOPARENT 0
#define ABOVERIGHT 1
#define ABOVE 2
#define ABOVELEFT 3
#define RIGHT 4
#define LEFT 5
#define BELOWRIGHT 6
#define BELOW 7
#define BELOWLEFT 8

// MAP NODE TYPES
#define EMPTY 1
#define CITY 2

#endif
