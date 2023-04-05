#include <gtest/gtest.h>
#include "../src/text.h"
#include "../src/list_item.h"
#include "../src/paragraph.h"
#include "../src/visitor/markdown_visitor.h"

TEST(Caseparagraph, GETLEVEL)
{
        Paragraph p(1, "paragraph測試");
        ASSERT_EQ(p.getLevel(), 1);
}
TEST(Caseparagraph, GETTEXT)
{
        Paragraph p(2, "paragraph測試");
        ASSERT_EQ(p.getText(), "paragraph測試");
}
TEST(Caseparagraph, LevelZeroException)
{
        ASSERT_ANY_THROW(Paragraph p(0, "paragraph測試"));
}
TEST(Caseparagraph, LargerThanLevelException)
{
        ASSERT_ANY_THROW(Paragraph p(7, "paragraph測試"));
}
TEST(Caseparagraph, ParagraphLevelLowerOrEqualtest)
{
        Paragraph p(2, "paragraph測試");
        ASSERT_ANY_THROW(p.add(new Paragraph(0, "list1")));
}
TEST(Caseparagraph, Paragraph)
{
        Paragraph p(2, "paragraph測試");
        MarkdownVisitor visitor;
        p.accept(&visitor);
        std::string str = visitor.getResult();

        ASSERT_EQ("## paragraph測試\n", str);
}
TEST(Caseparagraph, accept)
{
        Paragraph p(2, "paragraph測試");
        p.add(new ListItem("list1"));
        p.add(new Text("text"));
        MarkdownVisitor visitor;
        p.accept(&visitor);
        std::string str = visitor.getResult();
        ASSERT_EQ("## paragraph測試\n- list1\ntext\n", str);
}
