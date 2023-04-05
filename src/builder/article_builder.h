#pragma once
#include <list>
#include <stack>
#include "../paragraph.h"
#include "../list_item.h"
#include "../text.h"
#include "../iterator/iterator.h"
#include "../article.h"
class ArticleBuilder
{
public:
    static ArticleBuilder *getInstance()
    {
        if (_instance == 0)
        {
            _instance = new ArticleBuilder();
        }
        return _instance;
    }

    ~ArticleBuilder()
    {
        while (!_articles.empty())
        {
            Article *temp = _articles.top();
            _articles.pop();
            delete temp;
        }
    }

    void buildListItem(std::string text)
    {
        _articles.push(new ListItem(text));
    }

    void buildText(std::string text)
    {
        _articles.push(new Text(text));
    }

    void buildParagraphBegin(int level, std::string text)
    {
        _articles.push(new Paragraph(level, text));
    }

    void buildParagraphEnd()
    {
        std::list<Article *> components;
        while (constrain())
        {
            components.push_back(_articles.top());
            _articles.pop();
        }
        Article *compound = _articles.top();
        for (auto it = components.rbegin(); it != components.rend(); it++)
        {
            compound->add(*it);
        }
    }

    Article *getArticle()
    {
        Article *temp = _articles.top();
        _articles.pop();
        return temp;
    }

    void reset()
    {
        _instance = 0;
    }

private:
    ArticleBuilder(){};
    static ArticleBuilder *_instance;
    std::stack<Article *> _articles;
    bool constrain()
    {
        Iterator *it = _articles.top()->createIterator();
        bool constrain = typeid(*_articles.top()) != typeid(Paragraph) ||
                         (!it->isDone() &&
                          typeid(*_articles.top()) == typeid(Paragraph));
        delete it;
        return constrain;
    }
};
ArticleBuilder *ArticleBuilder::_instance = 0;
