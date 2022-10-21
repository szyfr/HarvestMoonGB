
SECTION "77A7", ROMX[$77A7], BANK[7]


;;= FUN_77A7()
;;=  
;;=  
FUN_BANK7_77A7:
	di

	; Sets variables to $FF
	ld  a,$FF
	ld  [wunk_6],a
	ld  [wunk_8],a

	; Clears hardware variables
	xor a
	ldh [rBGP],a
	ldh [rOBP0],a
	ldh [rOBP1],a

	; FUN_22E8($7806)
	ld  hl,$7806
	call FUN_22E8
	call wait_7000

	; FUN_22E8($7975)
	ld  hl,$7975
	call FUN_22E8
	call wait_7000

	; Call FUN_22E8 8 times, incrementing hl by $10 each time
	ld  hl,$79D5
	ld  b,$08
.loop:
	push hl
	push bc
	call FUN_22E8
	call wait_7000
	pop bc
	pop hl

	ld  de,$0010
	add hl,de
	dec b
	jr  nz,.loop

	; FUN_23E9(19, $7D8A, $7955)
	ld  hl,$7D8A
	ld  a,$13
	ld  de,$7955
	call FUN_23E9

	; FUN_23E9(16, $797F, $7965)
	ld  hl,$797F
	ld  a,$10
	ld  de,$7965
	call FUN_23E9

	; Clears pallettes
	xor a
	ldh [rBGP],a
	ldh [rOBP0],a
	ldh [rOBP1],a

	; FUN_22E8($7995)
	ld  hl,$7995
	call FUN_22E8
	call wait_7000

	ret