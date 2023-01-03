
#include "patrol.h"
//#include "beeline.h"
#include <fstream>
//#include "util/base64.h"
using namespace std;



//(not sure if i needed this to save position and direction as arrays in my patrol class)
    //save position as an array
/*    picojson::array pos;
    pos.push_back(picojson::value(deleteThisDrone.pos[0]));
    pos.push_back(picojson::value(deleteThisDrone.pos[1]));
    pos.push_back(picojson::value(deleteThisDrone.pos[2]));
    entity["pos"] = picojson::value(pos);

    // Save the direction as an array
    picojson::array dir;
    dir.push_back(picojson::value(deleteThisDrone.dir[0]));
    dir.push_back(picojson::value(deleteThisDrone.dir[1]));
    dir.push_back(picojson::value(deleteThisDrone.dir[2]));
    entity["dir"] = picojson::value(dir);
*/
  void Patrol::SetJoystick(double x, double y, double z, double a) {
      dir[0] = x; dir[1] = y; dir[2] = z;
    }

  void Patrol::Move(double* pos, double* dir, Drone drone){
    dir[0] = 0;
    dir[1] = -1;
    dir[2] = 1;
    while(pos[2])
  //checking along x axis towards the backward direction
    if(pos[0] > 100){
      dir[0] = -1;
      //sets the joystick to the desired position
      drone.SetJoystick(dir[0],0,0,0);
      }
  //checking along x axis towrds the forward direction
    if(pos[0] < -100){
      dir[0] = -1;
      //sets the joystick to the desired position
      drone.SetJoystick(dir[0],0,0,0);
      }
  //checking along z axis towrds the backward direction
    if(pos[2] > 50){
      dir[2] = -1;
      //sets the joystick to the desired position
      drone.SetJoystick(0,0,dir[2],0);
      }
  //checking along z axis towrds the forward direction
    if(pos[2] < -50){
      dir[2] = 1;
      //sets the joystick to the desired position
      drone.SetJoystick(0,0,dir[2],0);
      }
};