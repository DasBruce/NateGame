#ifndef MAPNODE_H
#define MAPNODE_H

#include "stdafx.h"

using namespace std;

class MapNode{
    public:
        MapNode();
        // ~MapNode(){}

		int F,G,H;
        int ParentID;
		int ParentDirection;
		bool Traversable;

		int Type;
		int PlayerOwner;
		int Population;
		float EconomicInfluence[NUMPLAYERS];
		float Fertility;

		unsigned int PickingColour[3];
		bool Selected;
		TwBar* ControlPanel;
		string name;

		void Init(float x, float y);
		virtual void Update();
		virtual void Draw();
		virtual void Picking();
		// Getters
		// Setters
		void SetColour(float r, float g, float b){ red=r; green=g; blue=b; }
		void SetParentDirection(int dir){ ParentDirection=dir; }
		bool DiagonalParent();

        float red,green,blue;
		float x, y;
};

#endif
