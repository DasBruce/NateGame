#ifndef EMPTYLANDNODE_H
#define EMPTYLANDNODE_H

#include "stdafx.h"
#include "MapNode.h"

class EmptyLand:public MapNode{
	public:
		EmptyLand(int x, int y){this->x=x; this->y=y;}
		void Draw();
};

#endif
