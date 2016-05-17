/* Problem 36: Double-base palindromes
 * By: Mark Guerra
 * 12/7/2015
 */

#include "problem036.h"
#include "utils.h"

#include <algorithm>
#include <bitset>

/*
 * Loop from [0] to [1000000] and check if the number is a palindrome.
 * If it is, convert it to binary and check if that binary number
 * is a palindrome. If it is, add the base 10 number [i] to the sum.
 * Finally, return the sum and print it out.
 */

bool problem036::isPalindrome(std::string n) {
    for (int i = n.size() - 1; i >= 0; i--) {
        if (n[i] == n[abs(i - (n.size() - 1))]) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

int problem036::getAnswer() {
    int sum = 0;
    for (int i = 0; i < 1000000; ++i) {
        if (isPalindrome(utils::toString(i))) {
            std::string binary = std::bitset<20>(i).to_string();
            if (isPalindrome(utils::ltrim(binary, '0'))) {
                sum += i;
            }
        }
    }
    return sum;
}