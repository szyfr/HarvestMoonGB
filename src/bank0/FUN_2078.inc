
SECTION "2078", ROM0[$2078]


;;= FUN_2078 (???)
;;=  Adds A*3 to return value, loads hl and a from that location, then jumps to hl.
;;=  Input: A - offset, stack+0x8 - return
FUN_2078:
	; hl = a*3
	ld  e,a
	ld  d,0
	ld  l,a
	ld  h,0
	add hl,hl
	add hl,de

	; de = hl then pop into hl
	ld  e,l
	ld  d,h
	pop hl

	; de + hl
	add hl,de

	; Load hl and a from [hl]
	ld  e,[hl]
	inc hl
	ld  d,[hl]
	inc hl
	ld  a,[hl]
	ld  l,e
	ld  h,d
