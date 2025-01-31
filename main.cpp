#include <cstdio>
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;

namespace fs = filesystem;

void init_refs() {
	// the first reference created is the ref: refs/heads/main
	// where this main file contains a sha1 hash for something??
	// assuming this hash must point to the root of the tree probably

	if (fs::create_directories(".mgit/refs/heads")) {
		ofstream f(".mgit/refs/heads/main"); // main file
		f << "19a27ddd6221178c88e7042bf3934f9946e6be23" << endl; // TODO implment sha1 in code somewhere
		return;
	}
	else {
		cerr << "failed to create refs/heads" << endl;
		exit(1);
	}
}

void init_objects() {
	// numbers and sha1 hash something another not entirely sure how this works
}

void init_info() {
	if (fs::create_directory(".mgit/info/")) {
		cout << "successfully create info directory" << endl;
		ofstream f(".mgit/info/exclude");
		f << "# *.[oa]\n# *~\n";
	}
	else {
		cerr << "unable to create info directory" << endl;
	}
}

void init_config() {
	ofstream f(".mgit/config");
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
	// TODO define hooks init_hooks();
	init_info();
	init_objects();
	init_refs();
}

int main(int argc, char **argv) {
	if (argc > 1 && (string)argv[1] == "init") {
		init();
	}
}
