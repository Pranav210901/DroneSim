/**
 * @file vec3_test.cc
 * @author Pranav Pokhrel (pokhr013@umn.edu)
 * @brief 
 * @version 0.1
 * @date 2021-12-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "gtest/gtest.h"
#include "vec3.h"

class VecTest : public ::testing::Test {
public:
  void SetUp() {
    //code here will execute just before the test ensues
    null_vec = Vec3(0,0,0)
  }
};
/**
 * @brief Construct a new test f object, to test setters in the vector class
 * 
 */
TEST_F(VecTest, Setter_test){
    Vec3 vec1(1.0, 2.0, 3.0);
    Vec3 vec11(4.0, 2.0, 3.0);
    Vec3 vec12(1.0, 3.0, 3.0);
    Vec3 vec13(1.0, 2.0, 4.0);
    Vec3 set_up;

    EXPECT_EQ(vec1.setX(4.0), vec11);
    EXPECT_EQ(vec1.setY(3.0), vec12);
    EXPECT_EQ(vec1.setZ(4.0), vec13);
}
/**
 * @brief Construct a new test f object, to test the magnitude method in the vector class
 * 
 */
TEST_F(VecTest, MagnitudeTest){
    Vec3 vec1(2.0, 3.0, 5.0);
    Vec3 vec2(3.0, 4.0, 5.0);
    float Mag1 = sqrt(pow(vec111.GetX(), 2) + pow(vec111.GetY(), 2) + pow(vec111.GetZ(), 2));
    float Mag2 = sqrt(pow(vec112.GetX(), 2) + pow(vec112.GetY(), 2) + pow(vec112.GetZ(), 2));
    EXPECT_EQ(int(Mag1), 6);
    EXPECT_EQ(int(Mag2), 7);
}
/**
 * @brief Construct a new test f object, to test the normalize method in the vector class
 * 
 */
TEST_F(VecTest, NormalizeTest){
    Vec3 vec11(4.0, 9.0, 16.0)
    float mag = sqrt(pow(vec11.GetX(), 2) + pow(vec11.GetY(), 2) + pow(vec11.GetZ(), 2));
    Vec3 normalizedVector(4.0/mag, 9.0/mag, 16.0/mag);
    
    EXPECT_EQ(vec11.Normalize(), normalizedVector);
    EXPECT_EQ(null_vec.Normalize(), null_vec);
} 
    
}