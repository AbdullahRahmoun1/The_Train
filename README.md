**Intro** 

a C++ ( OpenGl ) game built by a group of students for a university project . 

The game will take you on a trip on the train where you can discover the train from inside and see the outside world from the windows …. 

**The train consists of :** 

- 4 Passenger cars 
- 2 Sleeping cars 
- 2 Kitchen cars 
- 2 Cargo cars 
- A driving car 

**Outside world consists of :** 

- Train station
- Rural area 
- City area 
- Sea area 

**Project anatomy** 

The main classes are : 

- TrainCar.cpp 
- Train.cpp 
- Environment.cpp 
- UltimateCamera.cpp 
- ProjectTextures.cpp 


**TrainCar** : 

It is the base class for the train cars . it has the methods to draw the external structure of the train car with its doors and windows and has a way to interact with these objects and it has a collision detection methods for the walls . 

Classes : ( PassengersCar.cpp , KitchenCar.cpp , BedRoomCar.cpp , CargoCar.cpp ) Extends this class and add to it the methods to draw the décor and interact with it . 

**Train.cpp :** 

This class has contains the cars objects and it is responsible for managing this cars ( moving , drawing , interaction , collision ) 

Important methods : 

- **Void Train::initialize()** it initializes the trainCars and the display lists for the cars 
- **Void Train::draw()** it draws all the cars (by calling .draw on them) 
- **Void Train::interact(bool keys[])** it manages interacting with the cars (doors , windows , closets )  

**Environment.cpp :** 

This class contains the methods to draw the areas of the environment 

Important methods : 

- **Void Environment::initialize()** it initialize the textures and the tree model 
- **Void Environment::draw()** it draws the environment 
- **Void Environment::translate(double z)** it moves the area by z 

**UltimateCamera.cpp :** 

this class contains all the methods responsible for moving the camera around 

and it has the functions that controls the character movement and looking around 

the camera was attached to the mouse so you can use it to navigate your surroundings with a free 360 degree view

**important methods :** 

- **UltimateCamera::cameraSitting(bool keys[], HWND hWnd)** the method we call in every frame to handle the camera movement**  

**ProjectTextures.cpp :** 

A simple class that contains all the textures used in the project with an Initialize method to let openGl load the images when this method is called ( start of program ) 

**Improtant methods :** 

- **Void ProjectTextures::initialize()**  it initializes the project textures by calling LoadTexture(path)**  

**Player.cpp :** 

The class responsible for drawing and managing the player movements , character design , character animation . 

**Important methods :** 

- **Void Player::manageAndDraw()** it draws the character and apply the animation needed**  

**Helper classes :** 

These classes are used in TrainCar.cpp only 

Note :  

This project is 98% made by hand … ONLY one ready model used ! 

**Keys :** 

Walk ( w + s + a + d) 

Interact ( E ) 

Close Or open windows (Q) 

Turn lightning (on + off ) ( 1 ) 

First person cam (Tab) 

Free camera (Shift) 

Look around ( arrow keys  or mouse ) 

Increase train speed ( X ) 

Decrease train speed (V) 

When in Free cam mode ( C -> go down  , F->go up ) 

**The END** 
