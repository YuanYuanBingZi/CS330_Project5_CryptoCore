#include <string>
#include <iostream>
#include <algorithm>
#include "ccipher.h"
struct Cipher::CipherCheshire {
    string cipher_alpha;
};

struct CCipher::CCipherCheshire {
    int rot;
};

// -------------------------------------------------------
// Caesar Cipher implementation
CCipher::CCipher() : Cipher() {
	csmile = new CCipherCheshire;
	csmile->rot = 0;
	smile->cipher_alpha = "abcdefghijklmnopqrstuvwxyz";	
}

/* This constructor initiates the object with a
   input cipher key
 */
CCipher::CCipher(int offset) : Cipher() {
    if(offset < 0){
	    cout << "Error: Caesar cipher is less than 0" << endl;
	    exit(EXIT_FAILURE);
	}else{
  	csmile = new CCipherCheshire;
	csmile->rot = offset;
	smile->cipher_alpha = "abcdefghijklmnopqrstuvwxyz";	
	rotate_string(smile->cipher_alpha, csmile->rot);
	}
	
}
/* Destructor
 */
CCipher::~CCipher(){
	delete csmile;
}

// -------------------------------------------------------

// Rotates the input string in_str by rot positions
void rotate_string(string& in_str, int rot)
{
    for(int i = 0; i < in_str.length(); i++){
            in_str[i] = char(int(in_str[i] + rot - 97) % 26 + 97);}
    
    
}

