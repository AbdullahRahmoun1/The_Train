#pragma once
class ProjectTextures
{
	
public:
	//abdullah
	static int wood,out,door,rdoor,groundTex
		,connecterGroundTex,carpetTex,seatTex
		,seatBackTex,enginsTex,mainDoorLeft
		,mainDoorRight,curtainTexture;
	//adnan
	static int bedRoomB1tex , bedRoomMattresstex , bedRoomPillowtex ,bedRoomTable ,bedRoomChair,bedRoomTest,bedRoomKeytex,bedRoomBlack,bedRoomRobic,bedRoomChess;
	static int bedRoomScreen[2];
	//mousa 
	static int woodsTex, boxTex1, boxTex2, ladderTex, stepTex, frameTex, nightTex, monaTex;
	//alaa
	static int cloast , table1, control, out1,out2;
	//omran
	int back, front, left, right, top, bottom;
	int wall, flooor, rooof, left_floor, out_tunnel, ground, grass, grass2, bridge, sea;
	int house_front, house_side, house_roof;
	int house_front2, house_side2, house_roof2;
	int house_front3, house_side3, house_roof3;
	int house_front5, house_side5, house_roof5;
	int building;
	int building2;
	int building3;
	int building4;
	int house_front6;
	int house_front7;
	int house_front8;
	int skybox_texture;
	//example
	static int somethingWood,somethingMetal,somethingSomething;//declare here 
	ProjectTextures(void);
	static void initialize();	
	virtual ~ProjectTextures(void);
};

