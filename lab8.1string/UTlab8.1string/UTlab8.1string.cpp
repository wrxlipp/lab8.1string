#include "pch.h"
#include "CppUnitTest.h"
#include "../lab8.1string/lab8.1string.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UTLabTest
{
    TEST_CLASS(UTLabTest)
    {
    public:
        // Тестування функції Count для підрахунку кількості входжень символів "+", "-", "="
        TEST_METHOD(TestCount)
        {
            string testStr = "a+b=c-";  // Тестовий рядок
            int result = Count(testStr);  // Викликаємо функцію для підрахунку
            Assert::AreEqual(result, 3);  // Очікуваний результат: 3 символи "+", "-", "="
        }

        // Тестування функції Change для заміни символів на "**"
        TEST_METHOD(TestChange)
        {
            string testStr = "a+b=c-";  // Тестовий рядок
            string result = Change(testStr);  // Викликаємо функцію для заміни символів

            Assert::AreEqual(result, string("a**b**c**"));  // Очікуваний результат: "a**b**c**"
        }

        // Тест для порожнього рядка (підрахунок символів)
        TEST_METHOD(TestCountEmptyString)
        {
            string testStr = "";  // Порожній рядок
            int result = Count(testStr);  // Викликаємо функцію для підрахунку
            Assert::AreEqual(result, 0);  // Очікуваний результат: 0 входжень
        }

        // Тест для рядка без символів "+", "-", "=" (заміна не відбудеться)
        TEST_METHOD(TestChangeNoReplacement)
        {
            string testStr = "abcdef";  // Рядок без символів "+", "-", "="
            string result = Change(testStr);  // Викликаємо функцію для заміни

            Assert::AreEqual(result, string("abcdef"));  // Очікуваний результат: "abcdef" (рядок не змінюється)
        }

        // Тест для рядка з одним символом, який потрібно замінити
        TEST_METHOD(TestChangeSingleCharacter)
        {
            string testStr = "+";  // Тестовий рядок, що містить лише один символ "+"
            string result = Change(testStr);  // Викликаємо функцію для заміни

            Assert::AreEqual(result, string("**"));  // Очікуваний результат: "**"
        }

        // Тест для рядка з декількома символами, які потрібно замінити
        TEST_METHOD(TestChangeMultipleCharacters)
        {
            string testStr = "++-==";  // Тестовий рядок
            string result = Change(testStr);  // Викликаємо функцію для заміни

            Assert::AreEqual(result, string("****-****"));  // Очікуваний результат: "****-****"
        }
    };
}