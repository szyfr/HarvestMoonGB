
SECTION "232F", ROM0[$232F]


;;= FUN_232F
;;=  
;;=  Input: 
FUN_232F:
	; Call FUN_22E8 using $89 and $01
	ld  hl,$23A0
	call FUN_22E8 ; TODO

	; Call wait_7000
	call wait_7000

	; If B & A are pressed, last call
	; Since no value is written, i don't know what it'll get.
	ldh a,[rP1]
	and 3
	cp  3
	jr  nz,.LAB_2385

	; Read direction input
	ld  a,P1F_GET_DPAD
	ldh [rP1],a
	ldh a,[rP1]
	ldh a,[rP1]

	; Call wait_7000
	call wait_7000

	; Write no input
	ld  a,P1F_GET_NONE
	ldh [rP1],a

	; Call wait_7000
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

	; Call wait_7000
	call wait_7000

	ld  a,P1F_GET_NONE
	ldh [rP1],a
	ldh a,[rP1]
	ldh a,[rP1]
	ldh a,[rP1]

	; Call wait_7000
	call wait_7000
	
	; If B & A are pressed, last call
	; Don't know if anything's been written since P1F_GET_NONE. maybe?
	ldh a,[rP1]
	and 3
	cp  3
	jr  nz,.LAB_2385

	; Call FUN_22E8 using $89 and $00
	ld  hl,$2390
	call FUN_22E8 ; TODO

	; Call wait_7000
	call wait_7000

	; potential 0 carry return?
	sub a
	ret

.LAB_2385:
	; Call FUN_22E8 using $89 and $00
	ld  hl,$2390
	call FUN_22E8 ; TODO

	; Call wait_7000
	call wait_7000

	; Carry = 1
	scf
	ret