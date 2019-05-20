function sorted = mySort(arr, compareFunc)

	n = length(arr);
	for i = 1:n
		for j = 1:(n - 1)
			if compareFunc(arr(j + 1), arr(j))
				tmp = arr(j);
				arr(j) = arr(j + 1);
				arr(j + 1) = tmp;
			end
		end
	end

	sorted = arr;
