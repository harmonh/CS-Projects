TITLE Homework Five   (hw5.asm)

; Author: Holly Harmon			email: harmonh@onid.oregonstate.edu
; Course: CS 271-400
; Project ID: Homework 5           Date: 05/25/2014
; Description: **Used my two grace days for this assignment** This program gets a number from
; the user from 100 to 300 and fills an array with that many randomly generated numbers from
; 0 to 999. The array is printed to the user, then sorted in descending order. The median is
; calculated and displayed, then the sorted array is printed to the user.

INCLUDE Irvine32.inc

;user input
	MAX_INPUT = 300
	MIN_INPUT = 100
;random number range
	LO_RANGE = 0
	HI_RANGE = 999

.data
	title_1		BYTE	"Sorting Random Integers            By Holly Harmon",0
	intro_1		BYTE	"This program generates random numbers in the range [0 - 999],",0
	intro_2		BYTE	"displays the original list, sorts the list, and calculates the",0
	intro_3		BYTE	"median value. Finally is displays the list sorted in descending order.",0
	prompt		BYTE	"How many numbers should be generated? [100 - 300]: ",0
	ranError	BYTE	"Invalid input. Try again.", 0
	printRand	BYTE	"The unsorted random numbers:",0
	printSort	BYTE	"The sorted random numbers:",0
	printMed	BYTE	"The median is ",0
	spaces		BYTE	"   ", 0
	request		DWORD	?
	median		DWORD	?
	rows		DWORD	0

	randArray	DWORD	MAX_INPUT	DUP(?)


.code
main PROC
	call	Randomize
;introduction:
	call	intro

;get user data
	push	OFFSET	request
	call	getData

;fill the array
	push	OFFSET	randArray
	push	request
	call	fillArray

;print unsorted array
	push	OFFSET randArray
	push	request
	push	OFFSET printRand
	push	rows
	call	displayList

;sort the array
	push	OFFSET randArray
	push	request
	call	sortList

;calculate/display the median
	push	OFFSET randArray
	push	request
	call	displayMedian

;print the sorted array
	push	OFFSET randArray
	push	request
	push	OFFSET printSort
	push	rows
	call	displayList

   exit
main ENDP

; (insert additional procedures here)

; ***************************************************************
; Procedure to introduce the program
; receives: none
; returns: none
; preconditions: none
; registers changed: edx
; ***************************************************************
intro	PROC
	mov		edx, OFFSET title_1
	call	WriteString
	call	Crlf
	call	Crlf
	mov		edx, OFFSET intro_1
	call	WriteString
	call	Crlf
	mov		edx, OFFSET intro_2
	call	WriteString
	call	Crlf
	mov		edx, OFFSET intro_3
	call	WriteString
	call	Crlf
	ret		
intro	ENDP	

; ***************************************************************
; Procedure to get user inputed integer and validates it is in range
; receives: address of request on system stack
; returns: user input in global request
; preconditions: none
; registers changed: eax, edx
; ***************************************************************
getData	PROC
	push	ebp
	mov		ebp, esp
userInput:	
	mov		edx, OFFSET prompt
	call	WriteString
	call	ReadInt

;validation
	cmp		eax, MAX_INPUT
	jg		error
	cmp		eax, MIN_INPUT
	jge		noError
error:
	mov		edx, OFFSET	ranError
	call	WriteString
	call	Crlf
	jmp		userInput
noError:
	mov		ebx, [ebp+8]
	mov		[ebx], eax
	
	pop		ebp
	ret		4
getData	ENDP

; ***************************************************************
; Procedure to fill the array with the user indicated number of
; random values
; receives: address of array and value of request on system stack
; returns: the array contains the number of random values indicated 
; by request
; preconditions: request is initialized, 100 <= request <= 300
; registers changed: eax, ecx, edi
; ***************************************************************
fillArray	PROC
	push	ebp
	mov		ebp, esp
	mov		ecx, [ebp+8]
	mov		edi, [ebp+12]

fill:
	mov		eax, HI_RANGE
	sub		eax, LO_RANGE
	inc		eax
	call	RandomRange
	add		eax, LO_RANGE
	mov		[edi], eax
	add		edi, 4
	loop	fill

	pop		ebp
	ret		8
fillArray	ENDP

; ***************************************************************
; Procedure to display the array
; receives: address of array, address of title for which array is being
; displayed, value of request and value of rows on system stack
; returns: none
; preconditions: request is initialized, 100 <= request <= 300 and 
; the first elements of the array up to request are initialized
; registers changed: eax, edx, ecx, edi, ebx
; ***************************************************************
displayList	PROC
	push	ebp
	mov		ebp, esp
	mov		edx, [ebp+12]
	call	WriteString
	call	Crlf
	mov		ecx, [ebp+16]
	mov		edi, [ebp+20]
	
print:
	mov		eax, [edi]
	call	WriteDec
	mov		edx, OFFSET spaces
	call	WriteString
	mov		eax, [ebp+8]
	inc		eax
	mov		[ebp+8], eax
	add		edi, 4
	cdq
	mov		eax, [ebp+8]
	mov		ebx, 10
	div		ebx
	cmp		edx, 0
	jne		noLine
	call	Crlf
noLine:
	loop	print

	call	Crlf
	pop		ebp
	ret		12
displayList	ENDP

; ***************************************************************
; Procedure to sort the array in descending order
; receives: address of array and the value of request on system stack
; returns: initialized elements of the array are stored in descending order
; preconditions: request is initialized, 100 <= request <= 300 and 
; the first elements of the array up to request are initialized
; registers changed: eax, ecx, esi
; ***************************************************************
sortList	PROC
	push	ebp
	mov		ebp, esp
	mov		ecx, [ebp+8]
	dec		ecx
;using bubble sort
L1:
	push	ecx
	mov		esi, [ebp+16]
L2:
	mov		eax, [esi]
	cmp		[esi+4], eax
	jl		L3
	xchg	eax, [esi+4]
	mov		[esi], eax
L3:
	add		esi, 4
	loop	L2
	pop		ecx
	loop	L1
	
	pop		ebp
	ret		8
sortList	ENDP

; ***************************************************************
; Procedure to calculate and display the median of the array
; receives: address of array and value of request on system stack
; returns: none
; preconditions: request is initialized, 100 <= request <= 300 and 
; the first elements of the array up to request are initialized
; registers changed: eax, edi, ebx, edx
; ***************************************************************
displayMedian	PROC
	push	ebp
	mov		ebp, esp
	mov		edi, [ebp+12]
	call	Crlf
; divides by 2 and checks if request is odd or even
	cdq
	mov		eax, [ebp+8]
	mov		ebx, 2
	div		ebx
	cmp		edx, 0
	jg		odd

	dec		eax
	mov		ebx, 4
	mul		ebx
	add		edi, eax
	mov		eax, [edi]
	add		eax, [edi+4]
	cdq
	mov		ebx, 2
	div		ebx
	cmp		edx, 0
	je		round
	add		eax, 1
round:
	mov		edx, OFFSET printMed
	call	WriteString
	call	WriteDec
	call	Crlf
	jmp		E1

odd:
	mov		ebx, 4
	mul		ebx
	add		edi, eax
	mov		eax, [edi]
	mov		edx, OFFSET printMed
	call	WriteString
	call	WriteDec
	call	Crlf
E1:
	call	Crlf
	pop		ebp
	ret		8
displayMedian	ENDP

END main
