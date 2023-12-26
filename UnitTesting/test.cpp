#include "pch.h"
#include "../../MathLibrary/MathLibrary/NativePair.h"
#include "../../MathLibrary/MathLibrary/NativeVector.h"


TEST(CreateVectorCase, NativeVector) {
  MathLibrary::NativeVector<int> myNativeVector;
  EXPECT_TRUE(true);
}

TEST(AddElementCase, NativeVector) {
	MathLibrary::NativeVector<int> myNativeVector;
	myNativeVector.append(4);
	EXPECT_TRUE(true);
}

TEST(CheckIntElementCase, NativeVector) {
	MathLibrary::NativeVector<int> myNativeVector;
	myNativeVector.append(4);
	ASSERT_EQ(myNativeVector[0], 4);
	EXPECT_TRUE(true);
}

TEST(CheckStringElementCase, NativeVector) {
	MathLibrary::NativeVector<std::string> myNativeVector;
	myNativeVector.append("Poland");
	ASSERT_EQ(myNativeVector[0], std::string("Poland"));
	EXPECT_TRUE(true);
}