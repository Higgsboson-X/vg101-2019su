function merged = mergeArrays(A, B)

	merged = zeros(1, length(A) + length(B));
	k = 1;
	while ~isempty(A) && ~isempty(B)
		if A(1) > B(1)
			merged(k) = B(1);
			B = B(2:end);
		else
			merged(k) = A(1);
			A = A(2:end);
		end
		k = k + 1;
	end
	
	if isempty(A)
		merged(k:end) = B;
	else
		merged(k:end) = A;
	end
	
end