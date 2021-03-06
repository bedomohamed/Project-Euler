/* Problem 47: Distinct primes factors
 * By: Mark Guerra
 * 12/17/2015
 */

#include "main.h"
#include "utils.h"

#include <unordered_set>
#include <iostream>
#include <vector>

/*
 * Start at [644], which we get from the problem.
 * Each time around a loop, check the number of
 * distinct prime factors the number [x] has.
 * If it has 4 distinct prime factors,
 * return it and print it to the screen.
 */

int Problem047::getDistinctPrimeFactors(int n, std::vector<long> primes) {
    int results = 0;
    for (int i = 0; i < primes.size(); ++i) {
        if (primes[i] > n) break;
        if (n % primes[i] == 0) {
            ++results;
        }
    }
    return results;
}

std::string Problem047::get_answer() {
    std::vector<long> primes = utils::generatePrimes(1000);
    int counter = 0;
    int result = 0;
    int x = 643;
    while (true) {
        ++x;
        if (getDistinctPrimeFactors(x, primes) == 4) {
            if (counter == 0) {
                result = x;
            }
            ++counter;
        }
        else {
            counter = 0;
            result = 0;
        }
        if (counter == 4) {
            return std::to_string(result);
        }
    }
}
