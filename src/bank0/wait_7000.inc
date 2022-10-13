
SECTION "2323", ROM0[$2323]


;;= wait_7000
;;=  Loop 7000 times, 40 cycles each, for 280,000 cycles or about .07 seconds.
;;=  Input: HL - ???
wait_7000:
	ld  de,$1B58
.loop:
	; Run 40 cycles, loop
	nop
	nop
	nop
	dec de
	ld  a,d
	or  e
	jr  nz,.loop

	ret