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
	num_err byte 'Error: ???????????? ? ?????????? ?????????????? ????????!', 0
	L1 DWORD 1
	L2 DWORD 2
	L3 BYTE "text for text", 0
	L4 BYTE "hi", 0
	L5 DWORD 100
	L6 DWORD 50
	L7 DWORD 4
	L8 DWORD 6
	L9 DWORD 13
	L10 DWORD 5
	L11 DWORD 3
	L12 DWORD 23

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
	mov eax, condv
	cmp eax, condk
	jne m2
	je m3
	je m3
m2:
	push L1
	call OutputInt
	jmp e1
m3:
	push L2
	call OutputInt
e1:
	mov eax, condv
	cmp eax, condk
	jae m4
	jb m5
	je m5
m4:
	push L1
	call OutputInt
	jmp e2
m5:
	push L2
	call OutputInt
e2:
	push L1
	jmp local0
local0:
	pop eax
	ret
cond ENDP

text PROC pzm : DWORD
	push offset L3
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
	cmp eax, 2147483647
ja num_error
	push eax
	pop powres
	push powres
	jmp local2
local2:
	pop eax
	ret
pow ENDP

main PROC
	push offset L4
	call OutputStr
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
	cmp eax, 2147483647
ja num_error
	push eax
	pop mainx
	push mainx
	call OutputInt
	call text
	push eax
	pop mainpos
	push mainpos
	call OutputStr
	push L7
	push L8
	pop edx
	pop edx
	push L8
	push L7
	call cond
	push eax
	pop mainres
	push mainres
	call OutputInt
	push L9
	pop maini
	push maini
	call OutputInt
	push L7
	pop eax
	mov [mainarr+0], eax
	push L10
	pop eax
	mov [mainarr+4], eax
	push L8
	pop eax
	mov [mainarr+8], eax
	push mainy
	push L11
	pop edx
	push L11
	call pow
	push eax
	pop eax
	pop ebx
	add eax, ebx
	push eax
	cmp eax, 2147483647
ja num_error
	push eax
	mov eax, 4
	mul L2
	mov esi, eax
	push [mainarr+esi]
	pop eax
	pop ebx
	add eax, ebx
	push eax
	cmp eax, 2147483647
ja num_error
	push eax
	pop mainpolish
	push mainpolish
	call OutputInt
	push L12
	mov eax, 4
	mul L2
	mov esi, eax
	push [mainarr+esi]
	pop eax
	pop ebx
	add eax, ebx
	push eax
	cmp eax, 2147483647
ja num_error
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
num_error::
push offset num_err
call OutputStr
call ExitProcess
main ENDP
end main