#include "pointer.h"
#include <iostream>
#include <fstream>
#include <sstream>

bool I_CAN_MARK(MODE m){
	std::ifstream lastMark( ".last");
	std::string mode;
	while (lastMark >> mode)
    {	
    	std::stringstream convert(mode);
		int actualMark;
		convert >> actualMark;
		if(actualMark == 0 or actualMark == 1){
			return m != actualMark;
		}
        
    }

    return true;
}

float getTotalTimeInMarked(std::time_t in, std::time_t out){
	typedef std::chrono::duration<float> diff;
	hours h1(out), h2(in);
	diff fs= h1-h2;
	hours d = std::chrono::duration_cast<hours>(fs);
	return d.count()/60/60;
}

void markInFile(MODE mode){
	if(!I_CAN_MARK(mode)){
		std::cout<<"Invalid option, after \""<<(mode?"OUT":"IN")<<"\" you must use \""<<(mode?"IN":"OUT")<<"\"";
		exit(1);
	}

	std::ofstream outputFile( "Pontos", std::ostream::out | std::ostream::app);

	if(mode == IN){
		outputFile << "----------------------------------------------"<<std::endl;
	}

	std::string mode_string = ((bool)mode ? "Saida: " : "Entrada: ");
	std::cout << mode_string;
	outputFile << mode_string;

	auto mark = Time::now();

  	std::time_t t = std::chrono::system_clock::to_time_t(mark);
  	std::cout << std::ctime(&t) << std::endl;
	outputFile << std::ctime(&t) << std::endl;

	if(mode == OUT){
		std::ifstream lastMark( ".last");
		std::string line, aux="";
		std::time_t in =0;
		while (lastMark >> line)
    	{	
        	if( line[0] == 'T' ){
        		for(unsigned int i = 0; i < line.size(); i++){
        			if(line[i] == 'T' || line[i] == ':') continue;
        			aux+=line[i];
        		}
				std::stringstream convert(aux);
				convert >> in;
        		break;
        	}
    	}
		
    	outputFile << "Tempo trabalhado : "<< getTotalTimeInMarked(in, t) << "h";
		outputFile << "----------------------------------------------"<<std::endl;
	}

	std::ofstream lastMark( ".last", std::ostream::out | std::ostream::trunc);
	lastMark<<std::to_string((int)mode)<<std::endl;
	lastMark<<"T:"<<t<<std::endl;
}
