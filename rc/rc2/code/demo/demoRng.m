% demo rng;
clearvars;

% generate current random state from rng;
rng(2);
% store the random state;
s = rng;

% generate pseudorandom numbers;
r = rand();
disp(r);
r = randi([1, 5]);
disp(r);
r = randn();
disp(r);

% restore the random state;
rng(s);
% reproduce random numbers;
r = rand();
disp(r);
r = randi([1, 5]);
disp(r);
r = randn();
disp(r);

A = zeros(7);
B = zeros(7);
% effects on `randperm`;
rng(s);
for i = 1:7
	r = randperm(7);
	A(i, :) = r;
	disp(r);
end
rng(s);
for i = 1:7
	r = randperm(7);
	B(i, :) = r;
	disp(r);
end

disp(A == B);