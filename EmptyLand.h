#ifndef EMPTYLANDNODE_H
#define EMPTYLANDNODE_H

#include "stdafx.h"
#include "MapNode.h"

class EmptyLand:public MapNode{
	public:
		EmptyLand(int x, int y, unsigned int PickingColour[]);

		void Draw();
};

#endif
