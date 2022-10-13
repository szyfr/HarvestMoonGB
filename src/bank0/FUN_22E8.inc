
SECTION "22E8", ROM0[$22E8]


;;= FUN_22E8
;;=  
;;=  Input: HL - ???
FUN_22E8:
	; Loads value from hl and if [hl] & 7 == 0, return
	ld  a,[hl]
	and 7
	ret z

	; Copies [hl] to b and set c to rP1
	ld  b,a
	ld  c,0

.loop:
	push bc

	; Write 0, then None, then Buttons to rP1
	ld  a,$00
	ldh [c],a
	ld  a,P1F_GET_NONE
	ldh [c],a
	ld  b,P1F_GET_BTN

.LAB_22F8:
	; Load [hl] into $XX08, inc hl
	ld  e,8
	ld  a,[hl+]
	ld  d,a

.LAB_22FC:
	; If bit 0 of d is zero, load P1F_GET_DPAD into a
	bit 0,d
	ld  a,P1F_GET_BTN
	jr  nz,.LAB_2304
	
	ld  a,P1F_GET_DPAD
.LAB_2304:
	; Set rP1 to BTN/DPAD then NONE
	ldh [c],a
	ld  a,P1F_GET_NONE
	ldh [c],a

	; Rotate d right and dec e. If e != 0, jump back up
	rr  d
	dec e
	jr  nz,.LAB_22FC

	; Dec b and if != 0, jump farther up
	dec b
	jr  nz,.LAB_22F8

	; Write DPAD then NONE to rP1
	ld  a,P1F_GET_DPAD
	ldh [c],a
	ld  a,P1F_GET_NONE
	ldh [c],a

	; Restore bc and dec b. If b == 0, return. 
	pop bc
	dec b
	ret z

	; Call wait_7000
	call wait_7000

	; Loop back
	jr  .loop