#include <gtest/gtest.h>
#include <string>
#include "../../src/paragraph.h"
#include "../../src/list_item.h"
#include "../../src/text.h"
#include "../../src/builder/article_builder.h"
#include "../../src/visitor/markdown_visitor.h"

#include <iostream>
TEST(CaseBuilder, buildText)
{
    ArticleBuilder *builder = ArticleBuilder::getInstance();
    builder->buildText("text");
    Article *result = builder->getArticle();

    ASSERT_EQ("text", result->getText());
    builder->reset();
    delete builder;
    delete result;
}
TEST(CaseBuilder, buildListItem)
{
    ArticleBuilder *builder = ArticleBuilder::getInstance();
    builder->buildListItem("text");
    Article *result = builder->getArticle();

    ASSERT_EQ("text", result->getText());
    builder->reset();
    delete builder;
    delete result;
}
TEST(CaseBuilder, buildParagraph)
{
    ArticleBuilder *builder = ArticleBuilder::getInstance();
    builder->buildParagraphBegin(2, "paragraph測試");
    builder->buildListItem("list1");
    builder->buildText("text");
    builder->buildParagraphEnd();
    Article *result = builder->getArticle();
    ASSERT_EQ("paragraph測試", result->getText());
    builder->reset();
    delete builder;
    delete result;
}