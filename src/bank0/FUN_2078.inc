
SECTION "2078", ROM0[$2078]


;;= jumptable_bank_call(A:offset, S+8:return)
;;=  
;;=  Adds A*3 to return value, loads hl and a from that location, then jumps to hl.
jumptable_bank_call:
	; Loads offset into HL
	; Then "multiplies" it by 3
	ld  e,a
	ld  d,0
	ld  l,a
	ld  h,0
	add hl,hl
	add hl,de

	; Copies HL into DE
	ld  e,l
	ld  d,h

	; Pops return address off stack mand applies offset
	pop hl
	add hl,de

	; Loads DE and A from ptr, then copies ptr to DE
	ld  e,[hl]
	inc hl
	ld  d,[hl]
	inc hl
	ld  a,[hl]
	ld  l,e
	ld  h,d

	; Fall into bank_call([return+offset + 2], [return+offset])