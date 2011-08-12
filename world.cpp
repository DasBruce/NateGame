#include "world.h"

using namespace std;

World::World(){
	PickingColour[0] = 1;
	PickingColour[0] = 1;
	PickingColour[0] = 1;
	cout << "Creating world" << endl;
	cout << "Press Enter to end the turn" << endl;
	for( int i=0; i<HEIGHT; i++){
		for( int j=0; j<WIDTH; j++){
			EnsureUniquePickingColour();
			MapNodes.push_back(new EmptyLand(j, i, PickingColour));
		}
	}

	start = 0;
	finish = 14;

	CreateCity(141, 10000, 0, string("Dunedin"));
//    cout << MapNodes[141]->name << endl;
	CreateCity(62, 7000, 1, string("Christchurch"));
	CreateCity(57, 7000, 1, string("Hamilton"));
}

void World::MouseHandler(int Button, int Press){
	if(Press == GLFW_PRESS){
		if(Button == GLFW_MOUSE_BUTTON_LEFT){
			Draw(RENDERMODEPICK);
		}
	}
}

void World::Update(){
	Draw();
    TwDraw();
}

void World::EndTurn(){
	cout << "End Turn" << endl;
	UpdateEconomicInfluence();
	UpdateOwnership();
	for(int i=0;i<MAPSIZE;i++){
		MapNodes[i]->Update();
	}
}

void World::UpdateOwnership(){
	for(int i=0;i<MAPSIZE;i++){
		if(MapNodes[i]->PlayerOwner == UNOWNED){
			for(int j=0;j<NUMPLAYERS;j++){
				if(MapNodes[i]->EconomicInfluence[j] > OWNERSHIPTHRESHOLD){
					MapNodes[i]->PlayerOwner = j;
					cout << MapNodes[i]->PlayerOwner << endl;
				}
			}
		}
		// else{
			// for(int j=0;j<NUMPLAYERS;j++){
				// if(MapNodes[i]->EconomicInfluence[j] < OWNERSHIPLOSSTHRESHOLD){
					// MapNodes[i]->PlayerOwner == j;
				// }
			// }
		// }
	}
}

