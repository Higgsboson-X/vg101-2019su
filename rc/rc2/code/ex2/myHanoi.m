function myHanoi(n)

	fid = fopen('hanoiOut.txt', 'w');
	myHanoiHelper(n, 'A', 'C', 'B', 1, fid);
	fclose(fid);
	
end