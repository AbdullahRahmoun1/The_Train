#pragma once
#include "Point2.h"
class UltimateCamera
{
public:
	UltimateCamera();
	~UltimateCamera();
	static double walkX, walkZ, breath, turn, updown, height;
	static bool moving,firstPerson;
	
	static void cameraSitting(bool keys[], HWND hWnd);
	static bool canGoFor, canGoBack, canGoRight, canGoLeft;
	static double mouseX, mouseY, screenX, screenY;
};

