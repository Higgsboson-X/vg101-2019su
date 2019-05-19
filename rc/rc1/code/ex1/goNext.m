function [nextR, nextC] = goNext(curR, curC, dir)

nextR = curR;
nextC = curC;

parsed = split(dir);

shape = size(parsed);

for ind = 1:shape(1)
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