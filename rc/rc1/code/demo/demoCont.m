clearvars;

A = zeros(10);
for i = 1:10
	for j = 1:10
		if i == 3 && j == 4
			continue;
		end
		A(i, j) = 1;
	end
end

disp(A);
