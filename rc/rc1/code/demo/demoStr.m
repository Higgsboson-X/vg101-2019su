clearvars;

str = 'this is a string';
old = 'this';
new = 'that';

newStr = strrep(str, old, new);
disp(newStr);

index = strfind(newStr, 'is');
disp(index);
