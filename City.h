#ifndef CITY_H
#define CITY_H

#include "stdafx.h"
#include "MapNode.h"

class City:public MapNode{
	public:
		City();
		City(int Population, int PlayerOwner, int x, int y);
		int Population;
		void Update();
		void Draw();
};

#endif
