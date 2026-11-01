
1. Algorithm
Definition: An algorithm is a finite sequence 
of well-defined steps used to solve a problem.

Five characteristics of an algorithm --- Remember I-O-F-D-E:
 1. I -- Input: accepts zero or more inputs.
 2. O -- Output: produces at least one output.
 3. F -- Finiteness: terminates after a finite number of steps.
 4. D -- Definitness: every step is clear and unambiguous.
 5. E -- Effectiveness: every step is simple and executable.

// For Example 
// We just apply this code.
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a , b;
    cin>>a;
    cin>>b;
    int sum = a + b;
    cout<< sum << endl;
    return 0;
}

2. Algorithm Efficiency
Definition: Algorithm efficiency measures how effectively 
an algorithm uses time and memory to solve a problem.
Two main measures:
Measure                  Meaning                                   Example
Time Complexity          How running time grows with input size n. O(n) 
Space Complexity         How extra memory grows with input size n. O(1)

Common time complexities

Complexity        Name         Example 
O(1)              Constant     Access an array element
O(log n)          Logarithmic  Binary Search
O(n)              Linear       Linear Search
O(nlogn)          Linearithmic Merge Sort
O(n^2)            Quadratic    Basic Bubble Sort
O(2^n)            Exponential  Some recursive subset algorithms 
O(n!)             Factorial    Brute-force permutations 
Memory trick: As input grows, lower time complexity usually means better scalability.
O(1)<O(log n)<O(n)<O(nlogn)<O(n^2)<O(2^n)<O(n!)
This is the usual order of growth, from slower to faster-growing functions.
Best, Average and Worst Cases 
 1. Best Case: Minimum time taken for any input of size n.
 2. Average Case: Expected time over a specified input distribution.
 3. Worst Case: Maximum time taken for any input size n.
Example: Linear Search in an array of n elements.
Case            Situation                   Time 
Best            Target is first             O(1)
Average         Target is around the middle O(n)
Worst           Target is last or absent    O(n)
Remember: Best = minimum , Average =  expected , Worst = maximum.
3. Algorithm Accuracy(Correctness)
Definition: Algorithm accuracy means an algorithm produces the correct result 
for the given input according to the problem's requirements.
In algorithm design, we usually discuss this as correctness.
Two important conditions
1. Partial correctness: If the algorithm terminates, its output is correct.
2. Termination: The algorithm finishes after a finite number of steps.
Together, partial correctness and termination establish total correctness.
Example: To find the maximum number of two numbers:

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a , b ;
    cin>>a ;
    cin>>b ;
    if(a>b){
        cout<<"a:"<<a<<" ";
    }else{
        cout<<"b:"<<b<<" ";
    }
}

How to check correctness
 1. Test normal inputs.
 2. Test boundary cases, such as equal numbers.
 3. Test unusual inputs, such as negative values.
 4. Verify that every possible valid case is handled.
 5. Prove the logic when required; testing alone cannot prove correctnexx for every input.

4. Common Algorithm Paradigms 
Definition: An algorithmic paradigm is a general problem-solving strategy
used to design algorithms.
Remember the main paradigms with B-D-G-D-B.
Paradigm            Main Idea                           Example
Brute Force         Try all possibillities or use a     Linear Search
                    straightforward solution         
Divide and Conquer  Divide, solve subproblems,combine   Merge Sort
Greedy              Choose the best local option at     Kruskal's Algorithm
                    each step 
Dynamic             Store and reuse overlapping         Fibonacci with 
Programming         subproblem results                  memorization

Backtracking        Explore choices; undo invalid       N-Queens 
                    choices
Other approaches include randomized algorithms and transform-and-conquer.
Easy way to remember 
 1. Brute Force: Try
 2. Divide and Conquer: Divide 
 3. Greedy: Choose 
 4. Dynamic Programming: Remember 
 5. Backtracking: Try and undo.

Important difference: Greedy makes local choices that may not produce a global optimum 
for every problem. 
Dynamic Programming compares or combines subproblem results to obtain an 
optimal answer when its conditions are satisfied.

5. Brute- Force Approach
Definition: Brute force is a straightforward problem-solving 
approach that tries all possible candidates or uses a direct methosd until a solution is found.
Example 1: Linear Search 
Find 7 in the array[4,2,7,9]
          4 -> 2 -> 7 -> 9
     Check 4->Check 2-> Find 7 -> Stop
     Target found at index 2(third position)
Pseudocode:
LINEAR_SEARCH(A,n,target)
    FOR i=0 TO n-1
        IF A[i] == target
        RETURN i 
    RETURN -1
1. Best-case time: O(1)
2. Wors-case time: O(n)
3. Extra space: O(1)
Example 2: Brute-Force Password/ Combination Search
Try every allowed combination until the correct one is found.
If there are k possible combinations, the worst case may require checking k candidates.
Advantages and Disadvantages 
Advantages                      Disadvantages 
Simple to understand            Can be slow 
Easy to implement               May check many unnecessary candidates 
Often easy to verify            May not scale to large inputs 
Useful for small inputs         Some problems have exponentially many possibilities 
Exam sentence: Brute force is simple and often reliable, but its time complexity can be high when the number of candidates is large.
6. Pseudocode
Definition: Pseudocode is an informal, language-independent way of describing an algorithm using simple English and programming-like statements.

It explains the logic without requiring exact C++ or Java syntax.
Common pseudocode keywords
Keyword	       Meaning
START, STOP	   Begin/end
INPUT, READ	   Receive data
OUTPUT, PRINT  Display result
IF - ELSE	   Make a decision
FOR	           Repeat a known number of times
WHILE	       Repeat while a condition is true
RETURN	       Send back a result
←	           Assignment

Example: Find the largest of three numbers
Pseudocode:
START
    INPUT a, b, c

    max ← a

    IF b > max
        max ← b

    IF c > max
        max ← c

    OUTPUT max
STOP


Dry run for a = 10, b = 25, c = 15:
Step	                 max
Initially	              10
Check b > max	          25
Check c > max	          25
Output	                  25

Rules for writing good pseudocode
1. Use simple, clear statements.
2. Write one logical step per line.
3. Indent conditions and loops.
4. Use meaningful variable names.
5. Include input, processing, output, and termination.
6. Avoid language-specific syntax unless required.
Pseudocode vs. actual code: Pseudocode explains the logic; a programming
language implements it.
