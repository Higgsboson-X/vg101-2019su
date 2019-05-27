clearvars;
% pass a function as an argument;
a = [2, 3, 1, 2, 4, 5, 8, 9, 2];
lessFunc = @myLess;
sorted = mySort(a, lessFunc);

disp(sorted);

% access a local function;
hd = mainFuncTools;

s = hd.mySum(1, 2);
m = hd.myMul(1, 2);
d = hd.myDiv(1, 2);

disp(s);
disp(m);
disp(d);
