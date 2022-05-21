#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP 6.1/Array.h"
#include "../OOP 6.1/Array.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			typedef Array::value_type* TArray;
			int n = 0;
			Array c = Array(2 * n);
			Assert::AreEqual(0., c.sum());
		}
	};
}
