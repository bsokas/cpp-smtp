#include <cstdio>
#include <cstdlib>
#include <vector>

class NetworkState {
	static NetworkState* instance;
	std::vector<unsigned short int> portsInUse;

	//private constructor
	NetworkState(){};

	~NetworkState(){};

public:
	static NetworkState* getInstance(){
		if (!instance) {
			instance = new NetworkState();
		}

		return instance;
	};

	void print(){
		if (portsInUse.size() == 0) printf("No network ports currently in use\n");
	};
};

NetworkState* NetworkState::instance = NULL;