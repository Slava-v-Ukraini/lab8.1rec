#include "pch.h"
#include "CppUnitTest.h"
#include "../PR8.1rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UTLabTest
{
    TEST_CLASS(UTLabTest)
    {
    public:
        TEST_METHOD(TestCountNoGroups)
        {
            char testStr[] = "Hello World!";
            int result = Count(testStr, 0);
            Assert::AreEqual(0, result);
        }

        TEST_METHOD(TestCountWithGroups)
        {
            char testStr[] = "abc,-def,-ghi,-jkl";
            int result = Count(testStr, 0);
            Assert::AreEqual(3, result);
        }

        TEST_METHOD(TestCountEmptyString)
        {
            char testStr[] = "";
            int result = Count(testStr, 0);
            Assert::AreEqual(0, result);
        }

        TEST_METHOD(TestChangeNoGroups)
        {
            char testStr[] = "Hello World!";
            char dest[101] = { '\0' };
            char* result = Change(dest, testStr, dest, 0);
            Assert::AreEqual("Hello World!", result);
        }

        TEST_METHOD(TestChangeWithGroups)
        {
            char testStr[] = "abc,-def,-ghi,-jkl";
            char dest[151] = { '\0' };
            char* result = Change(dest, testStr, dest, 0);
            Assert::AreEqual("abc*def*ghi*jkl", result);
        }

        TEST_METHOD(TestChangeEmptyString)
        {
            char testStr[] = "";
            char dest[101] = { '\0' };
            char* result = Change(dest, testStr, dest, 0);
            Assert::AreEqual("", result);
        }

        TEST_METHOD(TestChangeSingleGroup)
        {
            char testStr[] = ",-";
            char dest[101] = { '\0' };
            char* result = Change(dest, testStr, dest, 0);
            Assert::AreEqual("*", result);
        }
    };
}
