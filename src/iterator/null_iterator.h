#pragma once
#include "iterator.h"
#include "../article.h"
class NullIterator : public Iterator
{
public:
    void first() override
    {
        throw "NullIterator don't have first";
    }

    Article *currentItem() const override
    {
        throw "NullIterator don't have currentItem";
    }

    void next() override
    {
        throw "NullIterator don't have next";
    }

    bool isDone() const override
    {
        return true;
    }
};
