f = @(x) (x < 0) .* x + (x >= 0) .* (x.^2);
a = linspace(-1, 1, 50);
plot(a, f(a));
