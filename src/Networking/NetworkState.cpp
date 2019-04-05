#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
#include <sstream>

#define START_PORT 9006

class NetworkState {
	static NetworkState* instance;
	std::map<unsigned short int, std::string> portsInUse;
	std::vector<unsigned short int> retiredPorts;
	unsigned short int startPort;

	//private constructor
	NetworkState(){
		startPort = START_PORT;
	};

	~NetworkState(){};

public:
	static NetworkState* getInstance(){
		if (!instance) {
			instance = new NetworkState();
		}
		return instance;
	};

	unsigned short int getNetworkPort(std::string serviceDescriptor=""){
		unsigned int newPort = startPort++;
		if (serviceDescriptor.size() == 0) {
			std::stringstream stream;
			stream << "NO-ID-" << newPort;
			serviceDescriptor = stream.str();
		}
		portsInUse[newPort] = serviceDescriptor;
		return newPort;
	};

	unsigned short int checkRetiredPorts(){
		unsigned short int oldPort = 0;
		if (retiredPorts.size() > 0) {
			oldPort = retiredPorts.back();
			retiredPorts.pop_back();
		}

		return oldPort;
	}

	void returnPort(unsigned short int portToClose){
		if (portsInUse.find(portToClose) == portsInUse.end()) return;
		portsInUse.erase(portToClose);
		retiredPorts.push_back(portToClose);
	}

	void print(){
		if (portsInUse.size() == 0) printf("No network ports currently in use\n");
		else {
			int highest = startPort - 1;
			printf("\tService Descriptor\t\tPort Number\n");
			while (highest >= START_PORT) {
				printf("\t%s\t\t\t%d\n", portsInUse[highest].c_str(), highest);
				highest--;
			}
		}
	};
};

NetworkState* NetworkState::instance = NULL;
