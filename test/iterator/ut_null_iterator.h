#include <gtest/gtest.h>
#include "../../src/text.h"
#include "../../src/list_item.h"
#include "../../src/paragraph.h"
#include "../../src/iterator/null_iterator.h"
TEST(CaseNullIterator, NullIteratorFirstThrowException)
{
    NullIterator *it = new NullIterator();
    ASSERT_ANY_THROW(it->first());
    delete it;
}
TEST(CaseNullIterator, NullIteratorCurrentItemThrowException)
{
    NullIterator *it = new NullIterator();
    ASSERT_ANY_THROW(it->currentItem());
    delete it;
}
TEST(CaseNullIterator, NullIteratorNextThrowException)
{
    NullIterator *it = new NullIterator();
    ASSERT_ANY_THROW(it->next());
    delete it;
}
TEST(CaseNullIterator, NullIteratorIsDoneTrue)
{
    NullIterator *it = new NullIterator();
    ASSERT_TRUE(it->isDone());
    delete it;
}