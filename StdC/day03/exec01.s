	.file	"exec01.c"
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$20, %esp
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	movl	$0, -24(%ebp)
	movl	$0, -20(%ebp)
	movl	$0, -16(%ebp)
	subl	$8, %esp
	leal	-24(%ebp), %eax
	pushl	%eax
	pushl	$.LC0
	call	__isoc99_scanf
	addl	$16, %esp
	subl	$8, %esp
	leal	-16(%ebp), %eax
	pushl	%eax
	pushl	$.LC0
	call	__isoc99_scanf
	addl	$16, %esp
	subl	$8, %esp
	leal	-20(%ebp), %eax
	pushl	%eax
	pushl	$.LC0
	call	__isoc99_scanf
	addl	$16, %esp
	movl	-24(%ebp), %eax
	testl	%eax, %eax
	je	.L2
	movl	-16(%ebp), %edx
	movl	-20(%ebp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	cmpl	$104, %eax
	setle	%al
	movzbl	%al, %eax
	jmp	.L3
.L2:
	movl	-16(%ebp), %edx
	movl	-20(%ebp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	cmpl	$109, %eax
	setle	%al
	movzbl	%al, %eax
.L3:
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	movl	-24(%ebp), %eax
	testl	%eax, %eax
	je	.L4
	movl	-16(%ebp), %edx
	movl	-20(%ebp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	cmpl	$104, %eax
	jle	.L5
.L4:
	movl	-24(%ebp), %eax
	testl	%eax, %eax
	jne	.L6
	movl	-16(%ebp), %edx
	movl	-20(%ebp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	cmpl	$109, %eax
	jg	.L6
.L5:
	movl	$1, %eax
	jmp	.L7
.L6:
	movl	$0, %eax
.L7:
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	movl	$0, %eax
	movl	-12(%ebp), %ecx
	xorl	%gs:20, %ecx
	je	.L9
	call	__stack_chk_fail
.L9:
	movl	-4(%ebp), %ecx
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
