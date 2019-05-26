% demo recursion: merge sort;
clearvars;

% base case;
A = mergeSort([]);
disp(A);
A = mergeSort(2);
disp(A);

% simple test cases;
A = mergeSort([2, 1, 2, 3, 2, 7, 5, 8, 3]);
disp(A);
A = mergeSort([1, 1, 1, 1, 1]);
disp(A);