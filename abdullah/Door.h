#pragma once
class Door
{
public:
	static double  thikness,width,height;
	static int pzListId,nzListId;
	double angle,openingSpeed;
	int status,door,rdoor;
	bool PZ;
	Door(void);
	Door(bool PZ,int door,int rdoor);
	void draw();
	void open();
	void close();
	void manageMovment();
	virtual ~Door(void);
};
