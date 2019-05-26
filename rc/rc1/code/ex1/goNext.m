function [nextR, nextC] = goNext(curR, curC, dir)

	nextR = curR;
	nextC = curC;

	parsed = split(dir);

	for ind = 1:length(parsed)
		dir = parsed{ind};
		if strcmp(dir, 'up')
			nextR = nextR - 1;
		elseif strcmp(dir, 'down')
			nextR = nextR + 1;
		elseif strcmp(dir, 'left')
			nextC = nextC - 1;
		elseif strcmp(dir, 'right')
			nextC = nextC + 1;
		end
	end
	
end