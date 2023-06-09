#pragma once
class Article;
class Iterator
{
public:
    virtual ~Iterator(){};

    virtual void first() = 0;

    virtual Article *currentItem() const = 0;

    virtual void next() = 0;

    virtual bool isDone() const = 0;
};