#include <gtest/gtest.h>
#include "../../src/builder/article_scanner.h"
#include <string>
TEST(Scanner, nextToken)
{
    std::string input = "I ListItem eee {\"string\"555\"next\"}too6a";
    ArticleScanner scanner(input);
    std::string first = scanner.nextToken();     // `first` is "ListItem"
    ASSERT_EQ("ListItem", first);
    std::string second = scanner.nextStr();      // `second` is "string"
    ASSERT_EQ("string", second);
    std::string third = scanner.nextToken();     // `third` is "}"
    ASSERT_EQ("}", third);
}
TEST(Scanner, nextStr)
{
    std::string input = "I ListItem eee {\"string\"555\"next\"}too6a";
    ArticleScanner scanner(input);
    std::string first = scanner.nextToken();     // `first` is "ListItem"
    ASSERT_EQ("ListItem", first);
    std::string second = scanner.nextStr();      // `second` is "string"
    ASSERT_EQ("string", second);
    std::string third = scanner.nextToken();     // `third` is "}"
    ASSERT_EQ("}", third);
    int fourth = scanner.nextInt();              // `fourth` is 6
    ASSERT_EQ(6, fourth);
}
TEST(Scanner, nextInt)
{
    std::string input = "I ListItem eee {\"string\"555\"next\"}too6a";
    ArticleScanner scanner(input);
    std::string first = scanner.nextToken();     // `first` is "ListItem"
    ASSERT_EQ("ListItem", first);
    std::string second = scanner.nextStr();      // `second` is "string"
    ASSERT_EQ("string", second);
    std::string third = scanner.nextToken();     // `third` is "}"
    ASSERT_EQ("}", third);
    int fourth = scanner.nextInt();              // `fourth` is 6
    ASSERT_EQ(6, fourth);
}
TEST(Scanner, Scanner_NextThrowException)
{
    std::string input = "I ListItem eee {\"string\"555\"next\"}too6a";
    ArticleScanner scanner(input);
    std::string first = scanner.nextToken();     // `first` is "ListItem"
    ASSERT_EQ("ListItem", first);
    std::string second = scanner.nextStr();      // `second` is "string"
    ASSERT_EQ("string", second);
    std::string third = scanner.nextToken();     // `third` is "}"
    ASSERT_EQ("}", third);
    int fourth = scanner.nextInt();              // `fourth` is 6
    ASSERT_EQ(6, fourth);
    scanner.nextToken();
    ASSERT_ANY_THROW(scanner.nextToken());
}
TEST(Scanner, Scanner_NextIntThrowException)
{
   std::string input = "I ListItem eee {\"string\"555\"next\"}too6a";
    ArticleScanner scanner(input);
    std::string first = scanner.nextToken();     // `first` is "ListItem"
    ASSERT_EQ("ListItem", first);
    std::string second = scanner.nextStr();      // `second` is "string"
    ASSERT_EQ("string", second);
    std::string third = scanner.nextToken();     // `third` is "}"
    ASSERT_EQ("}", third);
    int fourth = scanner.nextInt();              // `fourth` is 6
    ASSERT_EQ(6, fourth);
    ASSERT_ANY_THROW(scanner.nextInt());
}