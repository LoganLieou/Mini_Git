#include <cstdio>
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;

namespace fs = filesystem;

void init_config() {
	ofstream f(".git/config");
	if (!f.is_open()) {
		cerr << "Failed to open config file!" << endl;
		exit(1);
	}
	f << "CONFIGFILEBEGIN**" << endl;
	f.close();
}

void init_description() {
	ofstream f(".mgit/description");
	f << "";
	f.close();
}

void init_HEAD() {
	ofstream f(".mgit/HEAD");
	f << "ref: refs/heads/main" << endl;
	f.close();
}

/**
 * Initialize the file setup for git
 */
void init() {
	// create the git directory
	try {
		if (fs::create_directory(".mgit")) {
			cout << "Successfully created .mgit directory" << endl;
		}
		else {
			cout << "Failed to create directory" << endl;
			exit(1);
		}
	}
	catch (fs::filesystem_error &e) {
		cout << "Error " << e.what() << endl;
		exit(1);
	}

	// create the rest of the things
	init_config();
	init_description();
	init_HEAD();
	init_hooks();
	init_info();
	init_objects();
	init_refs();
}

int main(int argc, char **argv) {
	if (argc > 1 && (string)argv[1] == "init") {
		init();
	}
}
