
SECTION "7816", ROMX[$7816], BANK[7]


;;= FUN_7816
;;=  
;;=  Input: 
FUN_7816:
	; If [$DD00] == 0, return
	ld  a,[$DD00]
	or  a
	ret z

	; FUN_22E8($7975)
	ld  hl,$7975
	call FUN_22E8
	call wait_7000

	; Clear Palettes
	xor a
	ldh [rBGP],a
	ldh [rOBP0],a
	ldh [rOBP1],a

	; clear_memory($9000, 16)
	ld  hl,$9000
	ld  bc,$0010
	call clear_memory

	; clear_memory($9800, 1024)
	ld  hl,$9800
	ld  bc,$0400
	call clear_memory

	ld  hl,$7A55

	; If [$C0A7] != 1 || [$C0A7] != 7 || [$C0A7] != 15, skip
	; These might be flags. 1 = %1, 7 = %111, 15 = %1111, and 37 = %100101
	ld  a,[$C0A7]
	cp  1
	jr  z,.LAB_7853
	cp  7
	jr  z,.LAB_7853
	cp  15
	jr  z,.LAB_7853

	; If [$C0A7] != 37, jump
	cp  37
	jr  nz,.LAB_7859

.LAB_7853:
	ld  hl,$7B51
	ld  a,[$B884]

.LAB_7859:
	; Replace BC with hl
	ld  c,l
	ld  b,h
	; Replace HL with $0000 + A
	ld  l,a
	ld  h,0
	; HL * 2, then replace DE
	add hl,hl
	ld  d,h
	ld  e,l
	; (HL * 2) + DE + BC
	add hl,hl
	add hl,de
	add hl,bc

	; These two loops copy data from [$7B51] interspersed with 0 to create an input array for FUN_22E8
	ld  de,$C0AA
	ld  a,$51
	ld  [de],a
	inc de

	ld  b,4
.loop1:
	ld  a,[hl+]
	ld  [de],a
	inc de

	xor a
	ld  [de],a
	inc de

	dec b
	jr  nz,.loop1

	ld  a,[hl+]
	set 7,a
	ld  [de],a
	inc de

	ld  b,6
	xor a
.loop2:
	ld  [de],a
	inc de
	dec b
	jr  nz,.loop2

	; FUN_22E8($C0AA) (The created array)
	push hl
	ld  hl,$C0AA
	call FUN_22E8
	call wait_7000
	pop hl

	; If [$C0A7] == $20 || [$CB50] == $20, jump
	ld  a,[$C0A7]
	cp  $20
	jr  z,.LAB_7911
	ld  a,[$CB50]
	cp  $20
	jr  z,.LAB_7911

	; If [$DD01] == [hl], jump
	ld  b,[hl]
	ld  a,[$DD01]
	cp  b
	jp  z,.LAB_7948

	; Save b into [$DD01]
	ld  a,b
	ld  [$DD01],a

	push af
	push bc

	; Clear Palettes
	xor a
	ldh [rBGP],a
	ldh [rOBP0],a
	ldh [rOBP1],a

	; clear_memory($9000, 16)
	ld  hl,$9000
	ld  bc,$0010
	call clear_memory

	; clear_memory($9800, 1024) + [$C0A2] = $83
	ld  hl,$9800
	ld  bc,$0400
	ld  a,$83
	ld  [$C0A2],a
	call clear_memory

	; FUN_217F()
	call FUN_217F
	call wait_7000
	; lcd_disable()
	call lcd_disable

	; FUN_22E8($7975)
	ld  hl,$7975
	call FUN_22E8
	call wait_7000

	pop bc
	pop af

	; a = (a * 2) + b
	add a
	add b

	; TODO FUN_07A9($7B69)
	ld  hl,$7B69
	call FUN_07A9

	; FUN_23E9(a, $79A5)
	ld  de,$79A5
	call FUN_23E9

	; a = ([$DD01] * 3) + 1
	ld  a,[$DD01]
	ld  b,a
	add a
	add b
	inc a

	; TODO FUN_07A9($7B69)
	ld  hl,$7B69
	call FUN_07A9

	; FUN_23E9(a, $79B5)
	ld  de,$79B5
	call FUN_23E9

	; a = ([$DD01] * 3) + 1
	ld  a,[$DD01]
	ld  b,a
	add a
	add b
	inc a
	inc a

	; TODO FUN_07A9($7B69)
	ld  hl,$7B69
	call FUN_07A9

	; FUN_23E9(a, $79C5)
	ld  de,$79C5
	call FUN_23E9

.LAB_7911:
	; lcd_disable()
	call lcd_disable

	; clear_memory($9000, 16)
	ld  hl,$9000
	ld  bc,$0010
	call clear_memory

	; clear_memory($9800, 1024)
	ld  hl,$9800
	ld  bc,$0400
	call clear_memory

	; Clear Palettes
	xor a
	ldh [rBGP],a
	ldh [rOBP0],a
	ldh [rOBP1],a

	; FUN_217F()
	call FUN_217F
	call wait_7000

	; lcd_disable()
	call lcd_disable

	; FUN_22E8($7995)
	ld  hl,$7995
	call FUN_22E8
	call wait_7000

	; FUN_22E8($7975)
	ld  hl,$7975
	call FUN_22E8
	call wait_7000

.LAB_7948:
	ret