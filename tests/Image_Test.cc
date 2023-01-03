#include "gtest/gtest.h"
#include "image.h"
#include <string>
class ImageTest : public ::testing::Test {
public:
  void SetUp( ) { 
  }
};
TEST_F(ImageTest, ImageSaveTesting){
	int w,h=265;
	Image img(200,300);
	img.saveAs("result.png");
	ASSERT_TRUE(testing::AssertionResult("result.png"));
}
	
