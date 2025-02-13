/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2025
 *
 * @file    csc232.h
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Macros, libraries and definitions for use in csc232 assignments.
 * @version 1.0.0
 * @date    01/01/2025
 *
 * @copyright Copyright (c) 2025 James R. Daehn
 */

 #ifndef MSU_CSC232_H
 #define MSU_CSC232_H
 
 #define FALSE 0
 #define TRUE 1
 
 #define EXECUTE_PREAMBLE TRUE
 
 #define TEST_TASK1 TRUE
 #define TEST_TASK2 TRUE
 #define TEST_TASK3 TRUE
 #define TEST_TASK4 FALSE
 #define TEST_TASK5 FALSE
 
 #include <algorithm>
 #include <cassert>
 #include <climits>
 #include <cmath>
 #include <cstdlib>
 #include <cstring>
 #include <ctime>
 #include <fstream>
 #include <iomanip>
 #include <iostream>
 #include <list>
 #include <memory>
 #include <map>
 #include <queue>
 #include <random>
 #include <set>
 #include <stack>
 #include <stdexcept>
 #include <string>
 #include <utility>
 #include <vector>
 
 /** Common iostream objects */
 using std::cerr;
 using std::cin;
 using std::cout;
 using std::endl;
 
 /** Common iomanip objects */
 using std::left;
 using std::right;
 using std::setprecision;
 using std::setw;
 
 namespace task1
 {
     inline unsigned int fib(const unsigned int n)
     {
         // TODO: Task 1 - Implement me properly using a naive, recursive solution
         if (n == 0 || n == 1){
             return 1;
         }
         return fib(n - 1) + fib(n - 2);
     }
 }
 
 namespace task2
 {
     inline unsigned int fib(const unsigned int n)
     {
         static std::map<unsigned int, unsigned int> fibMap{};
         fibMap[0] = 1;
         fibMap[1] = 1;
 
         // TODO: Task 2 - Implement me properly using memoization, i.e., using a top-down approach
         // checks the map and if it is not in it already it will check and store it 
         if(fibMap.find(n) == fibMap.end()){
             fibMap[n] = fib(n - 1) + fib(n - 2);
         }
         return fibMap[n];
     }
 }
 
 namespace task3
 {
     inline unsigned int fib(const unsigned int n)
     {
         // TODO: Task 3 - Implement me properly using a bottom-up approach
         if(n == 0 || n == 1){
             return 1;
         }
         unsigned int previous = 1, current = 1;
         for(unsigned int i = 2; i <= n; ++i ){
             unsigned int newFib = previous + current;
             previous = current; 
             current = newFib;
         }
         return current;
     }
 }
 
 #endif // MSU_CSC232_H
 