# CS330_Project6_CryptoCore

## Project Overview

**CryptoCore** is a C++ project that implements a variety of classical encryption algorithms including Substitution, Caesar, ROT13, Running Key, and Vigenère ciphers. Each cipher is designed using object-oriented programming principles, with a focus on inheritance and polymorphism. This project provides both encryption and decryption functionalities, while also ensuring proper error handling and memory management.

## Features

- **Substitution Cipher**: Uses a custom cipher alphabet for encryption.
- **Caesar Cipher**: Shifts letters of the alphabet by a specified number of positions.
- **ROT13 Cipher**: A specific case of the Caesar cipher with a shift of 13.
- **Running Key Cipher**: Encrypts messages using a text from a "book" (series of strings).
- **Vigenère Cipher**: Uses a repeating keyword to shift the alphabet during encryption.
- **Error Handling**: Checks for invalid inputs such as incorrect alphabet lengths, invalid shift values, or insufficient running key length.
- **Memory Management**: Designed to avoid memory leaks, using destructors to properly clean up resources.

## File Structure

```
.
├── cipher.h               # Header file for the cipher classes
├── cipher.cc              # Implementation of cipher functions
├── main.cc                # Main file (DO NOT MODIFY)
├── input/                 # Directory with example input files
│   ├── caesar.txt
│   ├── substitution.txt
│   └── ...
├── output/                # Directory to store the generated output files
└── Makefile               # For building the project
```

## How to Build and Run

### Prerequisites

- A C++ compiler that supports C++11 or later.

### Compilation

To compile the project, simply use the `make` command in your terminal:

```bash
make
```

### Execution

After compiling, the program can be executed with the following command format:

```bash
./cipher -m <cipher_type> -i <input_file> -o <output_file>
```

#### Example

For a Caesar cipher with a shift defined in the input file:

```bash
./cipher -m c -i input/caesar.txt -o output/caesar_out.txt
```

Where:
- `-m c`: Specifies the Caesar cipher.
- `-i input/caesar.txt`: The input file containing the shift value and plain text.
- `-o output/caesar_out.txt`: The output file that will contain the encrypted and decrypted text.

### Supported Cipher Types
- `-m s`: Substitution Cipher
- `-m c`: Caesar Cipher
- `-m r`: ROT13 Cipher
- `-m k`: Running Key Cipher
- `-m v`: Vigenère Cipher

### Input File Format

Each input file should follow a specific format depending on the cipher being used. For example, a Caesar cipher input file should have:
1. The shift value on the first line.
2. The plain text to encrypt on the second line.

### Output File

The output file will contain the following:
1. Encrypted text in the first line.
2. Decrypted text in the second line.

### Error Handling

If invalid inputs or errors are encountered (e.g., invalid alphabet, invalid key length), the program will exit with an appropriate error message and `EXIT_FAILURE`.

## Class Structure

The project is structured using object-oriented programming principles. The main classes include:

- **Substitution Cipher**: The base class that handles basic substitution encryption and decryption.
- **Caesar Cipher**: Inherits from Substitution Cipher, implements Caesar shift logic.
- **ROT13 Cipher**: Inherits from Caesar Cipher, with a default shift of 13.
- **Running Key Cipher**: Inherits from Substitution Cipher, uses a "book" of strings for encryption.
- **Vigenère Cipher**: Inherits from Substitution Cipher, uses a keyword to shift the alphabet.

## Testing

The project includes several test files located in the `input/` directory. After running the program, verify the output in the `output/` directory to ensure the encrypted and decrypted text matches the expected results.

## Future Enhancements

1. **Support for Punctuation and Numbers**: Extend the encryption and decryption algorithms to handle punctuation and numbers, making the ciphers more versatile.
   
2. **Case-Insensitive Encryption**: Implement case-insensitive encryption to allow the ciphers to handle both upper and lower case letters without changing the original letter case.

3. **User Interface**: Develop a user-friendly command-line interface that allows users to easily select different ciphers and view real-time encryption/decryption results.
