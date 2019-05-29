function solved = sudokuSolver(board)
	
	solved = 0;
	filled = 1;
	for i = 1:9
		for j = 1:9
			if board(i, j) == 0
				filled = 0;
				for k = 1:9
					rStart = floor((i - 1) / 3) * 3 + 1;
					cStart = floor((j - 1) / 3) * 3 + 1;
					
					rEnd = rStart + 2;
					cEnd = cStart + 2;
					
					if sum(sum(board(rStart:rEnd, cStart:cEnd) == k)) == 0 ...
							&& sum(board(:, j) == k) == 0 ...
							&& sum(board(i, :) == k) == 0
						board(i, j) = k;
						solved = sudokuSolver(board);
					end
					if solved
						break;
					end
				end
			end
			if solved || ~filled
				break;
			end
		end
		if solved || ~filled
			break;
		end
	end
	
	if filled
		solved = 1;
		disp(board);
	end
	
end
