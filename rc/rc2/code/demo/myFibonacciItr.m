function fib = myFibonacciItr(n)

	if n == 1 || n == 2
		fib = 1;
	else
		xc = 1;
		xn = 1;
		for i = 1:(n - 2)
			xt = xn;
			xn = xc + xn;
			xc = xt;
		end
		fib = xn;
	end
	
end
		