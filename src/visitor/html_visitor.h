#pragma once
#include "article_visitor.h"
#include "../list_item.h"
#include "../text.h"
#include "../paragraph.h"
#include <string>
class HtmlVisitor : public ArticleVisitor
{
public:
    void visitListItem(ListItem *li) override
    {
        std::string str = li->getText();
        _li = "<li>" + str + "</li>";
    }

    void visitText(Text *t) override
    {
        _t = "<span>" + t->getText() + "</span>";
    }

    void visitParagraph(Paragraph *p) override
    {
        int level = p->getLevel();
        std::string sh = "<h" + std::to_string(level) + ">";
        std::string eh = "</h" + std::to_string(level) + ">";
        _p = "<div>" + sh + p->getText() + eh;
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
                    _p = _p + "<li>" + it->currentItem()->getText() + "</li>";
                }
                if (typeid(*it->currentItem()).name() == typeid(Text).name())
                {
                    _p = _p + "<span>" + it->currentItem()->getText() + "</span>";
                }
            }
        }
        delete it;
        _p = _p + "</div>";
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
        int level = it->currentItem()->getLevel();
        std::string sh = "<h" + std::to_string(level) + ">";
        std::string eh = "</h" + std::to_string(level) + ">";
        std::string out = "<div>" + sh + it->currentItem()->getText() + eh;
        Iterator *it2 = it->currentItem()->createIterator();
        for (it2->first(); !it2->isDone(); it2->next())
        {
            if (typeid(*it2->currentItem()).name() == typeid(Paragraph).name())
            {
                out = out + info(it2);
            }
            else
            {
                if (typeid(*it2->currentItem()).name() == typeid(ListItem).name())
                {
                    out = out + "<li>" + it2->currentItem()->getText() + "</li>";
                }
                if (typeid(*it2->currentItem()).name() == typeid(Text).name())
                {
                    out = out + "<span>" + it2->currentItem()->getText() + "</span>";
                }
            }
        }
        out = out + "</div>";
        delete it2;
        return out;
    }
};