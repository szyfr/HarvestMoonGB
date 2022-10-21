
SECTION "208B", ROM0[$208B]


;;= bank_call(A:bank, HL:target)
;;=  
;;=  Loads input ROM bank and calls jump_hl
bank_call:
	push bc

	; Save a in b, then save SRAM bank in c
	ld  b,a
	ld  a,[rRAMB]
	ld  c,a

	; Set ROM bank to input a
	ld  a,b
	ld  [rROMB01],a

	; Grab SRAM bank
	ld  a,c

	pop bc

	; Call jump_hl
	push af
	call jump_hl
	pop af

	; Reset SRAM bank
	ld  [rROMB01],a

	ret