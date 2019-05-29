clearvars;
% demo sudoku solver using recursion;
fid = fopen('sudokuIn-3.txt', 'r');
board = fscanf(fid, '%d', 81);
board = reshape(board, 9, 9)';
fclose(fid);

sudokuSolver(board);
