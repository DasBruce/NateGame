#include "City.h"

using namespace std;

City::City(){
	Population = 1000;
	Traversable = false;
}

City::City(int Population, int PlayerOwner, int x, int y){
	City();
	this->Population = Population;
	this->PlayerOwner = PlayerOwner;
	this->x = x;
	this->y = y;
	Type = CITY;
	FertileLand = 0;
	Farms = 0;
	FishingFleets = 0;
	TaxRate = 0.01;
}

void City::Update(){
	cout << "Population = " << (float)Population << endl;
	// cout << "Population growth = " << 1.05-TaxRate-((float)Population/1000000) << endl;
	Population *= (1.05-TaxRate-((float)Population/250000));//-Population/1000000);
}

void City::Draw(){
    glPushMatrix();
        glTranslatef( x, y, 0.0f);
		glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_QUADS);
        glVertex3f(-0.5, 0.5, 0);
        glVertex3f( 0.5, 0.5, 0);
        glVertex3f( 0.5,-0.5, 0);
        glVertex3f(-0.5,-0.5, 0);
        glEnd();
    glPopMatrix();
}
