# SHA256 Secure Hash Algorithm Program written in C

My name is Ray Mannion and I am a 4th year student in GMIT, studying Software Development.
For my Theory of Algoritms module, I was asked to create a Sha256 encryption program written 
in C using [VI editor](https://en.wikipedia.org/wiki/Vi) on a [Google Clould Virtual Machine](https://cloud.google.com/compute/docs/instances/) running a [Debian GNU/Linux9](https://www.debian.org/) operating system.

### SHA256 Secure Hash Algorithm
A secure hash algorithm or SHA is a set of cryptographic hash functions designed by the United States National Security Agency. The reason for using this algorithm is to encrypt data so that the resulting output would be complete indistinguishable from the input data and would be very difficult to determine the input even if the output is known.

The algorithm shown here is the [SHA256](https://en.wikipedia.org/wiki/SHA-2) algorithm. Its is a keyless encryption method as it does not use any form of key to encrypt the data, which technically means it is not an encryption, but actually a hashing function. It uses a one way compression format, meaning that it cannot be undone, or at the very least very difficult to undo the output or convert back to the original input. 

### How it works
The algorithm uses the functions:

Ch(X, Y, Z) = (X ∧ Y ) ⊕ (X ∧ Z),

Maj(X, Y, Z) = (X ∧ Y ) ⊕ (X ∧ Z) ⊕ (Y ∧ Z),

SIG0(X) = RotR(X, 2) ⊕ RotR(X, 13) ⊕ RotR(X, 22),

SIG1(X) = RotR(X, 6) ⊕ RotR(X, 11) ⊕ RotR(X, 25),

sig0(X) = RotR(X, 7) ⊕ RotR(X, 18) ⊕ ShR(X, 3),

sig1(X) = RotR(X, 17) ⊕ RotR(X, 19) ⊕ ShR(X, 10).

*These function can be found at line 164 in the sha256.c file*

and the 64 binary words K given by the 32 first bits of the fractional parts of the cube roots of the first
64 prime numbers:


0x428a2f98 &nbsp; 0x71374491 0xb5c0fbcf 0xe9b5dba5 0x3956c25b 0x59f111f1 0x923f82a4 0xab1c5ed5

0xd807aa98 0x12835b01 0x243185be 0x550c7dc3 0x72be5d74 0x80deb1fe 0x9bdc06a7 0xc19bf174

0xe49b69c1 0xefbe4786 0x0fc19dc6 0x240ca1cc 0x2de92c6f 0x4a7484aa 0x5cb0a9dc 0x76f988da

0x983e5152 0xa831c66d 0xb00327c8 0xbf597fc7 0xc6e00bf3 0xd5a79147 0x06ca6351 0x14292967

0x27b70a85 0x2e1b2138 0x4d2c6dfc 0x53380d13 0x650a7354 0x766a0abb 0x81c2c92e 0x92722c85

0xa2bfe8a1 0xa81a664b 0xc24b8b70 0xc76c51a3 0xd192e819 0xd6990624 0xf40e3585 0x106aa070

0x19a4c116 0x1e376c08 0x2748774c 0x34b0bcb5 0x391c0cb3 0x4ed8aa4a 0x5b9cca4f 0x682e6ff3



Boolean operations AND, XOR and OR, denoted by ∧, ⊕ and ∨, respectively.



