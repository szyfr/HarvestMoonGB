
SECTION "23E9", ROM0[$23E9]


;;= FUN_23E9
;;=  
;;=  Input: HL - FUN_3036?, A - FUN_3036?, DE - wait
FUN_23E9:
	push de
	push af

	; Preserve hl calling lcd_disable
	push hl
	call lcd_disable
	pop hl

	; Set bg palette
	ld  a,$E4
	ldh [rBGP],a

	; Call FUN_3036
	pop af
	ld  c,a
	ld  de,$8800
	call FUN_3036 ; TODO

	; Clear scrolling
	xor a
	ldh [rSCY],a
	ldh [rSCX],a

	; Prepare loop
	ld  hl,$9800
	ld  de,$000C
	ld  a,$80
	ld  c,$0D
.outerloop:
	ld  b,20
.innerloop:
	; Load A into ptr HL 20 times
	ld  [hl+],a
	inc a
	dec b
	jr  nz,.innerloop

	; Then increment HL by 12 and repeat 13 times
	add hl,de
	dec c
	jr  nz,.outerloop


	ld  a,LCDCF_ON | LCDCF_BGON
	ldh [rLCDC],a

	; Wait
	call wait_7000

	; Call FUN_22E8
	pop hl
	call FUN_22E8
	call wait_7000

	ret