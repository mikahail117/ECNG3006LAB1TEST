For question 1 in the lab, the magnitude function was created and called to test whether our function could accurately detect the magnitude of a number.
The test_add function was modified to catch errors with int
being classified as an 8-bit as opposed to a 16-bit number
. This was done by checking if the two added numbers were 
equal to the number obtained from running the function. If
the number for the add function was different we could 
assume that it was because of an overflow error which the
add function would not be able to accurately detect.