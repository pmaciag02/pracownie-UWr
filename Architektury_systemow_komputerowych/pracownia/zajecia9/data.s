	.file	"data.c"
	.text
.Ltext0:
	.globl	foo
	.data
	.align 2
	.type	foo, @object
	.size	foo, 2
foo:
	.value	314
	.section	.rodata
	.type	abc, @object
	.size	abc, 4
abc:
	.string	"abc"
	.globl	some
	.section	.data.rel,"aw"
	.align 32
	.type	some, @object
	.size	some, 38
some:
	.quad	weird
	.long	-3
	.zero	4
	.quad	abc
	.quad	foo
	.string	"efghi"
	.globl	bar
	.bss
	.align 8
	.type	bar, @object
	.size	bar, 8
bar:
	.zero	8
	.globl	array
	.align 32
	.type	array, @object
	.size	array, 800
array:
	.zero	800
	.text
.Letext0:
	.file 1 "data.c"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x16f
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF7
	.byte	0xc
	.long	.LASF8
	.long	.LASF9
	.long	.Ldebug_line0
	.uleb128 0x2
	.string	"foo"
	.byte	0x1
	.byte	0x1
	.byte	0x7
	.long	0x33
	.uleb128 0x9
	.byte	0x3
	.quad	foo
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.long	.LASF0
	.uleb128 0x4
	.long	0x5d
	.long	0x4a
	.uleb128 0x5
	.long	0x4f
	.byte	0x3
	.byte	0
	.uleb128 0x6
	.long	0x3a
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF1
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF2
	.uleb128 0x6
	.long	0x56
	.uleb128 0x7
	.string	"abc"
	.byte	0x1
	.byte	0x5
	.byte	0x13
	.long	0x4a
	.uleb128 0x9
	.byte	0x3
	.quad	abc
	.uleb128 0x8
	.byte	0x20
	.byte	0x1
	.byte	0x7
	.byte	0x1
	.long	0xb9
	.uleb128 0x9
	.string	"c"
	.byte	0x1
	.byte	0x8
	.byte	0x9
	.long	0xd6
	.byte	0
	.uleb128 0x9
	.string	"b"
	.byte	0x1
	.byte	0x9
	.byte	0x7
	.long	0xc8
	.byte	0x8
	.uleb128 0x9
	.string	"a"
	.byte	0x1
	.byte	0xa
	.byte	0xf
	.long	0xdc
	.byte	0x10
	.uleb128 0x9
	.string	"d"
	.byte	0x1
	.byte	0xb
	.byte	0xa
	.long	0xe2
	.byte	0x18
	.uleb128 0x9
	.string	"e"
	.byte	0x1
	.byte	0xc
	.byte	0x8
	.long	0xe8
	.byte	0x20
	.byte	0
	.uleb128 0xa
	.long	0xc8
	.long	0xc8
	.uleb128 0xb
	.long	0xcf
	.byte	0
	.uleb128 0xc
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x3
	.byte	0x4
	.byte	0x4
	.long	.LASF3
	.uleb128 0xd
	.byte	0x8
	.long	0xb9
	.uleb128 0xd
	.byte	0x8
	.long	0x5d
	.uleb128 0xd
	.byte	0x8
	.long	0x33
	.uleb128 0x4
	.long	0x56
	.long	0xf7
	.uleb128 0xe
	.long	0x4f
	.byte	0
	.uleb128 0xf
	.long	.LASF4
	.byte	0x1
	.byte	0xd
	.byte	0x3
	.long	0x78
	.uleb128 0x9
	.byte	0x3
	.quad	some
	.uleb128 0x8
	.byte	0x8
	.byte	0x1
	.byte	0x15
	.byte	0x1
	.long	0x12f
	.uleb128 0x9
	.string	"re"
	.byte	0x1
	.byte	0x16
	.byte	0x9
	.long	0xcf
	.byte	0
	.uleb128 0x9
	.string	"im"
	.byte	0x1
	.byte	0x17
	.byte	0x9
	.long	0xcf
	.byte	0x4
	.byte	0
	.uleb128 0x2
	.string	"bar"
	.byte	0x1
	.byte	0x18
	.byte	0x3
	.long	0x10d
	.uleb128 0x9
	.byte	0x3
	.quad	bar
	.uleb128 0x4
	.long	0x155
	.long	0x155
	.uleb128 0x5
	.long	0x4f
	.byte	0x63
	.byte	0
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF5
	.uleb128 0xf
	.long	.LASF6
	.byte	0x1
	.byte	0x1a
	.byte	0x6
	.long	0x145
	.uleb128 0x9
	.byte	0x3
	.quad	array
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x13
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x15
	.byte	0x1
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x1c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF1:
	.string	"long unsigned int"
.LASF5:
	.string	"long int"
.LASF9:
	.string	"/home/patryk/studia/ask/zajecia9"
.LASF7:
	.string	"GNU C17 9.4.0 -mtune=generic -march=x86-64 -ggdb -fno-common -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection"
.LASF0:
	.string	"short int"
.LASF2:
	.string	"char"
.LASF4:
	.string	"some"
.LASF8:
	.string	"data.c"
.LASF3:
	.string	"float"
.LASF6:
	.string	"array"
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
