function [match, dir] = evalBoard(board, word, r, c)

[rows, cols] = size(board);
dirs = {'up', 'down', 'left', 'right', ...
	'up right', 'up left', 'down right', 'down left'};

length = size(word);

for dir = dirs
	match = 1;
	curR = r;
	curC = c;
	for ind = 1:length(2)
		if curR > rows || curR < 1 || curC > cols || curC < 1
			match = 0;
			break;
		end
		if lower(char(board(curR, curC))) ~= lower(word(ind))
			match = 0;
			break;
		end
		[curR, curC] = goNext(curR, curC, dir);
	end
	if match == 1
		break;
	end
end