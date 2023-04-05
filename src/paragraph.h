#pragma once
#include "article.h"
#include <vector>
#include <typeinfo>
#include "./visitor/article_visitor.h"
#include "./iterator/iterator.h"
#include "./iterator/compound_iterator.h"
#include "./iterator/null_iterator.h"
class Paragraph : public Article
{
public:
    Paragraph(int level, std::string text)
    {
        _level = level;
        _text = text;
        if (_level < 1)
        {
            throw "level small than 0";
        }
        if (_level > 6)
        {
            throw "level larer than 6";
        }
    }

    ~Paragraph()
    {
        for (int i = 0; i < s.size(); i++)
        {
            delete s[i];
        }
    }

    std::string getText() const override
    {
        return _text;
    }

    int getLevel() const override
    {
        if (_level < 1)
        {
            throw "level small than zero";
        }
        return _level;
    }

    Iterator *createIterator() override
    {
        return new CompoundIterator<std::vector<Article *>::iterator>(s.begin(), s.end());
    }

    void add(Article *content) override
    {
        if (typeid(*content).name() == typeid(Paragraph).name())
        {
            if (content->getLevel() <= _level)
            {
                throw "level small than Paragraph";
            }
        }
        s.push_back(content);
    }

    void accept(ArticleVisitor *visitor) override
    {
        visitor->visitParagraph(this);
    }

private:
    int _level;
    std::string _text;
    std::vector<Article *> s;
};