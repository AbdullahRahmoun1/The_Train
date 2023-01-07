#include "Chess.h"


Chess::Chess(double size)
	{
		this->size = size;
		point[0] = Point(-size / 2, size / 2);
		point[1] = Point(size / 2, size / 2);
		point[2] = Point(size / 2, -size / 2);
		point[3] = Point(-size / 2, -size / 2);
	}
	void Chess::builder()
	{
		glColor3d(1, 1, 1);
		glBindTexture(GL_TEXTURE_2D, LoadTexture("chess.bmp", 255));
		glBegin(GL_QUADS);
		glTexCoord2d(0, 2);
		glVertex2d(this->point[0].x, this->point[0].y);
		glTexCoord2d(2, 2);
		glVertex2d(this->point[1].x, this->point[1].y);
		glTexCoord2d(2, 0);
		glVertex2d(this->point[2].x, this->point[2].y);
		glTexCoord2d(0, 0);
		glVertex2d(this->point[3].x, this->point[3].y);
		glEnd();

	}

Chess::Chess()
{
}


Chess::~Chess()
{
}
