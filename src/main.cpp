#include <iostream>
#include <cstdio>
#include "Utilities/io.cpp"

int main(int argc, char** argv) {
	std::cout<<"******Setting up cpp-smtp program*****\n\n";
	int* portno = (int*)parseInput(argc, argv, 1);
	printf("Provided port number %d\n", *portno);

	return 0;
}
