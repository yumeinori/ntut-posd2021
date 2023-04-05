#pragma once

#include <string>
#include <vector>
#include <iostream>
class ArticleScanner
{
public:
    ArticleScanner(std::string input) : _input(input) {}

    std::string nextToken()
    {
        if (pos == _input.length())
        {
            throw "end position of the input";
        }
        std::string result = "";
        while (result == "")
        {
            skipWhiteSpace();
            for (auto token : tokenList)
            {
                if ((_input.length() - pos) >= token.length())
                {
                    if (_input.compare(pos, token.length(), token) == 0)
                    {
                        //std::cout<<"compare"<<token<<"\n";
                        pos = pos + token.length();
                        result = token;
                        return result;
                    }
                }
            }
            if (pos < _input.length())
            {
                pos++;
            }
            if (pos == _input.length())
            {
                break;
            }
        }
        return result;
    }

    int nextInt()
    {
        if (pos == _input.length())
        {
            throw "end position of the input";
        }
        std::string s = "";
        while (1)
        {
            skipWhiteSpace();
            if (_input[pos] <= '6' && _input[pos] > '0')
            {
                pos++;
                if (pos < _input.length())
                {
                    if (_input[pos] <= '9' && _input[pos] > '0')
                    {
                        s = s;
                        pos--;
                    }
                    else
                    {
                        pos--;
                        s = _input[pos];
                        pos++;
                        return std::stoll(s);
                    }
                }
                pos++;
            }
            else if (s == "" && pos < _input.length())
            {
                pos++;
            }
            else
            {
                break;
            }
            if (pos == _input.length())
            {
                break;
            }
        }
        //std::cout<<s<<"\n";
        return std::stoll(s);
    }

    std::string nextStr()
    {
        if (pos == _input.length())
        {
            throw "end position of the input";
        }
        std::string s = "";
        while (1)
        {
            skipWhiteSpace();
            if (_input[pos] == '"')
            {
                pos++;
                while (1)
                {
                    if(_input[pos] == '"'){
                        break;
                    }
                    else{
                        s = s+_input[pos];
                    }
                    pos++;
                }
                return s;
            }
            else if (s == "" && pos < _input.length())
            {
                pos++;
            }
            else
            {
                break;
            }
            if (pos == _input.length())
            {
                break;
            }
        }
        //std::cout<<s<<"\n";
    }

    bool isDone()
    {
        skipWhiteSpace();
        return pos == _input.length();
    }

private:
    std::string _input;
    std::string::size_type pos = 0;
    const std::vector<std::string> tokenList = {"ListItem", "Text", "Paragraph", "(", ")", "{", "}"};
    void skipWhiteSpace()
    {
        while (_input[pos] == ' ' || _input[pos] == '\n' || _input[pos] == '\t')
        {
            if (pos < _input.length())
            {
                pos++;
            }
        }
    }
};