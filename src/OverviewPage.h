/*! \page OverviewPage OverviewPage
 *
 *  OverviewPage.h
 *
 * @copyright holm0715:Jaron Holm
 *
 *

* Overview:
* Our project was split into 2 major componets, the entities section and the camera/image handeling section. These two sections are brought together in the drone class, an entity which has a camera.
* This overview will go over the classes on a more individual level, if you want to see an explination how they all come together in the simulation, look at the simulation page in this doxygen documentation

*Entity:
*The main entity class is a base class that is inheritied by all entities. As the UML shows, Drone, Robot, Recharge station factory and the Battery Decorator are all derived classes if entity. All entities have a name and ID
*That are taken from the picoJSON object the entity is created from. For classes that move/change in some way during the simulation, they will also inherite an update method that can be called in the simulation.

*All Entities aside from the battery decorator are created from an Enity Factory class. The individual Factories all inherit from the base Entity factory class, which creates the entity based on their picojson data. 

* The robot class does not really do anything other than existing in the simulation and the rest of the simulation  classes work together to find its position.

Drone:
*Drone is the entity which the user controls and as such it has many unique methods and classes that it uses. The Classes it has includes a camera, vectors for speed and position, a patrol and beeline class for movement and a physics Engine.
*All of these are explained in greater detail below.
*As for the methods drone has, the main one is update, which is called in the simulation and chages the position, direction, speed, and acceleration(found in the physics engine) of the drone. These are changed based on whatever type of movement the drone is currently doing.
*Another intesting movment option the drone has is the Rotate method, which turns the drone based on a given angle.
*SetJoystick is the function that handles manual movemt, and it is used whenever input is detected from the user.
*ReturnAsPicoJSON is used at the end of update, so that the server can get the current information of drone that was changed during update.

*Movement Classes:
*Drone also contains the 3 movement options, patrol beeline and ManualMovement. All 3 have just a single method move, but all 3 work differently. The patrol class moves the drone randomly, and is used when searching the for the robot.
*The Beeline class moves the drone to a point, and is used both when the robot is found and when a powered drone detects that it needs a charge. In the first case Beeline is called to go to the robot, and in the second it is called to go to a rechage station.
*The ManualMovement is used when input is detected by the user, and it moves the drone according to whatever input the user made.

*PhysicsEngine:
*The Physic Engine class is used to create accelertaion in the drone. Outside of the getters and setters for the class, its main method is Calculate. This calculate is taken from whatever Physics Strategy it has. AS can be seen in the UML
*The strategy the Physic Engine uses is called Acceleration Strategy, and it's Calculate is used to determine what the drone's acceleration should be.

*Battery Decorator:
*The Battery Decorator is an entity that also contains an entity, following the decorator pattern. It is a base class, so many different battery decorators could be created for the various entitys, howver the only entity that is powered in this case is the drone.
*The Drone's specific battery Decorator is called DroneBattery. A drone battery is created from an already exsisting drone object and a vector location of a recharge station, so it knows where to call beeline to when it detects it needs to charge.
*It's update function simply decreases/increases chare depending on if its at a station, and then calls the update for it's drone if it's charge is not 0 and needCharge is false. If it is 0 it disables movement for the drone.
*FinishUpdate is called after update and sees if the drone is entering a zone of no return, where it could not make it back to the recharge station if it went further. If that is the case it flips the bool needCharge to true, which
*Changes the update function so that it instead beelines to a charging station.


*Other Entities:
*The other Entities are Robot and Recharge Station factory, and all that matters for both is really just their position. The Drone needs to find the position of the robot and a powered drone will know the location of the station.
*Charging is handeled in the DroneBattery class, and it simply charges when near a station, so no other functionality is needed in the station.

*Vec3:
*Vector 3 is a class which is used mostly for position and direction in the classes. As the UML shows, many classes rely on the Vector 3 object, drone, Robot, Rechage station, Camera and all the movement options use the vector class in some way.
*All Vector is is essentally 3 floats, x, y and z. It's methods are just the diffrent type of calculations you can do with vectors, such as multiply,normalize,dotproduct etc. All of these can be seen in the UML.

* Camera:

* The Camera class is the main class for the image procession side of the project. It's main metods are used to take a picture, process it, look for the robot in the image and if the robot is found, to calculate the robots postion from the picture.
* The first fuction, take picture creates an image based on what the camera is currently looking at. This image is then processed in process images, which uses an image processor class that the camera has.
* After the image has been processed findRobot will return whether or not the Image processor found the robot in the image. If it was findRobotPostition can be called, which calulates the robot's postion based on the image.

*Image Processor: 

*The Image Processor class uses filters in order to process the image taken by camera. As can be seen on the UML, the filters it uses are Color Thresholding and an OpenCVFilter, specifically a canny edge adpater.
* By applying these filters to the image, it's check function returns a bool saying if the robot was found.

 *UML:  <a href="https://lucid.app/lucidchart/a6b44b21-f64b-44eb-98ff-659d75aa7f92/edit?view_items=NqUyigSUXgSK&invitationId=inv_8502053e-d0ed-4d34-a9b5-89641bed6593">SimulationUML </a>

 */
