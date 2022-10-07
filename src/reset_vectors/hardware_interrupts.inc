
section "hardware_interrupts", rom0[$0040]


;;= VBlank
;;= 
intr_vblank:
	call FUN_02E4
	reti
;; Padding
db $ff,$ff,$ff,$ff


;;= Stat
;;= 
intr_stat:
	jp LAB_3317
;; Padding
db $ff,$ff,$ff,$ff,$ff


;;= Timer
;;= 
intr_timer:
	jp LAB_33FF
;; Padding
db $ff,$ff,$ff,$ff,$ff


;;= Serial
;;= 
intr_serial:
	jp LAB_340E
;; Padding
db $ff,$ff,$ff,$ff,$ff


;;= Joypad
;;= 
intr_joypad:
	reti