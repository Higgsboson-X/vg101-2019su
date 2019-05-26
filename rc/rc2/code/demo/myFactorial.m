function fact = myFactorial(n)

	if n == 0 || n == 1
		fact = 1;
	else
		fact = n * myFactorial(n - 1);
	end
	
end