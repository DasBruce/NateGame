#ifndef MAPNODE_H
#define MAPNODE_H

#include "stdafx.h"

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
		float Population;
		float P1Influence;
		float P2Influence;

		void Init(float x, float y);
		virtual void Update();
		virtual void Draw();
		// Getters
		// Setters
		void SetColour(float r, float g, float b){ red=r; green=g; blue=b; }
		void SetParentDirection(int dir){ ParentDirection=dir; }
		bool DiagonalParent();

        float red,green,blue;
		float x, y;
};

#endif
