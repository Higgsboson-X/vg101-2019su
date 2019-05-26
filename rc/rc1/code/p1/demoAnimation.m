clearvars;

fig = figure('Name', 'Animation', 'Resize', 'off');

for i = 0:100
	axis([0 100 0 100]);
	rectangle('Position', [i 50 6 3], 'FaceColor', 'y', 'EdgeColor', 'k');
	hold on;
	pause(0.1);
	clf;
end