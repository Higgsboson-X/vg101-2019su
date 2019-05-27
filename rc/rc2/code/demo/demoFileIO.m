clearvars;
% demo file IO;
fid = fopen('fileIn.txt', 'r');

integers = fscanf(fid, '%d %d\n', 2);
disp(integers);

line = fgetl(fid);
disp(line);

% note special characters;
chars = split(fgetl(fid), '');
disp(chars);

sent = split(fgetl(fid));
disp(sent);

% read from start;
frewind(fid);
line = fgetl(fid);
disp(line);
