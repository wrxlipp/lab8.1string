#include "pch.h"
#include "CppUnitTest.h"
#include "../lab8.1string/lab8.1string.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UTLabTest
{
    TEST_CLASS(UTLabTest)
    {
    public:
        // ���������� ������� Count ��� ��������� ������� �������� ������� "+", "-", "="
        TEST_METHOD(TestCount)
        {
            string testStr = "a+b=c-";  // �������� �����
            int result = Count(testStr);  // ��������� ������� ��� ���������
            Assert::AreEqual(result, 3);  // ���������� ���������: 3 ������� "+", "-", "="
        }

        // ���������� ������� Change ��� ����� ������� �� "**"
        TEST_METHOD(TestChange)
        {
            string testStr = "a+b=c-";  // �������� �����
            string result = Change(testStr);  // ��������� ������� ��� ����� �������

            Assert::AreEqual(result, string("a**b**c**"));  // ���������� ���������: "a**b**c**"
        }

        // ���� ��� ���������� ����� (��������� �������)
        TEST_METHOD(TestCountEmptyString)
        {
            string testStr = "";  // ������� �����
            int result = Count(testStr);  // ��������� ������� ��� ���������
            Assert::AreEqual(result, 0);  // ���������� ���������: 0 ��������
        }

        // ���� ��� ����� ��� ������� "+", "-", "=" (����� �� ����������)
        TEST_METHOD(TestChangeNoReplacement)
        {
            string testStr = "abcdef";  // ����� ��� ������� "+", "-", "="
            string result = Change(testStr);  // ��������� ������� ��� �����

            Assert::AreEqual(result, string("abcdef"));  // ���������� ���������: "abcdef" (����� �� ���������)
        }

        // ���� ��� ����� � ����� ��������, ���� ������� �������
        TEST_METHOD(TestChangeSingleCharacter)
        {
            string testStr = "+";  // �������� �����, �� ������ ���� ���� ������ "+"
            string result = Change(testStr);  // ��������� ������� ��� �����

            Assert::AreEqual(result, string("**"));  // ���������� ���������: "**"
        }

        // ���� ��� ����� � ��������� ���������, �� ������� �������
        TEST_METHOD(TestChangeMultipleCharacters)
        {
            string testStr = "++-==";  // �������� �����
            string result = Change(testStr);  // ��������� ������� ��� �����

            Assert::AreEqual(result, string("****-****"));  // ���������� ���������: "****-****"
        }
    };
}