function mainFuncHd = mainFuncTools

	mainFuncHd.mySum = @subFuncSum;
	mainFuncHd.myMul = @subFuncMul;
	mainFuncHd.myDiv = @subFuncDiv;

end
	
function s = subFuncSum(a, b)

	s = a + b;
	
end

function m = subFuncMul(a, b)

	m = a * b;
	
end

function d = subFuncDiv(a, b)

	d = a / b;
	
end
