# caesar-cipher
A simple Caesar cipher implementation in C. The Caesar cipher is one of the simplest and oldest methods of encryption. It works by shifting each letter in the plaintext by a fixed number of positions down or up the alphabet.

This program allows the user to encrypt or decrypt messages by specifying an offset (shift value).

## Features
- Encrypt: Shift the characters of a message by a specified number of positions.
- Decrypt: Reverse the encryption process using the same shift value.
- Custom Shift: Users can specify their own shift value for the cipher.

## Installation
```
gcc -o caesar caesar.c
```

## Usage
After compiling, run the program with the following instructions:

- The program will prompt you to enter the message you want to encrypt or decrypt.
- You will be asked to enter a shift value (e.g., 3 for a Caesar shift).
- You can choose whether you want to encrypt or decrypt the message.

## Example:
To encrypt the message "HELLO" with a shift value of 3:

```
Enter message: HELLO
Enter shift value: 3
Encrypted message: KHOOR
```

To decrypt the message "KHOOR" with a shift value of 3:

```
Enter message: KHOOR
Enter shift value: 3
Decrypted message: HELLO
```
