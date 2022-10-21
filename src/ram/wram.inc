section "WRAM1", WRAM0


empty1_1 :: ds $00A7

; used in entry(=$20), FUN_0258
;
; Used as an offset for a banked jump table
;
; TODO: name
wunk_7   :: db


section "WRAM2", WRAMX


empty_1 :: ds $0397


; Used in FUN_2426
;
; TODO name and definition
DEF wunkarr_1 EQU $D300


; Used in FUN_2426
;
; TODO name
wunk_4  :: db


empty_2 :: ds $08


; Used in FUN_2468
;
; TODO name
wunk_1  :: db ; $D3A0
wunk_2  :: db ; $D3A1
wunk_3  :: db ; $D3A2


; Used in FUN_2426
;
; TODO name
wunk_5  :: db ; $D3A3


empty_3 :: ds $095C


; Used in entry
;
; TODO name
wunk_6  :: db ; $DD00
; Used in FUN_BANK7_77A7
;
; TODO name
wunk_8  :: db ; $DD01