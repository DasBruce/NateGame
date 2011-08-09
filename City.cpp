#include "City.h"

using namespace std;

City::City(){
	Population = 1000;
	Traversable = false;
	Type = CITY;
}

City::City(int Population, int PlayerOwner, int x, int y){
	City();
	this->Population = Population;
	this->PlayerOwner = PlayerOwner;
	this->x = x;
	this->y = y;
	cout << "New City founded, population = " << this->Population << endl;
}

void City::Update(){
	cout << "Updating city" << endl;
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
