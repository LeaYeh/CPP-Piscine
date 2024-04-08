#ifndef __REPLACER_HPP__
#define __REPLACER_HPP__

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Replacer
{
    private:
        std::string         _input_fp;
        std::string         _output_fp;
        std::string         _old_str;
        std::string         _new_str;
        std::stringstream   _file_content;

        std::string         _getInputFileContent(void);
    public:
        Replacer(std::string filename, std::string old_str, std::string new_str);
        ~Replacer(void);
        void replace(void);
};

#endif