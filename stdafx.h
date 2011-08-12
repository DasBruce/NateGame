#ifndef STDAFX_H
#define STDAFX_H

#include <GL/glfw.h>
#include <stdlib.h>
#include <list>
#include <ctime>
#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <AntTweakBar.h>

#include "vector3f.h"

// PLAYERS
#define NUMPLAYERS 2

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

#define UNOWNED -1

#define OWNERSHIPTHRESHOLD 0.6
#define OWNERSHIPLOSSTHRESHOLD 0.02

// RENDERING
#define RENDERMODEDRAW 1
#define RENDERMODEPICK 2

#endif
