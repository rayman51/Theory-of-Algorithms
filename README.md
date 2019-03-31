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

*Boolean operations AND, XOR and OR, are denoted by ∧, ⊕ and ∨, respectively*

and the 64 binary words K given by the 32 first bits of the fractional parts of the cube roots of the first
64 prime numbers:


0x428a2f98&nbsp;0x71374491&nbsp;0xb5c0fbcf&nbsp;0xe9b5dba5&nbsp;0x3956c25b&nbsp;0x59f111f10x923f82a4&nbsp;0xab1c5ed5

0xd807aa98&nbsp;0x12835b01&nbsp;0x243185be&nbsp;0x550c7dc3&nbsp;0x72be5d74&nbsp;0x80deb1fe0x9bdc06a7&nbsp; 0xc19bf174

0xe49b69c1&nbsp;0xefbe4786&nbsp;0x0fc19dc6&nbsp;0x240ca1cc&nbsp;0x2de92c6f&nbsp;0x4a7484aa0x5cb0a9dc&nbsp;  0x76f988da

0x983e5152&nbsp;0xa831c66d&nbsp;0xb00327c8&nbsp;0xbf597fc7&nbsp;0xc6e00bf3&nbsp;0xd5a791470x06ca6351&nbsp;  0x14292967

0x27b70a85&nbsp;0x2e1b2138&nbsp;0x4d2c6dfc&nbsp;0x53380d13&nbsp;0x650a7354&nbsp;0x766a0abb0x81c2c92e&nbsp;  0x92722c85

0xa2bfe8a1&nbsp;0xa81a664b&nbsp;0xc24b8b70&nbsp;0xc76c51a3&nbsp;0xd192e819&nbsp;0xd69906240xf40e3585&nbsp; 0x106aa070

0x19a4c116&nbsp;0x1e376c08&nbsp;0x2748774c&nbsp;0x34b0bcb5&nbsp;0x391c0cb3&nbsp;0x4ed8aa4a0x5b9cca4f&nbsp;  0x682e6ff3


## Padding
SHA 256 works by reading message block of size 512, with the last 64 bits of the block left to denote the size of the original message. When the program reads in the file, it takes the bits of all the data and adds it up. It then add a one and pads the message block out with zeros to 448 bits. 512 - 64 = 448.

So, if a message was 3 characters with 8 bits each, 3 X 8 = 24

A one is then added to the message 24 + 1 = 25

The program will pad the message out with 423 zeros 448 - 25 = 423

Leaving the last 64 bits so that a number representing the bits in the original message can be added to the block. 

If a message message contains more than 512 bit then multiple blocks of 512 are used

If a message is 765 bits in size, the first block will take the first 512 bits

The second block then takes the remaining 253 bits 756 - 512 = 253

A one is then added to the message 253 + 1 = 254

The program will pad the message out with 194 zeros 448 - 254 = 194

Leaving the last 64 bits so that a number representing the bits in the original message can be added to the block.

## To run the program

First clone the project to your local machine

Cd to the project

To compile the sha256 file write the command  gcc -o sha256 sha256.c

To run the file write the command ./sha256 NAME OF FILE HERE

The program will then print to screen the hash value of the file you passed it.

## Useful Resources

[SHA256](https://en.wikipedia.org/wiki/SHA-2)
[Link to FEDERAL INFORMATION PROCESSING STANDARDS for Secure Hash Standard (SHS) ](https://ws680.nist.gov/publication/get_pdf.cfm?pub_id=919060 )

Many thanks to Dr. Ian McLoughlin (GMIT) for the video lectures provided to create this project