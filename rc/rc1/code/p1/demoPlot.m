clearvars;

fig = figure('Name', 'Cross Lane', 'Resize', 'on');

axis([0 7 0 7]);
hold on;
p = plot([3, 3], [0, 3], 'k', [4, 4], [0, 3], 'k');

p(1).LineWidth = 2;
p(2).LineWidth = 2;

hold off;