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
	L1 DWORD 1
	L2 DWORD 2
	L3 DWORD 4
	L4 BYTE "text for text", 0
	L5 DWORD 10
	L6 DWORD 50
	L7 DWORD 6
	L8 DWORD 13
	L9 DWORD 5
	L10 DWORD 3
	L11 DWORD 23

.data
	buffer BYTE 256 dup(0)
	powres DWORD 0
	maindate DWORD ?
	maintime DWORD ?
	mainx DWORD 0
	mainy DWORD 0
	mainpos DWORD ?
	mainres DWORD 0
	maini DWORD 0
	mainpolish DWORD 0
	mainarr DWORD 3 dup(0)

.code

cond PROC condv : DWORD, condk : DWORD
	mov eax, condv
	cmp eax, condk
	ja m0
	jb m1
	je m1
m0:
	push L1
	call OutputInt
	jmp e0
m1:
	push L2
	call OutputInt
e0:
	mov eax, L2
	cmp eax, L1
	jne m2
	je m3
	je m3
m2:
	push L1
	call OutputInt
m3:
	push L3
	jmp local0
local0:
	pop eax
	ret
cond ENDP

text PROC pzm : DWORD
	push offset L4
	jmp local1
local1:
	pop eax
	ret
text ENDP

pow PROC powc : DWORD
	push powc
	push powc
	pop eax
	pop ebx
	mul ebx
	push eax
	pop powres
	push powres
	jmp local2
local2:
	pop eax
	ret
pow ENDP

main PROC
	call Date
	push eax
	pop maindate
	push maindate
	call OutputStr
	call Time
	push eax
	pop maintime
	push maintime
	call OutputStr
	push L5
	pop mainy
	push mainy
	push L6
	pop ebx
	pop eax
	sub eax, ebx
	push eax
	pop mainx
	push mainx
	call OutputInt
	call text
	push eax
	pop mainpos
	push mainpos
	call OutputStr
	push L3
	push L7
	pop edx
	pop edx
	push L7
	push L3
	call cond
	push eax
	pop mainres
	push mainres
	call OutputInt
	push L8
	pop maini
	push maini
	call OutputInt
	push L3
	pop eax
	mov [mainarr+0], eax
	push L9
	pop eax
	mov [mainarr+4], eax
	push L7
	pop eax
	mov [mainarr+8], eax
	push mainy
	push L10
	pop edx
	push L10
	call pow
	push eax
	pop eax
	pop ebx
	add eax, ebx
	push eax
	mov eax, 4
	mul L2
	mov esi, eax
	push [mainarr+esi]
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop mainpolish
	push mainpolish
	call OutputInt
	push L11
	mov eax, 4
	mul L2
	mov esi, eax
	push [mainarr+esi]
	pop eax
	pop ebx
	add eax, ebx
	push eax
	mov eax, 4
	mul L1
	mov esi, eax
pop [mainarr+esi]
	mov eax, 4
	mul L1
	mov esi, eax
	push [mainarr+esi]
	pop mainpolish
	push mainpolish
	call OutputInt
	push 0
	call ExitProcess
main ENDP
end main