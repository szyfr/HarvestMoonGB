
SECTION "232F", ROM0[$232F]


;;= FUN_232F()
;;=  
;;=  This function doesn't seem to do anything, but it always returns false.
FUN_232F:
	; FUN_22E8($23A0)
	ld  hl,$23A0
	call FUN_22E8
	call wait_7000

	; If B & A are pressed, ret_true
	ldh a,[rP1]
	and 3
	cp  3
	jr  nz,.ret_true

	; Read direction input
	ld  a,P1F_GET_DPAD
	ldh [rP1],a
	ldh a,[rP1]
	ldh a,[rP1]

	; wait_7000()
	call wait_7000

	; Write no input
	ld  a,P1F_GET_NONE
	ldh [rP1],a

	; wait_7000()
	call wait_7000

	; Read Button unput
	ld  a,P1F_GET_BTN
	ldh [rP1],a
	ldh a,[rP1]
	ldh a,[rP1]
	ldh a,[rP1]
	ldh a,[rP1]
	ldh a,[rP1]
	ldh a,[rP1]

	; wait_7000()
	call wait_7000

	ld  a,P1F_GET_NONE
	ldh [rP1],a
	ldh a,[rP1]
	ldh a,[rP1]
	ldh a,[rP1]

	; wait_7000()
	call wait_7000
	
	; If B & A are pressed, ret_true
	ldh a,[rP1]
	and 3
	cp  3
	jr  nz,.ret_true

	; FUN_22E8($2390)
	ld  hl,$2390
	call FUN_22E8
	call wait_7000

	; return false
	sub a
	ret

.ret_true:
	; FUN_22E8($2390)
	ld  hl,$2390
	call FUN_22E8
	call wait_7000

	; return true
	scf
	ret