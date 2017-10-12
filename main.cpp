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
			std::cout << line << '\n';
			struct parsed_t *p = parser.parseString(line);
			if(p != nullptr){
				std::cout << p->lvalue << "=" << p->rvalue << std::endl;
			}
			delete p;
		}
		my_file.close();
	}
	return 0;
}