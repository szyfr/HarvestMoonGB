
SECTION "5404", ROMX[$5404], BANK[9]


;;= FUN_BANK9_5404(HL:??)
;;=  
;;=  
FUN_BANK9_5404:
	push hl

	call FUN_2196
	call FUN_21A5
	call FUN_3243

	ld  hl,$57A0
	ld  c,$1C
	ld  de,$8800
	call FUN_3036

	ld  hl,$52E9
	ld  c,$1C
	ld  de,$9000
	call FUN_3036

	pop hl

	ld  e,[hl]
	inc hl
	ld  d,[hl]
	inc hl
	ld  c,[hl]
	inc hl

	push hl

	ld  h,d
	ld  l,e
	ld  de,$9500
	call FUN_3036

	pop hl

	ld  e,[hl]
	inc hl
	ld  d,[hl]
	inc hl
	ld  c,[hl]
	inc hl

	push hl

	ld  h,d
	ld  l,e
	ld  de,$8A00
	call FUN_3036

	pop hl

	ld  e,[hl]
	inc hl
	ld  d,[hl]
	inc hl
	ld  c,[hl]
	inc hl

	push hl

	ld  h,d
	ld  l,e
	ld  de,$9800
	call FUN_3036

	ld  hl,$99A0
	ld  de,$9c00
	ld  b,$C0
	call FUN_2204

	ld  hl,$9C22
	call FUN_BANK9_555B

	ld  hl,$9C62
	call FUN_BANK9_555B

	ld  hl,$9C22
	ld  a,$F2
	ld  [hl+],a
	ld  a,$F3
	ld  [hl+],a
	ld  a,$F4
	ld  [hl+],a
	ld  a,$F5
	ld  [hl+],a
	ld  a,$F6
	ld  [hl+],a
	ld  a,$F4
	ld  [hl+],a
	ld  a,$F7
	inc hl
	ld  [hl+],a
	ld  a,$F8
	ld  [hl+],a
	ld  a,$F9
	ld  [hl+],a
	ld  a,$FA
	ld  [hl+],a
	ld  a,$F6
	ld  [hl],a

	ld  hl,$9C71
	ld  a,$FB
	ld  [hl],a

	ld  hl,$40B1
	ld  de,$8F20
	call FUN_BANK9_5552

	ld  hl,$41A1
	ld  de,$8F30
	call FUN_BANK9_5552

	ld  hl,$42D1
	ld  de,$8F40
	call FUN_BANK9_5552

	ld  hl,$41A1
	ld  de,$8F50
	call FUN_BANK9_5552

	ld  hl,$42C1
	ld  de,$8F60
	call FUN_BANK9_5552

	ld  hl,$4051
	ld  de,$8F70
	call FUN_BANK9_5552

	ld  hl,$42E1
	ld  de,$8F80
	call FUN_BANK9_5552

	ld  hl,$4271
	ld  de,$8F90
	call FUN_BANK9_5552

	ld  hl,$41D1
	ld  de,$8FA0
	call FUN_BANK9_5552

	ld  hl,$4061
	ld  de,$8FB0
	call FUN_BANK9_5552

	pop hl

	ld  a,[hl+]
	ld  h,[hl]
	ld  l,a
	ld  a,l
	ld  [$CD28],a
	ld  a,h
	ld  [$CD29],a
	xor a
	ld  [$CD30],a
	ld  [$CD31],a
	ld  [$CD32],a
	ld  [$CD33],a
	ld  [$CD5C],a
	ld  a,$4C
	ld  [$CD9A],a
	ld  a,$9F
	ld  [$CD9B],a
	xor a
	ldh [$93],a
	ldh [$91],a
	ld  a,$07
	ldh [$96],a
	ld  a,$68
	ldh [$95],a

	xor a

	ld  hl,$CB14
	ld  [hl+],a
	ld  [hl+],a
	ld  [hl],a
	dec a
	ld  [$CB1C],a
	ld  a,$1D
	ld  [$CB4E],a

	ld  hl,$C000
	ld  bc,$00A0
	call clear_memory

	ld  a,$54
	call FUN_24C4

	ld  a,$C3
	ld  [$C0A2],a
	ld  a,0
	ldh [rSTAT],a
	xor a
	ldh [rIF],a
	ld  a,$03
	ldh [rIE],a

	ret