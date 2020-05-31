/* Database for family tree. It consists of facts and rules. */
/* A portion of the family tree has been implemented for you */

/* Facts */
male(kam).
male(rob).
male(dom).
male(dag).
male(tio).
male(jeb).
male(zev).
male(gio).

female(ana).
female(syd).
female(sue).
female(kat).
female(may).
female(pam).
female(fey).
female(liz).

father_of(kam, rob).  /* kam is the father of rob */
father_of(kam, syd). /* kam is the father of syd */
father_of(jeb, tio).
father_of(jeb, pam).
father_of(rob, kat).
father_of(rob, dom).
father_of(tio, dag).
father_of(tio, fey).
father_of(zev, liv).
father_of(zev, gio).


mother_of(ana, rob). /* ana is the mother of rob */
mother_of(ana, syd). /* ana is the mother of syd */
mother_of(may,tio).
mother_of(may,pam).
mother_of(sue,kat).
mother_of(sue,dom).
mother_of(syd,dag).
mother_of(syd,fey).
mother_of(pam,liz).
mother_of(pam,gio).

/* Rules */
is_male(X) :-
	male(X);
	father_of(X, _).
	
/* Question 2.1 */
is_male(X) :-
	male(X);
	father_of(X, _).

/* Question 2.2 */	
is_female(X) :-
		female(X);
		mother_of(X, _).
		
/* Question 2.3 */
parent_of(X,Y) :-
	father_of(X,Y);
	mother_of(X,Y).
	
/* Question 2.4 */
sibling_of(X,Y) :-
	parent_of(Z,X), parent_of(Z,Y).
	not(X=Y).
	
/* Question 2.5 */
grandmother_of(X, Z) :-
	female(X), parent_of(X,Y),parent_of(Y,Z).
	
grandfather_of(X,Z) :-
	male(X), parent_of(X,Y), parent_of(Y,Z).

/* Question 2.6 */
desendent_of(X,Y) :-
	parent_of(Y,X).
desecendent_of(X,Y) :-
		parent_of(Z,X), descendent_of(Z,Y).
	