# Contribution guide
- [Project structure](#project-structure)
- [Decompiling a function](#decompiling-a-function)
- [Code style](#code-style)
- [Creating new `.c`/`.cpp` files](#creating-new-ccpp-files)
- [Non-matching functions](#non-matching-functions)

## Project structure
- `asm/`: Non-decompiled assembly code
    - `ovXX/`: Code for overlay `XX`
        - `*.s`: Source file in assembly
        - `include/*.inc`: External symbols imported by respective source file
- `build/`: Build output
    - `arm9_linker_script.lcf`: Linker command file for ARM9 program, specifies the order to put code and data into the ROM
    - `arm9_objects.txt`: List of object files to pass to the linker
    - `eur/`: Compiled/linked files
        - `asm/`: Built assembly code
        - `src/`: Built C/C++ code
        - `overlays/`: Contains `.bin` and `.lz` files for each overlay
        - `*.bin`: Linked code/data to compress or put in the ROM
        - `*.lz`: Compressed code to put in the ROM
        - `main.bin.xMAP`: Map file listing RAM addresses for all symbols
- `docs/`: Documentation about the game
- `include/`: Include files
- `ph_eur/`: Game assets, extracted from your own supplied ROM
    - `assets/`: Unmodified assets
    - `banner/`: Banner logo and text that shows on the DS home menu
    - `arm7.bin`: Extracted ARM7 program
    - `arm9_ovdata.bin`: Data about ARM9 overlays
- `src/`: Source C/C++ files
- `tools/`: Tools for this project
    - `compress/`: Compresses code before it is put in the ROM
    - `mwccarm/`: Compiler toolchain
    - `rom/`: Extracts and builds ROMs
    - `lcf.py`: Generates `arm9_linker_script.lcf`
    - `patch_mwcc.py`: Patches bugs in the toolchain
    - `requirements.txt`: Python libraries
    - `setup.py`: Sets up the project
- `assets.txt`: The order of asset directories to put in the ROM
- `*.sha1`: SHA-1 digests of different versions of the game

## Decompiling a function
WIP

## Creating new `.c`/`.cpp` files
New source files must be added to the LCF (Linker Command File). This is done via `lcf.py`, which generates the LCF when
building.

In `lcf.py`, you will see a list of overlays near the top. Each overlay then has a list of source files ending in `.s`, `.c` or
`.cpp`. Those source files, when compiled, are appended to the ROM in the order that they appear in the list.

So, to create a new source file, you put the path to the source file in the correct overlay so that it appears in the correct
order in relation to other source files.

## Code style
The code style is not strict, but please try to mimic the existing style as much as possible.

If it's impossible to match a function while following the code style, then it's OK to not follow it. But do let us know when
this happens so we may amend the code style.

Below is an example of the code style in this project. If something is unclear, look at existing code. If the existing code is
insufficient, then you may decide the code style in that situation.
```cpp
// Space before pointer asterisk * and reference ampersand &
s32 MyClass::MyMethod(MyStruct *myStruct, s32 &anInteger) {
    // Opening brace { on the same line
    // Space after `if`, `while`, `for` and `switch`
    if (myStruct->isCool) {
        // Access member fields using `this`
        // Class member fields are prefixed with "m"
        this->mInteger = anInteger;
    }
    // No space before asterisk * in pointer casts
    // Space after cast operator
    this->mPointer = (u32*) &anInteger;

    // Prefer pre-increment ++i
    // Use s32, s16, s8, etc. instead of int, short, char
    for (s32 i = 0; i < 10; ++i) {
        // Use `char` instead of s8 to indicate actual characters
        char ch = 'A' + i * 2;
        this->mString[i] = ch;
    }

    // Put long conditions on new line
    if (
        // Add clarifying parentheses for bool operators
        (this->mInteger > 10 && this->mPointer != NULL) ||
        (this->mInteger < 5)
    ) {
        // Add clarifying parentheses for bitwise operators
        this->mBool = ((this->mInteger >> 5) & 1) != 0;
    }

    do {
        // Call member functions using `this`
        this->DoStuff();
    // In do-while loops, `while` on same line as closing brace }
    } while (this->CanDoStuff());

    switch (this->mInteger) {
        // Indent `case`
        // If possible, put braces after `case`
        case 8: {
            return *this->mPointer;
        // If possible, put `break` after closing brace }
        } break;
    }

    // No parentheses around return value
    return this->mInteger;
}
```

## Non-matching functions
This project supports non-matching functions, and you can build them by using `make NONMATCHING=1`.

Non-matching functions must be written as follows:
```cpp
#include "global.hpp"

NONMATCH void MyFunction() {
    #ifndef NONMATCHING
    #include "../asm/path/to/asm.inc"
    #else
    // non-matching code here
    #endif
}
```

When building normally, the `NONMATCH` macro will mark `MyFunction` as an assembly function, and the `NONMATCHING` macro will
not be defined so that the `asm.inc` file will be included.

Conversely, when building in non-matching mode, `MyFunction` will be a regular C/C++ function, and the non-matching code will
be inserted instead of `asm.inc`.

When contributing non-matching functions to this project, please build in both modes and fix any build errors you may get.
Delete the `.o` file between building in each mode so that the `Makefile` runs the compiler both times.

> [!NOTE] The inline assembler does not function the same as the standalone assembler. [See differences here.](inline_assembler.md#differences-from-standalone-assembler)