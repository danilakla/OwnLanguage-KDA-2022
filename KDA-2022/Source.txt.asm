.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
includelib ../Debug/StaticLib.lib
ExitProcess PROTO :DWORD

EXTRN Date: proc
EXTRN Time: proc
EXTRN OutputInt: proc
EXTRN OutputStr: proc

.stack 4096

.CONST
	L1 BYTE "4242", 0

.data
	buffer BYTE 256 dup(0)
	mainv DWORD ?

.code

main PROC
	push offset L1
	pop mainv
	push mainv
	call OutputStr
	push 0
	call ExitProcess
main ENDP
end main