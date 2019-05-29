syms x;
f = eval('x + 1');
disp(f);
whos f;
y = f;

syms f(x);
f(x) = eval('x + 1');
whos f;

disp(f(x));
disp(f(y));
disp(f(2));

syms g(x);
g(x) = f(y);
disp(g(x));
disp(g(2));

syms g(y);
g(y) = f(y);
disp(g(y));
disp(g(2));
