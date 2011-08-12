#ifndef WORLD_H
#define WORLD_H

#include "stdafx.h"
#include "MapNode.h"
#include "Utilities.h"
#include "City.h"
#include "EmptyLand.h"

class World{
    public:
        World();
		void MouseHandler(int Button, int Press);
        void Update();
		void EndTurn();
		void KeyDown(int KeyID, bool Down);

		int GLHeight;
		int GLWidth;
		void Draw(int RenderMode = RENDERMODEDRAW);

		int mx;
		int my;
    private:
	    int prevTime;
        int diffTime;

		int start;
		int finish;

		double speed;
		bool wire;
		double old_time;

		unsigned int PickingColour[3];
		void EnsureUniquePickingColour();

		std::vector<MapNode*> MapNodes;
		std::vector<int> Cities;
		std::vector<int> open;
		std::vector<int> closed;
		std::vector<int> path;

		void CreateCity(int Index, int Population, int PlayerOwner, string name);

		int FindLowestF();
		bool IsInOpenList(int id);
		bool IsInClosedList(int id);
		void CalculateFGH(int id);
		void UpdateEconomicInfluence();
		void UpdateOwnership();
		void CalculatePath(int s, int f);
};

#endif
