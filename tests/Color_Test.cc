#include "gtest/gtest.h"
#include "color.h"
#include <string>
class ColorTest : public ::testing::Test {
public:
  void SetUp( ) { 
  }
};
TEST_F(ColorTest, ColorGetters){
	float r,g,b,a=255;
	Color c(r,g,b,a);
	EXPECT_EQ(c.Getalpha(),a) << "Color getters are not working";
	EXPECT_EQ(c.Getred(),r) << "Color getters are not working";
	EXPECT_EQ(c.Getblue(),b) << "Color getters are not working";
	EXPECT_EQ(c.Getgreen(),g) << "Color getters are not working";
	
}
TEST_F(ColorTest,ClampTest){
	float r,g,b,a=244;
	float n=255;
	Color c(r,g,b,a);
	c.clamp(0,255);
	EXPECT_EQ(c.Getalpha(),n) << "Color clamp not working proberly";
}


