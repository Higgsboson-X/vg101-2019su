syms f(x, y, z);
f(x, y, z) = eval('x^2 + y^2 + z^2');
syms dfx(x, y, z) dlnfx(x, y, z);
dfx(x, y, z) = diff(f, x);
dlnfx(x, y, z) = diff(log(f), x);

disp(double(dfx(1, 2, 3)));
disp(double(dlnfx(1, 2, 3)));
