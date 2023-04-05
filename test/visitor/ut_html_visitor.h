#include <gtest/gtest.h>
#include <string>
#include "../../src/paragraph.h"
#include "../../src/list_item.h"
#include "../../src/text.h"
#include "../../src/visitor/html_visitor.h"
#include <iostream>
TEST(CaseHtml, text)
{

        Text *t = new Text("測試");
        HtmlVisitor visitor;
        visitor.visitText(t);
        std::string str = visitor.getResult();
        ASSERT_EQ("<span>測試</span>", str);
        delete t;
}
TEST(CaseHtml, listItem)
{
        ListItem *t = new ListItem("測試");
        HtmlVisitor visitor;
        visitor.visitListItem(t);
        std::string str = visitor.getResult();

        ASSERT_EQ("<li>測試</li>", str);
        delete t;
}
TEST(CaseHtml, Paragraph)
{
        Paragraph *p = new Paragraph(2, "paragraph測試");
        HtmlVisitor visitor;
        visitor.visitParagraph(p);
        std::string str = visitor.getResult();

        ASSERT_EQ("<div><h2>paragraph測試</h2></div>", str);
        delete p;
}
TEST(CaseHtml, ParagraphComplex)
{
        Paragraph *p = new Paragraph(1, "title");
        p->add(new ListItem("list1"));
        p->add(new ListItem("list2"));
        p->add(new Text("text"));
        Paragraph *p2 = new Paragraph(2, "title2");
        p2->add(new ListItem("list3"));
        p2->add(new ListItem("list4"));
        p2->add(new Text("sub text"));
        p->add(p2);
        HtmlVisitor visitor;
        visitor.visitParagraph(p);
        std::string str = visitor.getResult();

        ASSERT_EQ("<div><h1>title</h1><li>list1</li><li>list2</li><span>text</span><div><h2>title2</h2><li>list3</li><li>list4</li><span>sub text</span></div></div>", str);
        delete p;
}
