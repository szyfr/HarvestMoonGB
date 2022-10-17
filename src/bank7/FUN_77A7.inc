
SECTION "77A7", ROMX[$77A7], BANK[7]


;;= FUN_77A7
;;=  
;;=  Input: 
FUN_77A7:
	di

	; Sets variables to $FF
	ld  a,$FF
	ld  [$DD00],a  ;TODO
	ld  [$DD01],a  ;TODO

	; Clears hardware variables
	xor a
	ldh [rBGP],a
	ldh [rOBP0],a
	ldh [rOBP1],a

	; Call FUN_22E8, then wait
	ld  hl,$7806
	call FUN_22E8
	call wait_7000

	; Call FUN_22E8, then wait
	ld  hl,$7975
	call FUN_22E8
	call wait_7000

	; Call FUN_22E8, then wait 8 times incrementing hl by 10 each time
	ld  hl,$79D5
	ld  b,$08
.LAB_77CE:
	push hl
	push bc
	call FUN_22E8
	call wait_7000
	pop bc
	pop hl

	ld  de,$0010
	add hl,de
	dec b
	jr  nz,.LAB_77CE

	; Call FUN_23E9
	ld  hl,$7D8A
	ld  a,$13
	ld  de,$7955
	call FUN_23E9

	; Call FUN_23E9
	ld  hl,$797F
	ld  a,$10
	ld  de,$7965
	call FUN_23E9

	; Clears hardware variables
	xor a
	ldh [rBGP],a
	ldh [rOBP0],a
	ldh [rOBP1],a

	; Call FUN_22E8, then wait
	ld  hl,$7995
	call FUN_22E8
	call wait_7000

	ret