void World::UpdateEconomicInfluence(){
	// Reset the EI for all nodes, NOTE: might change this later to have a historical effect
	for(int i=0;i<MAPSIZE;i++){
        for(int j=0;j<NUMPLAYERS;j++){
            MapNodes[i]->EconomicInfluence[j] = 0;
        }
	}
	// Go through all nodes and calculate distance from the cities
	for(int i=0;i<MAPSIZE;i++){
		for(int j=0;j<Cities.size();j++){
			float dist = distind(i, Cities[j]);
			if(MapNodes[Cities[j]]->PlayerOwner == 0)
				MapNodes[i]->EconomicInfluence[MapNodes[Cities[j]]->PlayerOwner] += MapNodes[Cities[j]]->Population/(10000*dist);
			else if(MapNodes[Cities[j]]->PlayerOwner == 1)
				MapNodes[i]->EconomicInfluence[MapNodes[Cities[j]]->PlayerOwner] += MapNodes[Cities[j]]->Population/(10000*dist);
		}
	}
}
// Keyboard Handler
void World::KeyDown(int KeyID, bool Down){
//	if(KeyID == VK_RETURN && Down == true){
//		EndTurn();
//	}
}
// A* pathfinding
void World::CalculatePath(int s, int f){
// Navigate
	open.push_back(start);

	while(true){
		// PrintOpenClosed();

		if(open.size() == 0){
			cout << "No open nodes" << endl;
			break;
		}
		int lowest = FindLowestF();
		if(open.at(lowest) == finish){
			cout << "Lowest open node is finish" << endl;
			break;
		}
		// Add the node with lowest F cost and move it to the closed list
		closed.push_back(open.at(lowest));
		open.erase(open.begin()+lowest);

		// Swap index in open lowest for node index lowest
		lowest = closed.back();
		// Neighbours
		int bl = lowest-WIDTH-1;
		int bc = lowest-WIDTH;
		int br = lowest-WIDTH+1;
		int l  = lowest-1;
		int r  = lowest+1;
		int ul = lowest+WIDTH-1;
		int uc = lowest+WIDTH;
		int ur = lowest+WIDTH+1;

		// Check that each neighbouring node is withing the boundaries and is not in the open or closed lists
		// Add the index to the open list, set ParentID, parent direction and calculate F,G and H
		if(lowest > WIDTH && lowest%WIDTH != 0) 		//LL
			if(IsInOpenList(bl) == false && IsInClosedList(bl) == false && MapNodes.at(bl)->Traversable){
				open.push_back(bl);
				MapNodes.at(bl)->SetParentDirection(BELOWLEFT);
				MapNodes.at(bl)->ParentID = lowest;
				CalculateFGH(bl);
			}
		if(lowest > WIDTH)
			if(IsInOpenList(bc) == false && IsInClosedList(bc) == false && MapNodes.at(bc)->Traversable){
				open.push_back(bc);
				MapNodes.at(bc)->SetParentDirection(BELOW);
				MapNodes.at(bc)->ParentID = lowest;
				CalculateFGH(bc);
			}
		if(lowest > WIDTH && lowest%WIDTH != WIDTH-1)
			if(IsInOpenList(br) == false && IsInClosedList(br) == false && MapNodes.at(br)->Traversable){
				open.push_back(br);
				MapNodes.at(br)->SetParentDirection(BELOWRIGHT);
				MapNodes.at(br)->ParentID = lowest;
				CalculateFGH(br);
			}
		if(lowest%WIDTH != 0)
			if(IsInOpenList(l) == false && IsInClosedList(l) == false && MapNodes.at(l)->Traversable){
				open.push_back(l);
				MapNodes.at(l)->SetParentDirection(LEFT);
				MapNodes.at(l)->ParentID = lowest;
				CalculateFGH(l);
			}
		if(lowest%WIDTH != WIDTH-1)
			if(IsInOpenList(r) == false && IsInClosedList(r) == false && MapNodes.at(r)->Traversable){
				open.push_back(r);
				MapNodes.at(r)->SetParentDirection(RIGHT);
				MapNodes.at(r)->ParentID = lowest;
				CalculateFGH(r);
			}
		if(lowest < MAPSIZE-WIDTH && lowest%WIDTH != 0)
			if(IsInOpenList(ul) == false && IsInClosedList(ul) == false && MapNodes.at(ul)->Traversable){
				open.push_back(ul);
				MapNodes.at(ul)->SetParentDirection(ABOVELEFT);
				MapNodes.at(ul)->ParentID = lowest;
				CalculateFGH(ul);
			}
		if(lowest < MAPSIZE-WIDTH)
			if(IsInOpenList(uc) == false && IsInClosedList(uc) == false && MapNodes.at(uc)->Traversable){
				open.push_back(uc);
				MapNodes.at(uc)->SetParentDirection(ABOVE);
				MapNodes.at(uc)->ParentID = lowest;
				CalculateFGH(uc);
			}
		if(lowest < MAPSIZE-WIDTH && lowest%WIDTH != WIDTH-1)
			if(IsInOpenList(ur) == false && IsInClosedList(ur) == false && MapNodes.at(ur)->Traversable){
                open.push_back(ur);
                MapNodes.at(ur)->SetParentDirection(ABOVERIGHT);
                MapNodes.at(ur)->ParentID = lowest;
                CalculateFGH(ur);
			}
	}
	int id = finish;
	while(true){
		path.push_back(id);
		id = MapNodes.at(id)->ParentID;
		if(id == start)
			path.push_back(id);
			break;
	}
}

void World::CalculateFGH(int id){
	if(MapNodes.at(id)->DiagonalParent())
		MapNodes.at(id)->G = MapNodes.at(MapNodes.at(id)->ParentID)->G + 14;
	else
		MapNodes.at(id)->G = MapNodes.at(MapNodes.at(id)->ParentID)->G + 10;

	int c = finish-id;
	MapNodes.at(id)->H = (c/WIDTH+c%WIDTH)*10;
	if(MapNodes.at(id)->H < 0)
		MapNodes.at(id)->H*=-1;
	if(MapNodes.at(id)->G < 0)
		MapNodes.at(id)->G*=-1;


	MapNodes.at(id)->F = MapNodes.at(id)->G + MapNodes.at(id)->H;
}

