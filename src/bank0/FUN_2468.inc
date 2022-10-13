
SECTION "2468", ROM0[$2468]


;;= FUN_2468
;;=  Sets two variables to input values and zeros a third.
;;=  Input: BC - values
FUN_2468:
	ld  a,b
	ld  [$D3A0],a ; TODO
	ld  a,c
	ld  [$D3A1],a ; TODO
	xor a
	ld  [$D3A2],a ; TODO
	ret