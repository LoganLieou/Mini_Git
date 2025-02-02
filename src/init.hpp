class Init {
public:
	/**
	 * Initialize and create the description file
	 */
	void InitDescription();

	/**
	 * Initialize and create the objects folder
	 */
	void InitObjects();

	/**
	 * Initialize and create the branches folder
	 */
	void InitBranches();

	/**
	 * Initialize and create the info folder
	 */
	void InitInfo();

	/**
	 * Initialize and create the config file
	 */
	void InitConfig();

	/**
	 * Initialize and create the refs folder
	 */
	void InitRefs();

	/**
	 * Initialize and create the .mgit folder, essentially the main function of
	 * this class
	 */
	void Main();
};