bool World::IsInOpenList(int id){
	for(int i=0;i<open.size();i++){
		if(open.at(i) == id)
			return true;
	}
	return false;
}

bool World::IsInClosedList(int id){
	for(int i=0;i<closed.size();i++){
		if(closed.at(i) == id)
			return true;
	}
	return false;
}

// Returns the index in _open_ of the lowest F cost node
int World::FindLowestF(){
	int id = 0;
	// Get first index from open nodes
	int F = MapNodes.at(open.at(0))->F;

	for(int i=0; i<open.size(); i++){
		if(MapNodes.at(open.at(i))->F < F){
			id = i;
			F = MapNodes.at(open.at(i))->F;
		}
	}
	return id;
}

void World::CreateCity(int Index, int Population, int PlayerOwner, string name){
    unsigned int TempPickingColour[3];
    TempPickingColour[0] = MapNodes[Index]->PickingColour[0];
    TempPickingColour[1] = MapNodes[Index]->PickingColour[1];
    TempPickingColour[2] = MapNodes[Index]->PickingColour[2];

	delete MapNodes[Index];
	MapNodes[Index] = new City(Population, PlayerOwner, xcom(Index), ycom(Index), name);
    MapNodes[Index]->PickingColour[0] = TempPickingColour[0];
    MapNodes[Index]->PickingColour[1] = TempPickingColour[1];
    MapNodes[Index]->PickingColour[2] = TempPickingColour[2];
	Cities.push_back(Index);
}


void World::Draw(int RenderMode){
    // reset view matrix
    glLoadIdentity();
    // move view back a bit
    glTranslatef(0, 0, -30);
	glEnable(GL_DEPTH_TEST);
	if(RenderMode == RENDERMODEDRAW){
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_COLOR_MATERIAL);
	}
	else if(RenderMode == RENDERMODEPICK){
		glDisable(GL_LIGHTING);
		glDisable(GL_LIGHT0);
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(-WIDTH/2,-HEIGHT/2,-30.0f);
	for( int i=0; i<MAPSIZE; i++){
		if(RenderMode == RENDERMODEDRAW){
			MapNodes[i]->Draw();
		}
		else if(RenderMode == RENDERMODEPICK){
			MapNodes[i]->Picking();

		}
	}
    glPopMatrix();
    if(RenderMode == RENDERMODEPICK){
        unsigned char pixels[] = {0, 0, 0};
		glfwGetMousePos(&mx, &my);
        glReadPixels(mx, 768-my, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &pixels);
		// cout << "Mouse = [" << mx << ", " << 768-my << "]" << endl;
        // cout << "[" << (int)pixels[0] << ", " << (int)pixels[1] << ", " << (int)pixels[2] << "]" << endl;
        for( int i=0; i<MAPSIZE; i++){
            if((int)pixels[0] == MapNodes[i]->PickingColour[0] && (int)pixels[1] == MapNodes[i]->PickingColour[1] && (int)pixels[2] == MapNodes[i]->PickingColour[2]){
                int Position[2];
                int Size[2];
                TwGetParam(MapNodes[i]->ControlPanel, NULL, "position", TW_PARAM_INT32, 2, Position);
                TwGetParam(MapNodes[i]->ControlPanel, NULL, "size", TW_PARAM_INT32, 2, Size);
                if(IsInQuad(mx, my, Position[0], Position[1], Size[0], Size[1]) == false){
                    MapNodes[i]->Selected = !MapNodes[i]->Selected;
                    cout << "name is " << MapNodes[i]->name << endl;
//                    TwDefine(MapNodes[i]->name) + string(" visible=false "));   // mybar is displayed again
                }
            }
        }
    }
}

void World::EnsureUniquePickingColour(){
	PickingColour[0] += 1;
	if(PickingColour[0] > 255){
		PickingColour[0] = 1;
		PickingColour[1] += 1;
	}
	if(PickingColour[1] > 255){
		PickingColour[1] = 1;
		PickingColour[2] += 1;
	}
	if(PickingColour[2] > 255){
		while(true){
			cout << "Oh shit! ";
		}
	}
}

