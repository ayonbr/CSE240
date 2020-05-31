foo(X,Y,Z):-
	Y=<0, Z is X, !.
	
foo(X,Y,Z):-
	X=<0, Z is Y, !.

foo(X,Y,Z):-
	(X>Y;X =:= Y),
	F1 is X-1,
	F2 is Y-2,
	foo(F1, Y, Z2),
	Z is X + Z2.
	
foo(X,Y,Z):-
	X<Y,
	F1 is X-2,
	F2 is Y-3,
	foo(F1,F2,Z2),
	Z is Y + Z2.