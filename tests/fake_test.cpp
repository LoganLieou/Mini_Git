#include <gtest/gtest.h>
#include "K.hpp"

TEST(FraudTest, FakeTest1) {
	ASSERT_EQ(1, 1);
}

TEST(FraudTest, FakeTest2) {
	ASSERT_EQ(0, 1);
}

TEST(FraudTest, FakeTest3) {
	K k;
	int result = k.f(4);
	ASSERT_EQ(result, 8);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
