
// TODO fix this and make all the code much cleaner

void init_config() {
	ofstream f(".git/config");
	if (!f.is_open()) {
		cerr << "Failed to open config file!" << endl;
		exit(1);
	}
	f << "CONFIGFILEBEGIN**" << endl;
	f.close();
}

init_description() {
	ofstream f(".mgit/description");
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
