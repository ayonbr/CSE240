%3.1
pizza(P,M,B,O,C):-
	member(P, [0,1,2,3,4,5,6,7,8,9]). % Pepperoni (9x5 = 45)
	member(M, [0,1,2,3,4]). % Meatball (10x4 = 40)
	member(B, [0,1,2,3,4,5,6]). % Basil (7x6 = 42)
	member(O, [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]). % Olives (3x15 = 45)
	member(C, [0,1,2,3,4,5]) % Chicken (8x5 = 40)
	
	Weight is P*5 + M*10 + B*7 + O*3 + C*8, Weight =:= 45. %sum of the weight and checks if it equals 45 ounces
	
	
%3.2 Write a rule called q2:- condition, to ask the following question (goal), so that type |?-q2. To test the question, |?-q2 pizza(1,2,2,2,2).

