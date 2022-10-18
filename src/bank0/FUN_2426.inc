
SECTION "2426", ROM0[$2426]


;;= FUN_2426()
;;=
;;=  Seemingly initializes audio.
FUN_2426:
	; FUN_2468(0,0)
	ld  bc,0
	call FUN_2468

	; Initialize audio
	ld  a,AUDENA_ON
	ldh [rNR52],a
	xor a
	ldh [rNR51],a
	ld  [wunk_4],a
	ld  a,AUDVOL_MAX_LEFT | AUDVOL_MAX_RIGHT
	ldh [rNR50],a

	; Set variables
	ld  hl,wunkarr_1
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
	ld  [wunk_5],a

	ret