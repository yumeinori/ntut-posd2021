#pragma once
#include "article_visitor.h"
#include "../list_item.h"
#include "../text.h"
#include "../paragraph.h"
#include <string>
#include <iostream>
class MarkdownVisitor : public ArticleVisitor
{
public:
    void visitListItem(ListItem *li) override
    {
        _li = "- " + li->getText() + "\n";
    }

    void visitText(Text *t) override
    {
        _t = t->getText() + "\n";
    }

    void visitParagraph(Paragraph *p) override
    {
        std::string first = "";
        for (int i = 0; i < p->getLevel(); i++)
        {
            first = first + "#";
        }
        first += " ";
        _p = first + p->getText() + "\n";
        Iterator *it = p->createIterator();
        for (it->first(); !it->isDone(); it->next())
        {
            if (typeid(*it->currentItem()).name() == typeid(Paragraph).name())
            {
                _p = _p + info(it);
            }
            else
            {
                if (typeid(*it->currentItem()).name() == typeid(ListItem).name())
                {
                    _p = _p + "- " + it->currentItem()->getText() + "\n";
                }
                if (typeid(*it->currentItem()).name() == typeid(Text).name())
                {
                    _p = _p + it->currentItem()->getText() + "\n";
                }
            }
        }
        delete it;
    }
    std::string getResult() const override
    {
        if (_t != "")
        {
            return _t;
        }
        if (_li != "")
        {
            return _li;
        }
        if (_p != "")
        {
            return _p;
        }
    }

private:
    std::string _t = "", _li = "", _p = "";
    std::string info(Iterator *it)
    {
        std::string first = "";
        for (int i = 0; i < it->currentItem()->getLevel(); i++)
        {
            first = first + "#";
        }
        first += " ";
        first = first + it->currentItem()->getText() + "\n";
        Iterator *it2 = it->currentItem()->createIterator();
        for (it2->first(); !it2->isDone(); it2->next())
        {
            if (typeid(*it2->currentItem()).name() == typeid(Paragraph).name())
            {
                first = first + info(it2);
            }
            else
            {
                if (typeid(*it2->currentItem()).name() == typeid(ListItem).name())
                {
                    first = first + "- " + it2->currentItem()->getText() + "\n";
                }
                if (typeid(*it2->currentItem()).name() == typeid(Text).name())
                {
                    first = first + it2->currentItem()->getText() + "\n";
                }
            }
        }
        delete it2;
        return first;
    }
};