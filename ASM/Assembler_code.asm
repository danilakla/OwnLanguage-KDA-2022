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
	L2 DWORD 23
	L3 DWORD 45
	L4 DWORD 2
	L5 DWORD 300
	L6 BYTE "------------", 0
	L7 DWORD 3
	L8 DWORD 4
	L9 DWORD 0
	L10 DWORD 15
	L11 DWORD 1112
	L12 DWORD 10
	L13 DWORD 44
	L14 DWORD 1754
	L15 BYTE " test", 0
	L16 DWORD 24
	L17 BYTE "dscxc", 0
	L18 DWORD 5
	L19 BYTE "4314", 0
	L20 BYTE "315", 0
	L21 DWORD 13
	L22 BYTE "lefet reveal o", 0
	L23 DWORD 6
	L24 DWORD 7
	L25 DWORD 8
	L26 DWORD 9

.data
	buffer BYTE 256 dup(0)
	tardate DWORD ?
	tartime DWORD ?
	tartes DWORD 3 dup(0)
	tarvc DWORD 0
	tarvcv DWORD 0
	tarcxtes DWORD 0
	tartes1 DWORD 3 dup(0)
	tartds DWORD 4 dup(0)
	tarti DWORD 0
	tarvb DWORD 0
	tartes3 DWORD 3 dup(0)
	tartes2 DWORD 3 dup(0)
	tartes6 DWORD 3 dup(0)
	tarcvvvv DWORD 0
	maintecx DWORD 4 dup(0)
	maingdh DWORD 0
	mainvc DWORD 0
	maincvx DWORD 0
	mainrc DWORD 0
	mainokk DWORD 0
	mainsize DWORD 0
	mainpis DWORD 10 dup(0)
	maina DWORD 0

.code

tar PROC tara : DWORD, tarb : DWORD
	call Date
	push eax
	pop tardate
	push tardate
	call OutputStr
	call Time
	push eax
	pop tartime
	push tartime
	call OutputStr
	push L1
	pop eax
	mov [tartes+0], eax
	push L2
	pop eax
	mov [tartes+4], eax
	push L3
	pop eax
	mov [tartes+8], eax
	mov eax, 4
	mul L4
	mov esi, eax
	push [tartes+esi]
	push L5
	pop eax
	pop ebx
	add eax, ebx
	push eax
	mov eax, 4
	mul L4
	mov esi, eax
	push [tartes+esi]
	pop eax
	pop ebx
	add eax, ebx
	push eax
	mov eax, 4
	mul L4
	mov esi, eax
	push [tartes+esi]
	pop eax
	pop ebx
	add eax, ebx
	push eax
	mov eax, 4
	mul L4
	mov esi, eax
	push [tartes+esi]
	pop eax
	pop ebx
	add eax, ebx
	push eax
	mov eax, 4
	mul L4
	mov esi, eax
	push [tartes+esi]
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop tarvc
	mov eax, 4
	mul L4
	mov esi, eax
	push [tartes+esi]
	push L5
	pop eax
	pop ebx
	add eax, ebx
	push eax
	mov eax, 4
	mul L4
	mov esi, eax
	push [tartes+esi]
	pop eax
	pop ebx
	add eax, ebx
	push eax
	mov eax, 4
	mul L4
	mov esi, eax
	push [tartes+esi]
	pop eax
	pop ebx
	add eax, ebx
	push eax
	mov eax, 4
	mul L4
	mov esi, eax
	push [tartes+esi]
	pop eax
	pop ebx
	add eax, ebx
	push eax
	mov eax, 4
	mul L4
	mov esi, eax
	push [tartes+esi]
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop tarvcv
	push L1
	pop eax
	mov [tartes1+0], eax
	push L2
	pop eax
	mov [tartes1+4], eax
	push L3
	pop eax
	mov [tartes1+8], eax
	push offset L6
	call OutputStr
	push L1
	pop eax
	mov [tartds+0], eax
	push L4
	pop eax
	mov [tartds+4], eax
	push L7
	pop eax
	mov [tartds+8], eax
	push L8
	pop eax
	mov [tartds+12], eax
	mov eax, 4
	mul L9
	mov esi, eax
	push [tartds+esi]
	pop tarti
	push tarti
	call OutputInt
	mov eax, 4
	mul L7
	mov esi, eax
	push [tartds+esi]
	push L10
	pop eax
	pop ebx
	add eax, ebx
	push eax
	mov eax, 4
	mul L9
	mov esi, eax
