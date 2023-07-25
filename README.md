Charles He        hxh190024
Xavier Mendez  xlm200000


Description

This program implements a barrier in C++ that solves the prefix sum problem using Hillis and steeles parallel algorithm with a spatial complexity of O(n). The barrier uses a waiting incrementer protected by a semaphore lock and utilizes two semaphores to create a reusable gate. The first gate blocks all the processes except the last which will release it, this occurs due to the first gate being initialized to closed. Once the processes are released past the first gate then the processes get blocked at gate two until the last process which releases the remaining processes one by one, this occurs due to the last process through gate one setting gate two to busy. The last process through gate two resets gate one for the next use.


How to Run the Program

Run the program using the following commands:
Make
./prefix-sum <arraySize>  <threadCount>  <outputFileName>

Where:
<arraySize> is the length of the array
<threadCount> is the number of threads to be executed concurrently
<outputFileName> is the name of the file that stores the output array

Example:
{cslinux2:~/cs4348/OperatingSystemsProject} ./prefix-sum 4000000 120 output.txt

Once the program successfully executes, you can open up <outputFileName> to see the output array.

Example:
{cslinux2:~/cs4348/OperatingSystemsProject} less output.txt