#ifndef CITY_H
#define CITY_H

#include "stdafx.h"
#include "MapNode.h"

class City:public MapNode{
	public:
		City();
		City(int Population, int PlayerOwner, int x, int y);
		void Draw();
		void Update();
	private:
		int FertileLand;
		int Farms;
		int FishingFleets;
		float TaxRate;
		
};

#endif
