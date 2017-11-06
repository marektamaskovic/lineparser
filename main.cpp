#include <iostream>
#include <fstream>

#include "ConfigParser.hpp"

class custom_ConfigParser: public ConfigParser
{
public:
    custom_ConfigParser(const std::vector<std::string> &v): custom_ConfigParser(v, "="){};
    custom_ConfigParser(const std::vector<std::string> &v, const std::string &sep): ConfigParser(v, sep) {};
    virtual bool checkMapValidity() override final;
};

bool custom_ConfigParser::checkMapValidity(){
    /* Some difficult checks in map*/
    std::cout << "Checks passed!" << std::endl;
    return true;
}

int main(){

    std::vector<std::string> val {"key1", "key2", "key3", "key4"};
    std::string line;

    custom_ConfigParser line_parser(val);

    // parser.viewConfig();
    std::fstream my_file("data", std::ios::in);

#if 1
    if(my_file.is_open()){
        if(!line_parser.parseStream(my_file)){
            auto map = line_parser.getMap();

            // Example of writing map on stdout
            std::cout << "Map:" << std::endl;
            for(auto it: map){
                std::cout << it.first << "=" << it.second << std::endl;
            }

            my_file.close();
        }
        else{
            return 1;
        }
    }
#else
    if (my_file.is_open()){
        while ( getline (my_file,line) ){
            // std::cout << "raw:" << line << '\n';
            auto p = line_parser.parseString(line);
            if(p != nullptr){
                std::cout << "par: " << p->lvalue << "=" << p->rvalue << std::endl;
            }
        }

        my_file.close();
    }
#endif
    return 0;
}