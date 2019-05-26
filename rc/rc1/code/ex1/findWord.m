function findWord(fileIn, fileOut)

	fid = fopen(fileIn, 'r');
	dim = fscanf(fid, '%d %d');

	board = zeros(dim(1), dim(2));

	for i = 1:dim(1)
		line = fgetl(fid);
		for j = 1:dim(2)
			board(i, j) = line(2 * j - 1);
		end
	end

	numWords = fscanf(fid, '%d');
	words = cell(1, numWords);
	for i = 1:numWords
		words{i} = fgetl(fid);
	end

	results = cell(1, numWords);
	found = zeros(1, numWords);

	for i = 1:dim(1)
		for j = 1:dim(2)
			for k = 1:numWords
				[res, dir] = evalBoard(board, words{k}, i, j);
				if found(k) == 0 && res
					results{k} = {i, j, dir{1}};
					found(k) = 1;
				end
			end
		end
	end

	fclose(fid);
	fid = fopen(fileOut, 'w');

	for ind = 1:numWords
		result = results{ind};
		% disp(result);
		fprintf(fid, '%s is located at (%d, %d) in the %s direction\n', ...
			words{ind}, result{1}, result{2}, result{3});
	end

	fclose(fid);
	
end
