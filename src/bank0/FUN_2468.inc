
SECTION "2468", ROM0[$2468]


;;= FUN_2468(B:val1, C:val2)
;;=
;;=  Sets two variables to input values and zeros a third.
FUN_2468:
	ld  a,b
	ld  [wunk_1],a
	ld  a,c
	ld  [wunk_2],a
	xor a
	ld  [wunk_3],a
	ret