pop [tartds+esi]
	mov eax, 4
	mul L9
	mov esi, eax
	push [tartds+esi]
	pop tarvb
	push tarvb
	call OutputInt
	push L4
	call OutputInt
	push offset L6
	call OutputStr
	push L11
	pop tarcxtes
	push L1
	pop eax
	mov [tartes3+0], eax
	push L2
	pop eax
	mov [tartes3+4], eax
	push L3
	pop eax
	mov [tartes3+8], eax
	push tarcxtes
	call OutputInt
	push L1
	pop eax
	mov [tartes2+0], eax
	push L2
	pop eax
	mov [tartes2+4], eax
	push L3
	pop eax
	mov [tartes2+8], eax
	push tarvcv
	call OutputInt
	push L1
	pop eax
	mov [tartes6+0], eax
	push L2
	pop eax
	mov [tartes6+4], eax
	push L3
	pop eax
	mov [tartes6+8], eax
	mov eax, 4
	mul L1
	mov esi, eax
	push [tartes6+esi]
	mov eax, 4
	mul L1
	mov esi, eax
	push [tartes+esi]
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop tarcvvvv
	push tarcvvvv
	call OutputInt
	push L9
	call OutputInt
	push L9
	call OutputInt
	push tarvc
	call OutputInt
	push 10
	jmp local0
local0:
	pop eax
	ret
tar ENDP

fd PROC fdcxvcx : DWORD, fdfvcv : DWORD
	push 44
	jmp local1
local1:
	pop eax
	ret
fd ENDP

main PROC
	mov eax, L12
	cmp eax, L7
	ja m0
	jb m1
	je m1
m0:
	push L4
	call OutputInt
	jmp e0
m1:
	push L7
	call OutputInt
e0:
	push L1
	pop eax
	mov [maintecx+0], eax
	push L4
	pop eax
	mov [maintecx+4], eax
	push L7
	pop eax
	mov [maintecx+8], eax
	push L8
	pop eax
	mov [maintecx+12], eax
	push L14
	pop maingdh
	push maingdh
	call OutputInt
	mov eax, L12
	cmp eax, eax
	jz m2
	jnz m3
	je m3
m2:
	push offset L15
	call OutputStr
m3:
	mov eax, 4
	mul L7
	mov esi, eax
	push [maintecx+esi]
	push L7
	pop eax
	pop ebx
	add eax, ebx
	push eax
	push L16
	push offset L17
	pop edx
	pop edx
	push offset L17
	push L16
	call fd
	push eax
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop mainvc
	push L18
	push L12
	pop eax
	pop ebx
	add eax, ebx
	push eax
	mov eax, 4
	mul L4
	mov esi, eax
	push [maintecx+esi]
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop maincvx
	push mainvc
	call OutputInt
	push offset L19
	push offset L20
	pop edx
	pop edx
	push offset L20
	push offset L19
	call tar
	push eax
	pop mainrc
	push mainrc
	call OutputInt
	push L21
	push L8
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop mainokk
	push mainokk
	call OutputInt
	push offset L22
	call OutputStr
	push L12
	pop mainsize
	push L1
	pop eax
	mov [mainpis+0], eax
	push L4
	pop eax
	mov [mainpis+4], eax
	push L7
	pop eax
	mov [mainpis+8], eax
	push L8
	pop eax
	mov [mainpis+12], eax
	push L18
	pop eax
	mov [mainpis+16], eax
	push L23
	pop eax
	mov [mainpis+20], eax
	push L24
	pop eax
	mov [mainpis+24], eax
	push L25
	pop eax
	mov [mainpis+28], eax
	push L26
	pop eax
	mov [mainpis+32], eax
	push L12
	pop eax
	mov [mainpis+36], eax
	mov eax, 4
	mul L7
	mov esi, eax
	push [mainpis+esi]
	pop maina
	push maina
	call OutputInt
	push 0
	call ExitProcess
main ENDP
end main