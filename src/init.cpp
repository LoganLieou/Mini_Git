#include "init.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <openssl/sha.h>

void Init::Main() {
	if (std::filesystem::exists(".mgit")) {
		std::cerr << ".mgit already exists\n";
		exit(0);
	}
	else if (!std::filesystem::create_directory(".mgit")) {
		std::cerr << "ERROR: Failed to create .mgit directory\n";
		exit(1);
	}
	else {
		std::cout << "Successfully initialized .mgit folder\n";
	}
	this->InitBranches();
	this->InitConfig();
	this->InitDescription();
	this->InitInfo();
	this->InitObjects();
	this->InitRefs();
}

void Init::InitBranches() {
	if (!std::filesystem::create_directories(".mgit/branches/")) {
		std::cerr << "ERROR: Failed to create .mgit/branches directory\n";
		exit(1);
	}
}

void Init::InitConfig() {
	std::ofstream outfile(".mgit/config");
	outfile << "[core]\n";
	outfile << "\tfilemode = true\n";
	outfile << "\tbare = false\n";
	outfile << "\tlogallrefupdates = true\n";
	outfile.close();
}

void Init::InitDescription() {
	std::ofstream outfile(".mgit/description");
	outfile << "";
	outfile.close();
}

void Init::InitInfo() {
	if (!std::filesystem::create_directory(".mgit/info")) {
		std::cerr << "ERROR: Failed to create info directory\n";
		exit(1);
	}
	std::ofstream outfile(".mgit/info/exclude");
	outfile << "# *.[oa]\n# *~\n";
	outfile.close();
}


void Init::InitObjects() {
	// No idea how this works
	// Time to break things and pray
}

void Init::InitRefs() {
	// No idea how this works
	// Surely it can't be that bad right
}

