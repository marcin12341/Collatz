
School project for Algorithms and Data Structures class.

# The Collatz function
<p>The Collatz function is a function f:ℕ⟶ℕ such that f(n)=3n+1 if n is odd and f(n)=n/2 if n is even. Use the function on the smallest/largest number of a given sequence.<br/>
If there are two or more smallest/largest numbers we choose the first one in the sequence.<br/>
If the smallest numbers are 1s then we pick the second smallest number.<br/>
If after applying the Collatz function the result does not fit in unsigned int (32-bit) then the result is omitted. The omitted numbers from the sequence are not taking into account when the smallest/largest numbers are searched.<br/>
<h4>Input</h4>
In the first line there is a number n - the number of elements in the sequence (n<60000).<br/>
In the second line there are n numbers - the sequence. All the number are positive integers that fit into unsigned int. <br/>
In the third line there is a number of commands (q).<br/>
The next q lines consist the commands.<br/>
A command consists of a number k and a charter c. The charter decides the searched number, 's' stands for the smallest numbers, 'l' stands for the largest numbers. The number k describes number of times which searching and applying the Collatz function should occur.<br/>
<h4>Output</h4>
Write the sequence after performing the commands. Instead the omitted numbers write charter 'm'.<br/>
<h3>Examples</h3>
<h5>Input</h5>
4<br/>
1 3 3 2000000001<br/>
2<br/>
3 s<br/>
1 l<br/>

<h5>Output</h5>
1 5 10 m<br/>


<h5>Input</h5>
5<br/>
1 3 3 2345678901 4123456789<br/>
2<br/>
9 s<br/>
1 l<br/>

<h5>Output</h5>
1 2 16 2345678901 m</p>
