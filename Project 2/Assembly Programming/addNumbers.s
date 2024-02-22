; Programmer: Kai Schenkel
; Class: SD-247 Computer Architecture
; Data: 2/4/2024
; Project 2: Assembly Programming

	.file	"addNumbers.c"
	.text
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "Numbers going though the Addition Function\0"
	.text
	.globl	addNums
	.def	addNums;	.scl	2;	.type	32;	.endef
	.seh_proc	addNums
addNums:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	movl	%ecx, %ebx
	movl	%edx, %esi
	leaq	.LC0(%rip), %rcx
	call	puts
	leal	(%rbx,%rsi), %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.ident	"GCC: (Rev6, Built by MSYS2 project) 13.1.0"
	.def	puts;	.scl	2;	.type	32;	.endef
