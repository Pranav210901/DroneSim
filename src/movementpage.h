/*! \movementpage Movement Page
 *
 * \section intro_sec movementpage.h
 *
 * @copyright kruta007: Kathryn Kruta.
 *
 *
 * A brief overview of the Drone Movement in the project: 
 *
 * Throughout the simulation the drone gets feedback from the cameras on whether or not it sees the
 * robot. If the color camera detects the robot is in view, then the depth camera will respond with 
 * the location of the robot. The Beeline class will then alter the drones trajectory to go directly
 * to the robot. However, if the color camera determines the robot is not in view the drone will
 * continue on moving throughout the simulation space getting no input from the depth camera. If the 
 * simulation detects keyboard input it will then switch to taking movement feedback and input from 
 * the keyboard. While taking direction from the user directly, the color and depth camera still
 * function and return as normal but does not effect the movement.
 *
 *
 * A brief overview of the main classes: Beeline, Patrol, Manual Movement
 *
 * Beeline:
 * The Beeline class has the move function that the drone will call only when the robot is spotted 
 * by the color camera. Once the robot is spotted, the depth camera will respond with the location 
 * of the robot. The Beeline move function uses the position returned from the depth camera to  
 * adjust the drones trajectory to move straight towards the robot. It also edits the velocity
 * vector to account for the new direction and speed.
 *
 * Patrol:
 * The Patrol class has the move function that the drone will continually call in until the robot is 
 * spotted by the color camera. Until the robot is spotted the color camera repeatidly scans the 
 * within camera view in a countinous grid-like pattern. 
 *
 * Manual Movement:
 * The Manual Movement class has the move function that will overide the move functions from both
 * the Patrol and Beeline classes. The drone will begin taking movement feedback based on the input
 * from the keyboard. At this point the movement is solely based on the direction of the user.
 * However, the color and depth inputs from the camera are still functioning normally, although
 * neither of these effects the movement of the drone.
 *
 * How to start extending the system:
 * 
 * To extend the system the one could add a movement controller to help streamline the strategy
 * pattern. One could also implement different patrol algorithms. For added difficulty and
 * potenitally a more realistic simulation, the robot could use movement, this would mean the drone
 * would need to account for the robot movement and possibly research areas and follow the robot
 * after it was found until the rescue team arrived.
 *
 */
