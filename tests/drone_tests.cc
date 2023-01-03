/**
 * @file Drone_test.cc
 * @author Pranav Pokhrel (pokhr013@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2021-12-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "gtest/gtest.h"
#include "drone.h"
#include "drone_factory.h"
#include "vector3.h"

class DroneTest : public ::testing::Test {
public:
    void SetUp() {
        //code here will execute just before the test ensues
        float speed = 100;
        vec3 direction = 100;
    }
}


  // test SetSpeed()
  drone->SetSpeed(speed);
  ASSERT_EQ(drone->speed, speed);
 
  //test SetDirection() 
  drone->SetDirection(direction);
  ASSERT_EQ(drone->direction, direction);