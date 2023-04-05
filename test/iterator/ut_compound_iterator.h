#include <gtest/gtest.h>
#include "../../src/text.h"
#include "../../src/list_item.h"
#include "../../src/paragraph.h"
#include "../../src/iterator/compound_iterator.h"
TEST(Compound_Iterator, Compound_iterator)
{
    Paragraph *cs = new Paragraph(2, "paragraph測試");
    ListItem *c1 = new ListItem("list1");
    Text *c2 = new Text("text");
    cs->add(c1);
    cs->add(c2);
    Iterator *it = cs->createIterator();
    //std::cout<<it->currentItem()->info();
    EXPECT_EQ(c1, it->currentItem());
    delete cs;
    delete it;
}
TEST(Compound_Iterator, Compound_iteratorFirst)
{
    Paragraph *cs = new Paragraph(2, "paragraph測試");
    ListItem *c1 = new ListItem("list1");
    Text *c2 = new Text("text");
    cs->add(c1);
    cs->add(c2);
    Iterator *it = cs->createIterator();
    EXPECT_EQ(c1, it->currentItem());
    it->first();
    EXPECT_EQ(c1, it->currentItem());
    delete cs;
    delete it;
}
TEST(Compound_Iterator, Compound_iteratorNext)
{
    Paragraph *cs = new Paragraph(2, "paragraph測試");
    ListItem *c1 = new ListItem("list1");
    Text *c2 = new Text("text");
    cs->add(c1);
    cs->add(c2);
    Iterator *it = cs->createIterator();
    //std::cout<<it->currentItem()->info();
    EXPECT_EQ(c1, it->currentItem());
    it->first();
    EXPECT_EQ(c1, it->currentItem());
    it->next();
    EXPECT_EQ(c2, it->currentItem());
    delete cs;
    delete it;
}
TEST(Compound_Iterator, Compound_iteratorIsdone)
{
    Paragraph *cs = new Paragraph(2, "paragraph測試");
    ListItem *c1 = new ListItem("list1");
    Text *c2 = new Text("text");
    cs->add(c1);
    cs->add(c2);
    Iterator *it = cs->createIterator();
    //std::cout<<it->currentItem()->info();
    EXPECT_EQ(c1, it->currentItem());
    it->first();
    EXPECT_EQ(c1, it->currentItem());
    it->next();
    EXPECT_EQ(c2, it->currentItem());
    it->next();
    EXPECT_EQ(true, it->isDone());
    delete cs;
    delete it;
}
TEST(Compound_Iterator, CurrentItemShouldThrowExceptionWhenIsDone)
{
    Paragraph *cs = new Paragraph(2, "paragraph測試");
    ListItem *c1 = new ListItem("list1");
    Text *c2 = new Text("text");
    cs->add(c1);
    cs->add(c2);
    Iterator *it = cs->createIterator();
    it->first();
    it->next();
    it->next();
    ASSERT_ANY_THROW(it->currentItem());
    delete cs;
    delete it;
}
TEST(Compound_Iterator, NextShouldThrowExceptionWhenIsDone)
{
    Paragraph *cs = new Paragraph(2, "paragraph測試");
    ListItem *c1 = new ListItem("list1");
    Text *c2 = new Text("text");
    cs->add(c1);
    cs->add(c2);
    Iterator *it = cs->createIterator();
    it->first();
    it->next();
    it->next();
    ASSERT_ANY_THROW(it->next());
    delete cs;
    delete it;
}
