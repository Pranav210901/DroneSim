#include "manmove.h"

bool ManualMovement::IsKeyDown(const std::string& key) {
	std::map<std::string, int>::iterator it = keyValue.find(key);
	if (it != keyValue.end()) {
		return it->second;
	}

	return false;
}
void ManualMovement::KeyDown(const std::string& key, int keyCode) {
	keyValue[key] = 1;
}
void ManualMovement::KeyUp(const std::string& key, int keyCode) {
	keyValue[key] = 0;
}
void ManualMovement::Move(){

  //code from web_app.cc in Update(double dt) function
	
  drone.SetJoystick(
		    IsKeyDown("ArrowRight") ? 1 : (IsKeyDown("ArrowLeft") ? -1 : 0),
		    IsKeyDown("w") ? 1 : (IsKeyDown("s") ? -1 : 0),
		    IsKeyDown("ArrowUp") ? -1 : (IsKeyDown("ArrowDown") ? 1 : 0),
		    IsKeyDown("a") ? 1 : (IsKeyDown("d") ? -1 : 0)
		    );

}
