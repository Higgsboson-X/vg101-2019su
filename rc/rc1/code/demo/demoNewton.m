f = @(x) x^5 - 11 * x^4 + 46 * x^3 - 90 * x^2 + 81 * x - 27;
root = newtonsMethod(f, 0.0000001);
disp(root);
