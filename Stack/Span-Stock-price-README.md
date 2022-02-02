Stock span problem :
task : The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stocks price for all n days. 
The span Si of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.
Explanation:
Brute force:   TC: O(n^2)
 For every i check in left direction. check first highest day when price higher than current price .
there we get the index : 
then find the span : i- previous highest index ;

Efficient way : TC: O(N)
1. take a stack (day(indices)  , prices) ;
2.pop if get higher value than top of stack ;
3. base case : if current value is the highest , corner case no value left in stack greater than that then, make
 span = index+1
4.stack==empty , span = idx+1;
