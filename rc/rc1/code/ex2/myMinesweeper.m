function myMinesweeper(r, c)

	pd = makedist('Normal');
	board = random(pd, [r, c]);
	% r * c logical matrix, 1 denotes a mine, 0 denotes a safe position;
	board = board > 0;

	lose = 0;
	win = 0;
	display = zeros(r, c);

	% disp(board);

	while ~lose && ~win
		pos = input('Position [r, c]: ');
		if board(pos(1), pos(2))
			lose = 1;
			continue;
		end
		subBoard = board(max(1, pos(1) - 1):min(r, pos(1) + 1), ...
			max(1, pos(2) - 1):min(c, pos(2) + 1));
		display(pos(1), pos(2)) = sum(subBoard(:));
		disp(display);
		eval = (display == 0);
		% disp(eval);
		if sum(eval(:)) == sum(board(:))
			win = 1;
		end
	end

	% disp(board);

	if lose
		disp('Sorry, you lose!');
	else
		disp('Congratulations, you win!');
	end
	
end