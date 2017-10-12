#include <iostream>
#include <fstream>

#include "Conf_parser.hpp"

int main(){

	std::vector<std::string> val {"key1", "key2", "key3", "key4"};
	std::string line;

	Conf_parser parser(val);

	// parser.viewConfig();
	std::fstream my_file("data", std::ios::in);

	if (my_file.is_open()){
		while ( getline (my_file,line) ){
			std::cout << "raw:" << line << '\n';
			auto p = parser.parseString(line);
			if(p != nullptr){
				std::cout << "par: " << p->lvalue << "=" << p->rvalue << std::endl;
			}
		}
		my_file.close();
	}
	return 0;
}