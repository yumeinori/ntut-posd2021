#pragma once
#include <string>
#include "./iterator/iterator.h"
#include "./visitor/article_visitor.h"
#include "./iterator/null_iterator.h"
class Article
{
public:
    virtual ~Article() {}

    virtual std::string getText() const = 0;

    virtual int getLevel() const
    {
        return 0;
    }

    virtual Iterator *createIterator() = 0;

    virtual void accept(ArticleVisitor *visitor) = 0;

    virtual void add(Article *dpFormat)
    {
        throw "exception";
    }
};