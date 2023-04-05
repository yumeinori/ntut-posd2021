#pragma once

#include <fstream>
#include <sstream>

#include <string>
#include <vector>
#include "../article.h"
#include "article_builder.h"
#include "article_scanner.h"

class ArticleParser {
public:
    // `filePath` is a relative path of makefile
    ArticleParser(std::string filePath) { 
        std::ifstream ifs(filePath, std::ios::in);
        if (!ifs.is_open())
        {
            throw "未成功讀取檔案";
        }
        std::stringstream ss;
        ss << ifs.rdbuf();
        input = ss.str();
        //std::cout << input;
        ifs.close();
    }

    ~ArticleParser() { 
        builder->reset();
        delete builder;
    }

    void parse() { 
        ArticleScanner scanner(input);
        builder = ArticleBuilder::getInstance();
        while (!scanner.isDone())
        {
            std::string token = "";
            try
            {
                token = scanner.nextToken();
            }
            catch (const char *msg)
            {
                //std::cout << msg;
            }
            //std::cout<<token<<"\n";
            if (token == "ListItem")
            {
                //std::cout << "創建圓形";
                try
                {
                    std::string temp = scanner.nextStr();
                    //std::cout <<"Circlecontent:"<< "temp";
                    builder->buildListItem(temp);
                }
                catch (const char *msg)
                {
                    //std::cout << msg;
                }
            }
            else if (token == "Text")
            {
                //std::cout << "創建長方";
                try
                {
                   std::string temp = scanner.nextStr();
                    //std::cout <<"Circlecontent:"<< "temp";
                    builder->buildText(temp);
                }
                catch (const char *msg)
                {
                    //std::cout << msg;
                }
            }
            else if (token == "Paragraph")
            {
                //std::cout << "創建三角";
                try
                {
                    int level = scanner.nextInt();
                    std::string tempstr = scanner.nextStr();
                    //std::cout <<"Circlecontent:"<< "temp";
                    builder->buildParagraphBegin(level,tempstr);
                }
                catch (const char *msg)
                {
                }
            }
            else if (token == "}")
            {
                builder->buildParagraphEnd();
            }
        }
    }

    Article* getArticle() { 
        return builder->getArticle();
    }
private:
    std::string input = "";
    ArticleBuilder *builder;
};
