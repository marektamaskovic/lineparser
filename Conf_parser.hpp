#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <locale>
#include <map>

struct parsed_t
{
    const std::string lvalue;
    const std::string rvalue;
    parsed_t(const std::string a, const std::string b): lvalue(a), rvalue(b) {};
};

class Conf_parser
{
    std::vector<std::string> keys;
    std::string separator {""};
    bool trim(std::string &str);
    bool checkKeyValidity(const std::string &key);

public:
    Conf_parser(const std::vector<std::string> &v);
    Conf_parser(const std::vector<std::string> &v, const std::string &sep);
    // ~Conf_parser();
    std::unique_ptr<struct parsed_t> parseString(std::string &str, const unsigned &line_num);
    std::map<std::string, std::string> parseStream(std::fstream &stream);

    void viewConfig();
};
