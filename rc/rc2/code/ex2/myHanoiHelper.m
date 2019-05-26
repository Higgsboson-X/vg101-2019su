function nStep = myHanoiHelper(n, rodFrom, rodTo, rodHelp, step, fid)

	if n == 1
		fprintf(fid, 'Step %d: move disk 1 from rod %s to rod %s.\n', ...
			step, rodFrom, rodTo);
		nStep = step + 1;
	else
		nStep = myHanoiHelper(n - 1, rodFrom, rodHelp, rodTo, step, fid);
		fprintf(fid, 'Step %d: move disk %d from rod %s to rod %s.\n', ...
			nStep, n, rodFrom, rodTo);
		nStep = myHanoiHelper(n - 1, rodHelp, rodTo, rodFrom, nStep + 1, fid);
	end
	
end