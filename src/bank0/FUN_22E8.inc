
SECTION "22E8", ROM0[$22E8]


;;= FUN_22E8
;;=  This function seems to use the 16 bytes located at [hl] to do something.
;;=  I hate this thing. The developer responsible is insane. If someone can tell me what this is supposed to do, PLEASE.
;;=  It has to be some sort of wait function, because otherwise it does nothing BUT waste time.
;;=  IF it is a wait function, the range is roughly 10,152 cycles (.002 seconds) -> 74,315,160 cycles (17 seconds)\
;;=  Function (roughly): cy = (((592 + (10*NumOfOnesIn[hl+])) * 16) + 36) + 104 + (280000 * loops-1)
;;=  Input: HL - ptr
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

	; Useless?
	ld  a,$00 ;8
	ldh [c],a ;8
	ld  a,P1F_GET_NONE ;8
	ldh [c],a ;8

	ld  b,$10
.LAB_22F8:
	; Load [hl] into $XX08, inc hl
	ld  e,8
	ld  a,[hl+]
	ld  d,a

.LAB_22FC:
	; If bit 0 of d is zero, skip 8 cycles
	bit 0,d
	ld  a,P1F_GET_BTN ;8
	jr  nz,.LAB_2304
	
	ld  a,P1F_GET_DPAD ;8
.LAB_2304:
	; Useless?
	ldh [c],a ;8
	ld  a,P1F_GET_NONE ;8
	ldh [c],a ;8

	; Rotate d right and dec e. If e != 0, jump back up
	rr  d
	dec e
	jr  nz,.LAB_22FC

	; Dec b and if != 0, jump farther up
	dec b
	jr  nz,.LAB_22F8

	; Useless?
	ld  a,P1F_GET_DPAD ;8
	ldh [c],a ;8
	ld  a,P1F_GET_NONE ;8
	ldh [c],a ;8

	; Restore bc and dec b. If b == 0, return. 
	pop bc
	dec b
	ret z

	; Call wait_7000
	call wait_7000

	; Loop back
	jr  .loop


;FUN_22E8(HL) {
;	if (([hl] & 7) == 0) return
;
;	var1 = ([hl] << 8)
;	while(true) {
;		for(16) {
;			var2 = [hl+]
;			for(8) {
;				val2 = val2 >> 1
;			}
;		}
;		var1--
;		if(var1 == 0) return
;	}
;}