
SECTION "2426", ROM0[$2426]


;;= FUN_2426
;;=  Seemingly initializes audio.
;;=  Input: 
FUN_2426:
	; Call FUN_2468
	ld  bc,0
	call FUN_2468

	; Initialize audio?
	ld  a,$80
	ldh [rNR52],a
	xor a
	ldh [rNR51],a
	ld  [$D397],a ; TODO
	ld  a,$77
	ldh [rNR50],a

	; Init loop
	ld  hl,$D300
	ld  b,6
	ld  a,$FF
.loop:
	ld  [hl],a
	ld  de,$0017
	add hl,de
	ld  [hl],a
	ld  de,$0002
	add hl,de
	dec b
	jr  nz,.loop

	; Clear variable
	xor a
	ld  [$D3A3],a ; TODO

	ret