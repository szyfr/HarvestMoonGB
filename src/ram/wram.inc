section "WRAM1", WRAM0


empty1_1 :: ds $00A2


; Set in FUN_BANK7_7816(=%10000011)
;
; Used in FUN_217F
;
; TODO: name (Probably LCDCValue)
wunk_11  :: db ; C0A2


empty1_2 :: ds $0003


; Set in entry(=$00)
;
; TODO: name
wunk_9   :: db ; C0A6

; Set in entry(=$20)
;
; Used in Jump tables
;
; TODO: name
wunk_7   :: db ; C0A7


empty1_3 :: ds $0458


; Set in entry(=$00)
;
; TODO: name
wunk_10  :: db ; C500


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