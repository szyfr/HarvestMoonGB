
SECTION "3036", ROM0[$3036]


;;= FUN_3036
;;=  
;;=  Input: C - bank, D - , E - , HL - 
FUN_3036:
	; Preserve ROM bank
	ld  a,[$4000]
	push af

	; Sets ROM bank to input C
	ld  a,c
	ld  [rROMB01],a

	; Sets HRAM $B9 to D
	ld  a,d
	ldh [$B9],a

	; Sets HRAM $B8 to E
	ld  a,e
	ldh [$B8],a

	; Sets HRAM $BA to [HL] then incs
	ld  a,[hl+]
	ldh [$BA],a

	; Sets HRAM $BC to [HL] + E
	add e
	ldh [$BC],a

	; Sets HRAM $BB to [HL] then incs
	ld  a,[hl+]
	ldh [$BB],a

	; Sets HRAM $BD to [HL] + d with carry
	adc d
	ldh [$BD],a

	ld  c,$00
.loop:
	; if C != 0, jump
	ld  a,c
	and a
	jr  nz,.LAB_305A

	ld  a,[hl+]
	ld  b,a

	ld  c,$08
.LAB_305A:
	; BC = (b >> 1) + (c - 1), then jump if (b >> 1) carried
	dec c
	srl b
	push bc
	jr  nc,.LAB_3065

	; Save [hl] into [de], inc both then jump to bottom
	ld  a,[hl+]
	ld  [de],a
	inc de
	jr  .LAB_30BA

.LAB_3065:
	; Load value from [hl], copy it and & $F0. Then add 3 to original and save [$BE]
	ld  a,[hl+]
	ld  c,a
	and $0F
	inc a
	inc a
	inc a
	ldh [$BE],a

	; Load value from [hl] and move the lower 4-bits into the upper 4 of c
	ld  a,[hl+]
	ld  b,a
	push hl
	srl b
	rr  c
	srl b
	rr  c
	srl b
	rr  c
	srl b
	rr  c

	; Subtract c from e, replace c
	ld  a,e
	sub c
	ld  c,a

	; Subtract with carry b from d, replace b
	ld  a,d
	sbc b
	ld  b,a

	; Load input D, if carry jump, then if != 0 jump.
	ldh a,[$B9]
	cp  b
	jr  c,.LAB_30AE
	jr  nz,.LAB_3095

	; Load input E, if carry jump, then if == 0 jump to same.
	ldh a,[$B8]
	cp  c
	jr  c,.LAB_30AE
	jr  z,.LAB_30AE

.LAB_3095:
	; Invert c, increment, replace b
	ld  a,c
	xor $FF
	inc a
	ld  b,a

	; Load [$BE], replace c and clear a
	ldh a,[$BE]
	ld  c,a
	xor a

.LAB_309E:
	; Save a into [de+]
	ld  [de],a
	inc de

	; If c == 0, jump
	dec c
	jr  z,.LAB_30B9

	; If b != 0, jump
	dec b
	jr  nz,.LAB_309E

	; Copy input de into hl
	ld  hl,$FFB8
	ld  a,[hl+]
	ld  h,[hl]
	ld  l,a

	; Jump
	jr  .LAB_30B3

.LAB_30AE:
	; Replace hl with bc
	ld  h,b
	ld  l,c

	; Replace c with [$BE]
	ldh a,[$BE]
	ld  c,a

.LAB_30B3:
	; Copy [hl] to [de], inc both
	ld  a,[hl+]
	ld  [de],a
	inc de

	; If c != 0, jump
	dec c
	jr  nz,.LAB_30B3

.LAB_30B9:
	pop hl

.LAB_30BA
	; Compare d with [$BD], If carry, restart loop. Then if != 0, leave.
	ldh a,[$BD]
	ld  b,a
	ld  a,d
	cp  b
	jr  c,.restartloop
	jr  nz,.leave

	; Compare e with [$BC], If no carry, leave.
	ldh a,[$BC]
	ld  c,a
	ld  a,e
	cp  c
	jr  nc,.leave

.restartloop:
	pop bc
	jr  .loop

.leave:
	pop bc
	pop af
	ld  [rROMB01],a

	ret