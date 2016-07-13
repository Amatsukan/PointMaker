#include "pointer.h"
#include <iostream>

int main(int argc, char *argv[])
{
	std::string mode;

	if(argc < 2){
		std::cout<<"Use : \n"<<argv[0]<<" in \n \t ou \n"<<argv[0]<<" out\n";
		return 0;
	}else{
		mode = std::string(argv[1]);
		if(mode == "in"){
			markInFile(IN);
		}else if(mode == "out"){
			markInFile(OUT);
		}else{
			std::cout<<"Invalid option, use \"in\" or \"out\".";
		}
	}


	return 0;
}