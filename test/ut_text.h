#include <gtest/gtest.h>
#include "../src/text.h"
#include "../src/visitor/markdown_visitor.h"

TEST(Casetext, GETTEXT)
{
        Text t("測試");
        ASSERT_EQ(t.getText(), "測試");
}
TEST(Casetext, ADDException)
{
        Text t("測試");
        ListItem *l=new ListItem("list2");
        ASSERT_ANY_THROW(t.add(l));
        delete l;
}
TEST(Casetext, getLevelZero)
{
        Text t("測試");
        ASSERT_EQ(t.getLevel(), 0);
}
TEST(Casetext, NullIteratorFirstException)
{
        Text t("測試");
        Iterator *it = t.createIterator();
        ASSERT_ANY_THROW(it->first());
        delete it;
}
TEST(Casetext, NullIteratorCurrentItemException)
{
        Text t("測試");
        Iterator *it = t.createIterator();
        ASSERT_ANY_THROW(it->currentItem());
        delete it;
}
TEST(Casetext, NullIteratorNextException)
{
        Text t("測試");
        Iterator *it = t.createIterator();
        ASSERT_ANY_THROW(it->next());
        delete it;
}
TEST(Casetext, NullIteratorIsDoneTrue)
{
        Text t("測試");
        Iterator *it = t.createIterator();
        ASSERT_TRUE(it->isDone());
        delete it;
}
TEST(Casetext, accept)
{
        Text t("測試");
        MarkdownVisitor visitor;
        t.accept(&visitor);
        std::string str = visitor.getResult();
        ASSERT_EQ("測試\n", str);
}