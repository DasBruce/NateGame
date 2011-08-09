#include "EmptyLand.h"

void EmptyLand::Draw(){
    glPushMatrix();
        glTranslatef( x, y, 0.0f);
		glColor3f(EconomicInfluence[0], 0.36, EconomicInfluence[1]);

        glBegin(GL_QUADS);
        glVertex3f(-0.5, 0.5, 0);
        glVertex3f( 0.5, 0.5, 0);
        glVertex3f( 0.5,-0.5, 0);
        glVertex3f(-0.5,-0.5, 0);
        glEnd();

		if(PlayerOwner == 0)
			glColor3f(1, 0, 0);
		else if(PlayerOwner == 1)
			glColor3f(0, 0, 1);

        glBegin(GL_LINE_LOOP);
        glVertex3f(-0.49, 0.49, 0.1);
        glVertex3f( 0.49, 0.49, 0.1);
        glVertex3f( 0.49,-0.49, 0.1);
        glVertex3f(-0.49,-0.49, 0.1);
        glEnd();
    glPopMatrix();
}
