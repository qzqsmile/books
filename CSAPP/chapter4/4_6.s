.text
.global pushtest
pushtest:
	pushl %ebp
	movl %esp, %ebp
	movl %esp, %eax
	pushl %esp
	popl %edx
	subl %edx,%eax
	leave
	ret
