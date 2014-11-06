	.file	"3_16.c"
	.text
	.p2align 4,,15
	.globl	absdiff
	.type	absdiff, @function
absdiff:
.LFB0:
	.cfi_startproc
	movl	4(%esp), %edx
	movl	8(%esp), %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	cmpl	%ecx, %edx
	jl	.L5
	ret
	.p2align 4,,7
	.p2align 3
.L5:
	movl	%ecx, %eax
	subl	%edx, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	absdiff, .-absdiff
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.7.3-1ubuntu1) 4.7.3"
	.section	.note.GNU-stack,"",@progbits
