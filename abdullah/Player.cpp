#include "Player.h"
#include "UltimateCamera.h"
#include <math.h>

int face=0;
bool Player::swapMoving=false;
double Player::RightHand=0;
double Player::LeftHand=0;
double Player::RightLeg=0;
double Player::leftLeg=0;
double Player::value=0.8;
void Player::drawAndManage(void)
{
	
			double faceWidth = 0.3 , faceThikness = 0.2;
			glPushMatrix();
	

			glTranslated(UltimateCamera::walkX,UltimateCamera::height+0.2*fabs(cos(UltimateCamera::breath))-0.2,UltimateCamera::walkZ+0.27);
	 
			glScaled(1.3,1.3,1.3);

			glRotated(-57.3*UltimateCamera::turn,0,1,0);

			glRotated(180,0,1,0);

				glBindTexture(GL_TEXTURE_2D,435345);
	
				glPushMatrix();

					if(swapMoving)
					{
						value*=-1;
					}
					if(RightHand>=20 || RightHand<=-20)
						swapMoving = !swapMoving;
					if(UltimateCamera::moving && UltimateCamera::firstPerson)
					{
						RightHand += value;
						LeftHand -= value;
						RightLeg -= value;
						leftLeg += value;
					}

					// Head
					if(!UltimateCamera::firstPerson)
					{
						Board head = Board(faceWidth,faceWidth,faceThikness,true);
						head.SetColor(0.9, 0.5, 0.15);
						head.face[0] = false;
						head.isHuman();
						head.build();
						head.face[0] = true;
						head.face[1] = false;
						head.face[2] = false;
						head.face[3] = false;
						head.face[4] = false;
						head.face[5] = false;
						head.SetTexture(face);
						head.Rotate(0,0,180);
						head.build();
					}
				glPopMatrix();
				// upper body
				glBindTexture(GL_TEXTURE_2D,3534534);
				Board up = Board(2*faceWidth,1.2*faceWidth,1.2*faceThikness,true);
				up.SetColor(0, 0, 0.7);
				up.Translate(0,-3*faceWidth/2,0.1*faceThikness);
				up.build();
				// hands
				glPushMatrix();
					glTranslated(-0.8*faceWidth,-0.8*faceWidth,-0.8*faceThikness);
					glRotated(-75+RightHand,1,0,0);
					glTranslated(0.8*faceWidth,0.8*faceWidth,0.8*faceThikness);
					up.width*=0.8;
					up.length*=0.25;
					up.thikness*=0.3;
					up.SetColor(0.9, 0.5, 0.15);
					up.Translate(-0.77*faceWidth,-2.3*faceWidth,-0.2*faceThikness);
					up.build();
				glPopMatrix();
				glPushMatrix();
					glTranslated(-0.8*faceWidth,-0.8*faceWidth,-0.8*faceThikness);
					glRotated(-75+LeftHand,1,0,0);
					glTranslated(0.8*faceWidth,0.8*faceWidth,0.8*faceThikness);
					up.Translate(0.75*faceWidth,-2.3*faceWidth,-0.2*faceThikness);
					up.build();
				glPopMatrix();
				// legs
				glPushMatrix();
					glTranslated(-faceWidth/2,-2.6*faceWidth,-0.5*faceThikness);
					glRotated(leftLeg,1,0,0);
					glTranslated(faceWidth/2,2.6*faceWidth,0.5*faceThikness);
					up.Translate(-faceWidth/3,-3.25*faceWidth,-0.35*faceThikness);
					up.build();
				glPopMatrix();
				glPushMatrix();
					glTranslated(-faceWidth/2,-2.6*faceWidth,-0.5*faceThikness);
					glRotated(RightLeg,1,0,0);
					glTranslated(faceWidth/2,2.6*faceWidth,0.5*faceThikness);
					up.Translate(faceWidth/3,-3.25*faceWidth,-0.35*faceThikness);
					up.build();
				glPopMatrix();
			glPopMatrix();
}


Player::~Player(void)
{
}
