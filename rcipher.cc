#include <string>
#include <iostream>
#include "rcipher.h"
struct Cipher::CipherCheshire {
    string cipher_alpha;
};

struct CCipher::CCipherCheshire {
    int rot;
};
// -------------------------------------------------------
// ROT13 Cipher implementation
// -------------------------------------------------------
RCipher::RCipher() : CCipher() {
	csmile->rot = 13;
	smile->cipher_alpha = "abcdefghijklmnopqrstuvwxyz";	
	rotate_string(smile->cipher_alpha, csmile->rot);	
}

RCipher:: ~RCipher(){};