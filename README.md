# LAB02 - An Introduction to Dynamic Programming

In this lab we apply top-down and bottom-up approaches to dynamic
programming in finding the nth Fibonacci number that dramatically improves
the performance of a naive recursive solution.

## Background

As we have seen in lecture, dynamic programming offers us a solution to finding the nth Fibonacci number in _O_(_n_). We have also seen that there are two approaches to dynamic programming: (1) top-down and (2) bottom-up. In this lab we'll explore both approaches to finding the nth Fibonacci number.

Before proceeding with this lab, the student should take the time to read

* Simplifying Dynamic Programming, an article found in Handouts module in
  Brightspace
* [Chapter 5 Recursion: The Mirrors](https://msu.vitalsource.com/reader/books/9780138122782/epubcfi/6/124%5B%3Bvnd.vst.idref%3DP70010183410000000000000000017C9%5D!/4/2%5BP70010183410000000000000000017C9%5D/2/2%5BP70010183410000000000000000017CA%5D/7:0%5B%2C%20Re%5D)
* [Chapter 6 Recursion as a Problem-Solving Technique](https://msu.vitalsource.com/reader/books/9780138122782/epubcfi/6/140%5B%3Bvnd.vst.idref%3DP7001018341000000000000000001BD2%5D!/4/2%5BP7001018341000000000000000001BD2%5D/2/2%5BP7001018341000000000000000001BD3%5D/7:0%5B%2CRec%5D)
* [Online Reference for std::map](https://en.cppreference.com/w/cpp/container/map)

## Objective

Upon successful completion of this lab, the student has learned how to

* Implement various solutions for finding the nth Fibonacci number
* Use associative arrays to help implement a top-down, dynamic programming,
  solution
* Vastly improve the performance of naive recursive solutions

## Getting Started

After accepting this assignment with the provided GitHub Classroom Assignment link, decide how you want to work with
your newly created repository:

- Using Codespaces directly in your web browser that employees the Visual Studio Code online IDE, or
- Using the IDE of your choice on your local machine

### Codespaces

If a Codespace is available for use (and this is your preferred method of development), open your newly created
repository in a Codespace.

At this point, you can skip to [Creating a development branch](#creating-a-development-branch).

### Local Development

Depending upon the IDE of your choice, many of the following steps may be taken within your IDE. It is up to you to
discover these tools (assuming they're available) and learn how to use them appropriately as desired. The following
instructions are assumed to take place within a terminal window. Note: many IDEs provide a terminal window as well.

#### Cloning your repository

The command you use to clone is slightly different depending upon whether
you're using `git` via `https`, `ssh`, or using the GitHub Cli via `gh`.

If you're using the `https` protocol, your clone command is:

```shell
git clone https://github.com/msu-csc232-sp25/<repo-name>.git
```

If you're using the `ssh` protocol, your clone command is:

```shell
git clone git@github.com:msu-csc232-sp25/<repo-name>.git
```

Finally, if you're using the GitHub CLI (`gh`), your clone command is:

```shell
gh repo clone msu-csc232-sp25/<repo-name>
```

After cloning the repository, navigate into the newly cloned repository:

```shell
cd <repo-name>
```

#### Creating a development branch

Next, create a branch named `develop`. Please note: The name of this branch **must** be as specified and will be, to the
grading scripts, case-sensitive.

```shell
git checkout -b develop
```

Make sure you are on the `develop` branch before you get started. Make all your commits on the `develop` branch.

```bash
git status
```

_You may have to type the `q` character to get back to the command line prompt after viewing the status._

## Tasks

This assignment consists of the following tasks:

- Task 1: Implement a naive solution
- Task 2: Implement a top-down solution with memoization
- Task 3: Implement a bottom-up (iterative) solution

### Task 1: Implement a naive solution

```c++
/**
 * Calculating the nth Fibonacci sequence using recursion is straightforward,
 * given the following recursive relation.
 * Note: It is assumed that the "first" Fibonacci number is associated
 * with n = 0. That is,
 *
 * fib(n) = 1 if n == 0 or n == 1
 *        = fib(n - 1) + fib(n - 2) for n > 1
 *
 * In other words,
 *
 * n:      0   1   2   3   4   5 ...
 * fib(n): 1   1   2   3   5   8 ...
 */
```

#### Steps

1. Locate the `TEST_TASK1` macro definition in the [include/csc232.h](include/csc232.h) header file and toggle its value from `FALSE` to `TRUE`.
2. Locate the `TODO: Task 1` in the [include/csc232.h](include/csc232.h)
   header file and implement a naive, recursive solution to finding the nth
   Fibonacci number.
3. Test your solution by running the `task1_test` target.
4. When you are happy with your results, stage, commit, and push your
   changes to GitHub.

### Task 2: Implement a top-down solution with memoization

The top-down approach is a technique of saving values that have already been
calculated, a technique that is referred to as _memoization_. With this technique we first break the problem up into sub-problems and then calculate and store values. To facilitate this approach we can use a _map_ structure. A map is also known as an "associative array" in which "keys" are associated with "values." The arrays you have worked with thus far _could_ be thought of as an associative map wherein the "key" is an integer (i.e., the index into the array), and of course, the "value" is the contents of the array at that index (key). Fortunately for us, the standard template library includes such a structure. The program  `demo.cpp` in this repo demonstrates the use of a map, and is shown below:

```
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>

int main() {
    std::map<std::string, char> grade_list;
    // Assign "John" a grade of 'C'
    grade_list["John"] = 'C';
    std::cout << "John's grade = " << grade_list["John"] << std::endl;

    // Raise his grade
    grade_list["John"] = 'B';
    std::cout << "After raising his grade, " << std::endl;

    // Find an entry in the map. The member function find(key) returns an
    // iterator; end() is an iterator that points to the "end" of the map.
    // If we haven't "reached" the end of the map, the key is in the map.
    if (grade_list.find("John") != grade_list.end()) {
        std::cout << "John's grade = " << grade_list["John"] << std::endl;
    }

    // On the other hand, if we have reached the "end" of the map using find(key)
    // then the key isn't in the map.
    if (grade_list.find("Jim") == grade_list.end()) {
        std::cout << "Jim wasn't found in the map" << std::endl;
    } else {
        std::cout << "Jim's grade = " << grade_list["Jim"] << std::endl;
    }

    // Let's associate another key/value pair in the map:
    grade_list["Sue"] = 'A';

    // Iterators "point" to elements in the map. Each element in the map has
    // a key/value pair named "first" (the key) and "second" (the value). Two
    // common iterators are begin() and end(). NOTE: end() doesn't point to
    // anything
    // "John" <- 'B'           <- grade_list.begin() points here
    // "Sue"  <- 'A'
    //                         <- grade_list.end() points here, i.e. just after
    //                            the last item in the map. Trying to access items
    //                            pointed to by end() will result in a Segmentation
    //                            fault and will dump the core.
    std::cout << "grade_list.begin()->first = " << grade_list.begin()->first
              << std::endl;
    std::cout << "grade_list.begin()->second = " << grade_list.begin()->second
              << std::endl;

    // We can use these pointers to iterator through the map
    std::cout << "Mappings in grade_list:" << std::endl;
    for (std::map<std::string, char>::iterator it = grade_list.begin(); it != grade_list.end(); ++it) {
        std::cout << std::setw(4) << it->first << " <-- " << it->second << std::endl;
    }

    // A map that maps integers to integers
    std::map<int, int> m;
    m[0] = 1;
    m[1] = 1;
    for (std::map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
        std::cout << it->first << " <-- " << it->second << std::endl;
    }

    return EXIT_SUCCESS;
}
```

For more details and a quick tutorial on using the map found in the STL, see [STL Maps -- Associative Arrays](http://www.cprogramming.com/tutorial/stl/stlmap.html).

With this understanding of the `map` object, let us return to the top-down approach to finding the nth Fibonacci number using a map.

Suppose we have a simple `map` object, `m`, which maps each Fibonacci number calculated that has already been calculated to its result, and we modify our function to use it and update it. The resulting function requires only _O_(_n_) time instead of exponential time (but requires _O_(_n_) space):

```
// This, of course, is just pseudo-code
map<int, int> m
m[0] = 1
m[1] = 1
function fib(n)
   if key n is not in map m
      m[n] = fib(n - 1) + fib(n - 2)
   return m[n]
```

When you locate the `TODO: Task 2` in the [include/csc232.h](include/csc232.h) header file, you'll find such a map declared above the comment. You should also notice that this map was declared as a `static` object. We do this because as a `static` object declared within a function, it will be reused with each successive (recursive) invocation of the function as opposed to being recreated upon each invocation.

#### Steps

1. Locate the `TEST_TASK2` macro definition in the [include/csc232.h](include/csc232.h) header file and toggle its value from `FALSE` to `TRUE`.
2. Locate the `TODO: Task 2` in the [include/csc232.h](include/csc232.h)
   header file and implement a top-down solution to finding the nth
   Fibonacci number.
3. Test your solution by running the `task2_test` target.
4. When you are happy with your results, stage, commit, and push your
   changes to GitHub.

### Task 3: Implement a bottom-up (iterative) solution

In the bottom-up approach, we calculate the smaller values of the Fibonacci sequence first, then build larger values from them. This method also uses _O_(_n_) time since it contains a loop that repeats _n_ − 1 times, but it only takes constant (_O_(1)) space, in contrast to the top-down approach which requires _O_(_n_) space to store the map.

```
// again, using pseudo-code
function fib(n)
    if n <= 1
        return 1
    else
        var previousFib = 1, currentFib = 1
        repeat n − 1 times // loop is skipped if n = 1
            var newFib = previousFib + currentFib
            previousFib = currentFib
            currentFib  = newFib
    return currentFib
```

#### Steps

1. Locate the `TEST_TASK3` macro definition in the [include/csc232.h](include/csc232.h) header file and toggle its value from `FALSE` to `TRUE`.
2. Locate the `TODO: Task 3` in the [include/csc232.h](include/csc232.h)
   header file and implement a bottom-up solution to finding the nth
   Fibonacci number.
3. Test your solution by running the `task3_test` target.
4. When you are happy with your results, stage, commit, and push your
   changes to GitHub.

## Submission Details

Before submitting your assignment, be sure you have pushed all your changes to GitHub. If this is the first time you're
pushing your changes, the push command will look like:

```bash
git push -u origin develop
```

If you've already set up remote tracking (using the `-u origin develop` switch), then all you need to do is type

```bash
git push
```

As usual, prior to submitting your assignment on Brightspace, be sure that you have committed and pushed your final
changes to GitHub. Once your final changes have been pushed, create a pull request that seeks to merge the changes in
your `develop` branch into your `trunk` branch.

You can use `gh` to create this pull request right from your command-line prompt:

```bash
gh pr create --assignee "@me" --title "Some appropriate title" --body "A message to populate description, e.g., Go Bills!" --head develop --base trunk --reviewer msu-csc232-sp25/graders
```

An "appropriate" title is at a minimum, the name of the assignment, e.g., `LAB02` or `HW04`, etc.

Once your pull request has been created, submit the URL of your assignment _repository_ (i.e., _not_ the URL of the pull
request) as a Text Submission on Brightspace. Please note: the timestamp of the submission on Brightspace is used to
assess any late penalties if and when warranted, _not_ the date/time you create your pull request. **No exceptions will
be granted for this oversight**.

### Due Date

Your assignment submission is due by the end of your lab period.

### Grading Rubric

This assignment is worth **3 points**.

| Criteria           | Exceeds Expectations         | Meets Expectations                  | Below Expectations                  | Failure                                        |
|--------------------|------------------------------|-------------------------------------|-------------------------------------|------------------------------------------------|
| Pull Request (20%) | Submitted early, correct url | Submitted on-time; correct url      | Incorrect URL                       | No pull request was created or submitted       |
| Code Style (20%)   | Exemplary code style         | Consistent, modern coding style     | Inconsistent coding style           | No style whatsoever or no code changes present |
| Correctness^ (60%) | All unit tests pass          | At least 80% of the unit tests pass | At least 60% of the unit tests pass | Less than 50% of the unit tests pass           |

^ _The Google Test unit runner will calculate the correctness points based purely on the fraction of tests passed_.

### Late Penalty

* In the first 24-hour period following the due date, this assignment will be penalized 20%.
* In the second 24-hour period following the due date, this assignment will be penalized 40%.
* After 48 hours, the assignment will not be graded and thus earns no points.

## Disclaimer & Fair Use Statement

This repository may contain copyrighted material, the use of which may not
have been specifically authorized by the copyright owner. This material is
available in an effort to explain issues relevant to the course or to
illustrate the use and benefits of an educational tool. The material
contained in this repository is distributed without profit for research and
educational purposes. Only small portions of the original work are being
used and those could not be used to easily duplicate the original work.
