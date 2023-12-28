#include "pch.h"
#include "MathLibrary/NativePair.h"
#include "MathLibrary/NativeVector.h"


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
}

TEST(CheckStringElementCase, NativeVector) {
	MathLibrary::NativeVector<std::string> myNativeVector;
	myNativeVector.append("Poland");
	ASSERT_EQ(myNativeVector[0], std::string("Poland"));
}

TEST(CreateVectorWithElements, NativeVector) {
	std::string tempArray[] = { "Poland", "Czech", "Bulgaria", "Great Britan" };
	MathLibrary::NativeVector<std::string> myNativeVector(tempArray);
	ASSERT_EQ(myNativeVector[0], "Poland");
	ASSERT_EQ(myNativeVector[1], "Czech");
	ASSERT_EQ(myNativeVector[2], "Bulgaria");
	ASSERT_EQ(myNativeVector[3], "Great Britan");
}

TEST(AppendVectorWithElements, NativeVector) {
	std::string tempArray[] = { "Poland", "Czech", "Bulgaria", "Great Britan" };
	MathLibrary::NativeVector<std::string> myNativeVector;
	myNativeVector.appendArray(tempArray);
	ASSERT_EQ(myNativeVector[0], "Poland");
	ASSERT_EQ(myNativeVector[1], "Czech");
	ASSERT_EQ(myNativeVector[2], "Bulgaria");
	ASSERT_EQ(myNativeVector[3], "Great Britan");
}

TEST(AppendVectorWithElementsNotEmpty, NativeVector) {
	std::string tempArray[] = { "Poland", "Czech"};
	std::string tempArray2[] = { "Bulgaria", "Great Britan" };
	MathLibrary::NativeVector<std::string> myNativeVector(tempArray);
	myNativeVector.appendArray(tempArray2);
	ASSERT_EQ(myNativeVector[0], "Poland");
	ASSERT_EQ(myNativeVector[1], "Czech");
	ASSERT_EQ(myNativeVector[2], "Bulgaria");
	ASSERT_EQ(myNativeVector[3], "Great Britan");
}

TEST(MergeVectors, NativeVector) {
	std::string tempArray[] = { "Poland", "Czech" };
	std::string tempArray2[] = { "Bulgaria", "Great Britan" };
	MathLibrary::NativeVector<std::string> myNativeVector1(tempArray);
	MathLibrary::NativeVector<std::string> myNativeVector2(tempArray2);
	myNativeVector1.merge(myNativeVector2);
	ASSERT_EQ(myNativeVector1[0], "Poland");
	ASSERT_EQ(myNativeVector1[1], "Czech");
	ASSERT_EQ(myNativeVector1[2], "Bulgaria");
	ASSERT_EQ(myNativeVector1[3], "Great Britan");
	
	ASSERT_EQ(myNativeVector2[0], "Bulgaria");
	ASSERT_EQ(myNativeVector2[1], "Great Britan");
}

TEST(FalseMergeVectors, NativeVector) {
	std::string tempArray[] = { "Poland", "Czech" };
	MathLibrary::NativeVector<std::string> myNativeVector(tempArray);
	myNativeVector.merge(myNativeVector);
	ASSERT_EQ(myNativeVector[0], "Poland");
	ASSERT_EQ(myNativeVector[1], "Czech");
	ASSERT_THROW(myNativeVector[2], std::out_of_range);
	ASSERT_THROW(myNativeVector[3], std::out_of_range);
}

TEST(NegativeOperatorVector, NativeVector) {
	std::string tempArray[] = { "Poland", "Czech", "Bulgaria", "Great Britan" };
	MathLibrary::NativeVector<std::string> myNativeVector(tempArray);
	ASSERT_EQ(myNativeVector[0], "Poland");
	ASSERT_EQ(myNativeVector[1], "Czech");
	ASSERT_EQ(myNativeVector[-1], "Great Britan");
	ASSERT_EQ(myNativeVector[-2], "Bulgaria");
	ASSERT_EQ(myNativeVector[-4], "Poland");
}

TEST(FalseNegativeOperatorVector, NativeVector) {
	std::string tempArray[] = { "Poland", "Czech", "Bulgaria", "Great Britan" };
	MathLibrary::NativeVector<std::string> myNativeVector(tempArray);
	ASSERT_THROW(myNativeVector[-5], std::out_of_range);
	ASSERT_THROW(myNativeVector[-6], std::out_of_range);
	ASSERT_THROW(myNativeVector[-7], std::out_of_range);
}
