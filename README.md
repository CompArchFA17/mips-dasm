# mips-dasm-filter
mips-dasm-filter is a MIPS disassembler filter process for [GTKWave](http://gtkwave.sourceforge.net/) written in C. 
It takes 32-bit hexadecimal values on stdin and generates their MIPS mnemonic on stdout.

Example: ```213104d2 -> addi $s1, $t1, 1234```

It is based on Orvar Segerström's more-capable [mips-disasm](https://github.com/0rvar/mips-dasm) (which also works on files), with small tweaks to make the output more compact for waveform-based debugging.

## Requirements
gcc or clang

## Getting started
Build using make:

    make


## Usage

Load the waveform with MIPS instructions in GTKWave. Right-click on the signal you want to disassemble and select "Data Format > Translate Filter Process > Enable and Select". Select the compiled mips-disasm-filter program from the chooser.

This repository also contains a collection of static filter files for the various fields of a MIPS instruction. To use those, follow the same process as above but choose "Translate Filter File".

## Tests
A test suite is included to verify the correctness of the disassembler.
To run it, do:

    make tests

## Supported instructions
Almost all instructions except for floating point are supported.

See instructions_test.c for a complete list of supported instructions.

## License
The code is licensed under GPLv3 - see LICENSE.txt
