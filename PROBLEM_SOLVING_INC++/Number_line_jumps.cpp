/*You are choreographing a circus show with various animals. For one act, you are given two kangaroos on a number line ready to jump in the positive direction (i.e, toward positive infinity).

The first kangaroo starts at location x1 and moves at a rate of v1 meters per jump.
The second kangaroo starts at location x2 and moves at a rate of v2 meters per jump.
You have to figure out a way to get both kangaroos at the same location at the same time as part of the show. If it is possible, return YES, otherwise return NO.

For example, kangaroo 1 starts at x1 = 2 with a jump distance v1 = 1 and kangaroo 2 starts at x2 = 1 with a jump distance of v2 = 2. After one jump, they are both at x = 3, (x1+v1 = 2 + 1=3, x2+v2 = 1+2 = 3 ), so our answer is YES.

Returns

string: either YES or NO
Input Format

A single line of four space-separated integers denoting the respective values of x1, v1, x2and v2.

Output Format

Print YES if they can land on the same location at the same time; otherwise, print NO.

Note: The two kangaroos must land at the same location after making the same number of jumps.

sample input 0
      
     0 3 4 2

sample output 0
     
         YES

Explanation 0

The two kangaroos jump through the following sequence of locations:

number line jump solution in c++
From the image, it is clear that the kangaroos meet at the same location (number 12 on the number line) after same number of jumps (4 jumps), and we print YES.

sample input 1

    0 2 5 3

sample output 1

       NO

Explanation 1

The second kangaroo has a starting location that is ahead (further to the right) of the first kangaroo’s starting location (i.e. x2>x1). Because the second kangaroo moves at a faster rate (meaning v2>v1) and is already ahead of the first kangaroo, the first kangaroo will never be able to catch up. Thus, we print NO.*/
