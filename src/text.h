#pragma once
#include "article.h"
#include "./visitor/article_visitor.h"
#include "./iterator/iterator.h"
#include "./iterator/null_iterator.h"
#include <string>
class Text : public Article
{
public:
    Text(std::string text)
    {
        _text = text;
    }

    std::string getText() const override
    {
        return _text;
    }

    Iterator *createIterator() override
    {
        return new NullIterator();
    }

    void accept(ArticleVisitor *visitor) override
    {
        visitor->visitText(this);
    }

private:
    std::string _text;
};