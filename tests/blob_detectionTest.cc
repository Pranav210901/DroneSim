#include "gtest/gtest.h"
#include "image_processor.h"

class BlobDetection : public ::testing::Test {
public:
  void SetUp() {
  }
};
TEST_F(BlobDetection,testNotFound){
	float f=false;
	Image img("src/Data/green.png");//the inputt file must not have a robot present
	ImageProcessor proc(img);
	EXPECT_EQ(proc.get_found(),f)<<"blob detection not probarly working";
	}

TEST_F(BlobDetection,testFound){
	float f=true;
	Image img("src/Data/1.png");//the inputt file must have a robot present
	ImageProcessor proc(img);
	EXPECT_EQ(proc.get_found(),f)<<"blob detection not probarly working";
	}
TEST_F(BlobDetection,testCheck){
	float f=false;
	Image img1(255,255);
	Image img2(255,255);
	ImageProcessor proc(img1);
	EXPECT_EQ(proc.check(img1,img2),f)<<"check is not consistance";
}
