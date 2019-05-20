A = zeros(10);
for i = 1:10
	for j = 1:10
		if i == 2 && j == 4
			break;
		end
		A(i, j) = 1;
	end
end

disp(A);
