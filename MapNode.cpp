#include "MapNode.h"
#define PI 3.14159265

using namespace std;

MapNode::MapNode(){
    red = 1;
    blue = 1;
    green = 1;
	x = 0;
	y = 0;
	F = 0;
	G = 0;
	H = 0;
	ParentDirection = NOPARENT;
	ParentID = -1;
	Population = 0;
	Traversable = true;
	Type = EMPTY;
	PlayerOwner = UNOWNED;
}

void MapNode::Init(float x, float y){
	this->x = x;
	this->y = y;
}

void MapNode::Draw(){
    glPushMatrix();
        glTranslatef( x, y, 0.0f);
		// glColor3f(P1Influence, 0.36, P2Influence);
		// if(P1Influence > 0.5)
			// glColor3f(0.7, 0, 0);
		// else if(P2Influence > 0.5)
			glColor3f(1, 1, 1);
        glBegin(GL_QUADS);
        glVertex3f(-0.5, 0.5, 0);
        glVertex3f( 0.5, 0.5, 0);
        glVertex3f( 0.5,-0.5, 0);
        glVertex3f(-0.5,-0.5, 0);
        glEnd();
    glPopMatrix();
}

void MapNode::Update(){
}

bool MapNode::DiagonalParent(){
	if(ParentDirection == ABOVERIGHT ||
	   ParentDirection == ABOVELEFT ||
	   ParentDirection == BELOWRIGHT ||
	   ParentDirection == BELOWLEFT)
		return true;
	else
		return false;
}
