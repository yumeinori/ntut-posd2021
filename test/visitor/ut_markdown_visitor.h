#include <gtest/gtest.h>
#include <string>
#include "../../src/paragraph.h"
#include "../../src/list_item.h"
#include "../../src/text.h"
#include "../../src/visitor/markdown_visitor.h"
#include <iostream>
TEST(Casemarkdown, text)
{
        Text *t = new Text("測試");
        MarkdownVisitor visitor;
        visitor.visitText(t);
        std::string str = visitor.getResult();
        ASSERT_EQ("測試\n", str);
        delete t;
}
TEST(Casemarkdown, listItem)
{
        ListItem *t = new ListItem("測試");
        MarkdownVisitor visitor;
        visitor.visitListItem(t);
        std::string str = visitor.getResult();
        ASSERT_EQ("- 測試\n", str);
        delete t;
}
TEST(Casemarkdown, Paragraph)
{
        Paragraph *p = new Paragraph(2, "paragraph測試");
        MarkdownVisitor visitor;
        visitor.visitParagraph(p);
        std::string str = visitor.getResult();
        ASSERT_EQ("## paragraph測試\n", str);
        delete p;
}
TEST(Casemarkdown, ParagraphComplex)
{
        Paragraph *p = new Paragraph(2, "paragraph測試");
        p->add(new ListItem("list1"));
        p->add(new Text("text"));
        MarkdownVisitor visitor;
        visitor.visitParagraph(p);
        std::string str = visitor.getResult();
        ASSERT_EQ("## paragraph測試\n- list1\ntext\n", str);
        delete p;
}