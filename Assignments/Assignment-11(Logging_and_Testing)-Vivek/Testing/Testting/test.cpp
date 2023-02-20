#include "pch.h"
#include "../StaticLib1/framework.h"
#include <gtest/gtest.h>

TEST(TestCaseName, TestName) {
  EXPECT_EQ(2, remainder(10, 4));
  EXPECT_TRUE(true);
}

TEST(Testcasename, Testname) {
	EXPECT_EQ('e', charat(5));
	EXPECT_TRUE(true);
}
