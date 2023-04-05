#pragma once
#include "../article.h"
#include "iterator.h"
template <class ForwardIterator>

class CompoundIterator : public Iterator
{
public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end) : _begin(begin), _end(end)
    {
        _current = _begin;
    }

    void first() override
    {
        _current = _begin;
    }

    Article *currentItem() const override
    {
        if (_current == _end)
        {
            throw "iterator is done";
        }
        return *_current;
    }

    void next() override
    {
        if (_current == _end)
        {
            throw "iterator is done";
        }
        _current++;
    }

    bool isDone() const override
    {
        return _current == _end;
    }

private:
    ForwardIterator _begin;
    ForwardIterator _end;
    ForwardIterator _current;
};
