
SECTION "206C", ROM0[$206C]


;;= FUN_206C (jump_offset)?
;;=  Copies ptr at baseptr+(offset*2) and jumps to it.
;;=  Input: A - offset, stack+0x8 - baseptr
FUN_206C:
	; Double input a
	ld  l,a
	ld  h,0
	add hl,hl

	; Copy result into de and pop into hl, then add
	ld  e,l
	ld  d,h
	pop hl
	add hl,de

	; Jump to ptr at hl
	ld  a,[hl+]
	ld  h,[hl]
	ld  l,a
	jp  hl