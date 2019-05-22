function root = newtonsMethod(f, e)

	% input: a function handle with respect to x, accuracy e;
	% output: a root of f;

	xc = 0.;
	xn = xc;

	syms g(x);
	g(x) = f(x);
	df = diff(g, x);

	while ~isnan(xn) && abs(f(xc)) > e
		xc = xn;
		xn = double(xc - f(xc) / df(xc));
	end

	root = xc;
