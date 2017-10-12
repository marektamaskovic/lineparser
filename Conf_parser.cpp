#include "Conf_parser.hpp"

Conf_parser::Conf_parser(	const std::vector<std::string> v,
							const std::string sep
						):
 						keys(v), separator(sep) {}

Conf_parser::Conf_parser(const std::vector<std::string> v):
 						Conf_parser(v, "=") {}

void Conf_parser::viewConfig(){
	std::cout << "separator:\t" << this->separator << std::endl;
	std::cout << "keys:\t";
	for(auto item : this->keys){
		std::cout << item << ", ";
	}
	std::cout << "\b\b  " << std::endl;
}

struct parsed_t *Conf_parser::parseString(std::string str){

	// std::cout << "hladam" << str << std::endl;

	std::string::size_type sep_pos;
	std::string key_c, key, val;

	// skontroluj dlzhu a potom ci su bitove kopie

	sep_pos = str.find(this->separator);

	if(sep_pos == std::string::npos){
		std::cout << "ERROR: separator not found" << std::endl;
	}
	else{
		// std::cout << "found at: " << str.substr(sep_pos) << " " << sep_pos << std::endl;
		key = str.substr(0, sep_pos);
		val = str.substr(sep_pos + 1);

		if(this->trim(key)){
			std::cerr << "ERROR: trim(): '"<< key << "'" << std::endl;
		}

		this->trim(val);
		// std::cout << "parsed:  '" << key << "'='" << val << "'" << std::endl;

		if(this->checkKeyValidity(key)){
			std::cerr << "ERROR: parsed key is not in key set inserted:" << key << std::endl;
			return nullptr;
		}
		else{
			struct parsed_t *p = new struct parsed_t(key, val);
			return p;
		}

	}

	return nullptr;
}

int Conf_parser::trim(std::string &str){

	if(str.length() <= 0){
		return 1;
	}

	std::locale loc;

	while(std::isspace(str.back(),loc)){
		str.pop_back();
	}

	while(std::isspace(str.front(),loc)){
		str = str.substr(1);
	}

	return 0;
}

int Conf_parser::checkKeyValidity(const std::string key){

	for(auto a: this->keys){
		// std::cout << "Cmp:" << a << ":" << key << std::endl;
		if(!key.compare(a)){
			return 0;
		}
		else{
			continue;
		}
	}

	return 1;
}