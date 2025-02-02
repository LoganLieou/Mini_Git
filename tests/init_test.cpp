#include <gtest/gtest.h>
#include <filesystem>
#include <iostream>
#include "../src/init.hpp"


TEST(InitTests, DescriptionTest) {
	Init::InitDescription();
	std::cout << "PASSED Description" << std::endl;
	ASSERT_EQ(std::filesystem::is_empty(".mgit/description"), false);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
