#include <gtest/gtest.h>
#include <filesystem>
#include <iostream>
#include "../src/init.hpp"

class InitTests : public testing::Test {
protected:
	InitTests() {
		Init init;
		init.Main(); // create the .mgit directory
	}
};


TEST(InitTests, DescriptionTest) {
	Init init;
	init.InitDescription();
	ASSERT_EQ(std::filesystem::exists(".mgit/description"), true);
}

TEST(InitTests, BranchesTest) {
	Init init;
	init.InitBranches();
	ASSERT_EQ(std::filesystem::exists(".mgit/branches"), true);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
