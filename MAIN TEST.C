#include<stdio.h>
#include<assert.h>
#include"C:\Users\User\Desktop\src\unity.h"
#include"C:\Users\User\Desktop\src\unity.c"
#include<iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

unsigned int magnitude(int x) {
    return (unsigned int) abs(x);
}

void setUp(void){

}
void tearDown(void){

}

void test_magnitude_of_signed_integers(void) {
    // Test that the magnitude of a negative integer is correctly computed
    int test_val = -123; // The unsigned magnitude of -123 is 123
    unsigned int expected = 123;
    TEST_ASSERT_EQUAL_UINT(expected, magnitude(test_val));
}
void test_add(void){
    // Test within safe 8-bit range
    for (int i = 0; i <= 127; i++) {   
        for (int j = 0; j <= 127 - i; j++) {
            TEST_ASSERT_EQUAL_INT(i+j, add(i, j));
        }
    }

    // Test cases that should cause overflow if int is 8-bit
    //TEST_ASSERT_EQUAL_INT(-128, add(127, 1)); // 127 + 1 = 128, which overflows to -128 if int is signed 8-bit
    //TEST_ASSERT_EQUAL_INT(-127, add(127, 2)); // Checking further overflow behavior
    
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_add);
    RUN_TEST(test_magnitude_of_signed_integers);
    UNITY_END();
    return 0;
}