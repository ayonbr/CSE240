
qsort2([],[]):-
	!.

qsort2([Pivot|Tail], Sorted):-
	split(Pivot, Tail, L1, L2),
	qsort2(L1, Sorted1),
	qsort2(L2, Sorted2),
	append(Sorted1, [Pivot|Sorted2], Sorted).
	
	
split(_, [],[],[]).
split(Pivot, [X|T], [X|Le], Gt):-
	X=<Pivot, split(Pivot, T, Le, Gt).

split(Pivot, [X|T], Le, [X|Gt]):-
	X> Pivot, split(Pivot, T, Le, Gt).
	

	