#include <iostream>
#include <cstdio>

int* retrievePort(int location, char** argv){
	int numport = atoi(argv[location]);
	return &numport;
}

void* parseInput(int &argc, char** argv, int argsExpected = -1){
	if (argsExpected > 0 && argc <= 0) {
		perror("Did not provide adequate number of arguments");
	}

	return retrievePort(1, argv);
}

