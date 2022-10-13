
SECTION "2166", ROM0[$2166]


;;= lcd_disable
;;=  Disables LCD
lcd_disable:
	; Test if LCD is on, return if false
	ld  hl,rLCDC
	bit 7,[hl]
	ret z

	; Disable vblank interrupt and save old value
	ldh a,[rIE]
	push af
	res 0,a
	ldh [rIE],a

.wait:
	; Wait until vblank
	ldh a,[rLY]
	cp 145
	jr  nz,.wait

	; Turn off LCD and replace original IE
	res 7,[hl]
	pop af
	ldh [rIE],a
	ret