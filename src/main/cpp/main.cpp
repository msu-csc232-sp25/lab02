/**
* CSC232 - Data Structures
 * Missouri State University, Spring 2025
 *
 * @file    main.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Entry-point of the main target.
 * @version 1.0.0
 * @date    01/01/2025
 *
 * @copyright Copyright (c) 202 James R. Daehn
 */

#include "csc232.h"

int main(int argc, char* argv[])
{
    // For the naive solution, this may take a noticeable amount of time to complete,
    // particularly on an older, slower, computer.
    static constexpr auto N = 40;
    const auto naive_result = task1::fib(N);
    std::cout << setw(18) << left;
    std::cout << "naive_result:" << naive_result << std::endl;
    const auto top_down_result = task2::fib(N);
    std::cout << setw(18) << left;
    std::cout << "top_down_result:" << top_down_result << std::endl;
    const auto bottom_up_result = task3::fib(N);
    std::cout << setw(18) << left;
    std::cout << "bottom_up_result:" << bottom_up_result << std::endl;

    return EXIT_SUCCESS;
}
