int iterative_Fibonacci(int n)
{
   int current = 1,
       Fibonacci = n,
       previous = 0;

   if (n > 1)
   {
      n -= 1;
      while (n--)
      {
         Fibonacci = previous + current;
         previous = current;
         current = Fibonacci;
      }
   }

   return Fibonacci;
}

int recursive_Fibonacci(int n)
{
   if (n == 0 || n == 1)
      return n;
   else
      return (recursive_Fibonacci(n-1) + recursive_Fibonacci(n-2));
}