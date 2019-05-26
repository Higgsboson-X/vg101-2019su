function sorted = mergeSort(A)

	if isempty(A) || length(A) == 1
		sorted = A;
	else
		A1 = mergeSort(A(1:floor(length(A) / 2)));
		A2 = mergeSort(A(floor(length(A) / 2) + 1:end));
		
		sorted = mergeArrays(A1, A2);
	end
	
end