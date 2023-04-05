#include <gtest/gtest.h>
#include "../src/list_item.h"
#include "../src/visitor/markdown_visitor.h"

TEST(CaseListItem, GETTEXT)
{
        ListItem t("測試");
        ASSERT_EQ(t.getText(), "測試");
}
TEST(CaseListItem, ADDException)
{
        ListItem t("測試");
        ListItem *t1 = new ListItem("list2");
        ASSERT_ANY_THROW(t.add(t1));
        delete t1;
}
TEST(CaseListItem, getLevelZero)
{
        ListItem t("測試");
        ASSERT_EQ(t.getLevel(), 0);
}
TEST(CaseListItem, NullIteratorFirstException)
{
        ListItem t("測試");
        Iterator *it = t.createIterator();
        ASSERT_ANY_THROW(it->first());
        delete it;
}
TEST(CaseListItem, NullIteratorCurrentItemException)
{
        ListItem t("測試");
        Iterator *it = t.createIterator();
        ASSERT_ANY_THROW(it->currentItem());
        delete it;
}
TEST(CaseListItem, NullIteratorNextException)
{
        ListItem t("測試");
        Iterator *it = t.createIterator();
        ASSERT_ANY_THROW(it->next());
        delete it;
}
TEST(CaseListItem, NullIteratorIsDoneTrue)
{
        ListItem t("測試");
        Iterator *it = t.createIterator();
        ASSERT_TRUE(it->isDone());
        delete it;
}
TEST(CaseListItem, accept)
{
        ListItem t("測試");
        MarkdownVisitor visitor;
        t.accept(&visitor);
        std::string str = visitor.getResult();

        ASSERT_EQ("- 測試\n", str);
}