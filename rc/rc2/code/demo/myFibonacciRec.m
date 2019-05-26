function fib = myFibonacciRec(n)

	if n == 1 || n == 2
		fib = 1;
	else
		fib   = myFibonacciRec(n - 1) + myFibonacciRec(n - 2);
	end
	
end