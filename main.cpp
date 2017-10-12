#include <iostream>
#include <fstream>

#include "Conf_parser.hpp"

int main(){

    std::vector<std::string> val {"key1", "key2", "key3", "key4"};
    std::string line;

    Conf_parser line_parser(val);

    // parser.viewConfig();
    std::fstream my_file("data", std::ios::in);

#if 1
    if(my_file.is_open()){
        auto map = line_parser.parseStream(my_file);

        std::cout << "Map:" << std::endl;
        for(auto it: map){
            std::cout << it.first << "=" << it.second << std::endl;
        }

        my_file.close();
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