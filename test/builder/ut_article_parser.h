#include <gtest/gtest.h>
#include "../../src/builder/article_parser.h"
#include <string>

TEST(Article_parser, text)
{
    ArticleParser *parser = new ArticleParser("test/data/text.txt");
    parser->parse();
    Article* result = parser->getArticle();
    ASSERT_EQ("This is a text", result->getText());
    delete parser;
    delete result;
}
TEST(Article_parser, list_item)
{
    ArticleParser *parser = new ArticleParser("test/data/list_item.txt");
    parser->parse();
    Article* result = parser->getArticle();
    ASSERT_EQ("This is a list item", result->getText());
    delete parser;
    delete result;
}
TEST(ArticlePrser, empty_compound)
{
    ArticleParser *parser = new ArticleParser("test/data/empty_paragraph.txt");
    parser->parse();
    Article* result = parser->getArticle();
    ASSERT_EQ("This is an empty paragraph", result->getText());
    delete parser;
    delete result;
}

TEST(ArticlePrser, simple_compound)
{
    ArticleParser *parser = new ArticleParser("test/data/simple_paragraph.txt");
    parser->parse();
    Article* result = parser->getArticle();
    ASSERT_EQ("This is a simple paragraph", result->getText());
    delete parser;
    delete result;
}

TEST(ArticlePrser, complex_compound)
{
    ArticleParser *parser = new ArticleParser("test/data/complex_paragraph.txt");
    parser->parse();
    Article* result = parser->getArticle();
    Iterator* it = result->createIterator();
    ASSERT_EQ("This is a complex paragraph", result->getText());
    ASSERT_EQ("This is a list item", it->currentItem()->getText());
    it->next();
    ASSERT_EQ("This is an inner paragraph", it->currentItem()->getText());
    it->next();
    ASSERT_EQ("This is a text", it->currentItem()->getText());

    delete parser;
    delete it;
    delete result;
}

