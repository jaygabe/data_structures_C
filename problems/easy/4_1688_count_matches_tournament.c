#include <stdio.h>
#include <assert.h>

int numberOfMatches(int n)
{
    // Initialize a variable to keep track of the total number of matches
    int matches = 0;
    // While n is greater than 1
    while (n > 1)
    {
        // If n is odd
        if (n % 2 == 1)
        {
            // Subtract one from n and divide by 2
            matches += (n - 1) / 2;
            n = (n - 1) / 2;
        }
        else
        {
            // Divide n by 2
            matches += n / 2;
            n = n / 2;
        }       
    }

    // Return the total number of matches
    return matches;
}

int main() {
    int test_cases[] = {7, 14, 1, 200, 3}; // Example test cases
    int expected_outputs[] = {6, 13, 0, 199, 2}; // Expected outputs for the test cases
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_tests; i++) {
        int result = numberOfMatches(test_cases[i]);
        int expected = expected_outputs[i];
        assert(result == expected); // Test if the result matches the expected output
        printf("Test case %d: %d teams -> %d matches (Expected: %d)\n", i + 1, test_cases[i], result, expected);
    }

    printf("All tests passed successfully.\n");
    return 0;
}