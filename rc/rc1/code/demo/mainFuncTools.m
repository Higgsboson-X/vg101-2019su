function mainFuncHd = mainFuncTools

	mainFuncHd.mySum = @subFuncSum;
	mainFuncHd.myMul = @subFuncMul;
	mainFuncHd.myDiv = @subFuncDiv;

function s = subFuncSum(a, b)

	s = a + b;

function m = subFuncMul(a, b)

	m = a * b;

function d = subFuncDiv(a, b)

	d = a / b;
