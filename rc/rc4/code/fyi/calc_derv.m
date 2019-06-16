T95SQ = [2.48, 1.59, 1.204, 1.05, 0.926, 0.834, 0.770, 0.715, 0.553, 0.467, 0.139];

fid = fopen('./files/$1', 'r');
res = fscanf(fid, '%d %d');
n = res(1);
d = res(2);
name = fgetl(fid);
unit = fgetl(fid);
func = fgetl(fid);
func(1) = '@';
F = str2func(func);
means = zeros(1, n);
u = zeros(1, n);
df = zeros(1, n);
dlnf = zeros(1, n);
for i = 1:n
	buf = fgetl(fid);
	if ~strcmp(buf, '=======')
		disp('error.');
	end
	res = fscanf(fid, '%d %d');
	data_num = res(1);
	digits = res(2);
	data = fscanf(fid, '%f');
	deltaB = data(end);
	data = data(1:end - 1);
	means(i) = round_digits(mean(data), digits);
	sx = round_digits(sqrt(sum((data - means(i)).^2) / (n - 1)), digits);
	if n <= 10
		t95sq = T95SQ(n - 2);
	else
		t96sq = T95SQ(min(9 + floor(max(0, n - 15) / 5), 11));
	end
	deltaA = round_digits(sx * t95sq, digits);
	u(i) = round_digits(sqrt(deltaA^2 + deltaB^2), digits);
	name = fgetl(fid);
	unit = fgetl(fid);
	res = strcat('syms', )
end
% unfinished!!!!!
val = 

fclose(fid);
