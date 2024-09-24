#ifndef VCIPHER_H_
#define VCIPHER_H_
//#include "cipher.h"
#include "kcipher.h"

using namespace std;

/* A class that implements a
   Vigenere cipher class. It 
   inherts KCipher */
// TODO: Implement this class
class VCipher : public KCipher{
protected:
	struct VCipherCheshire;
	VCipherCheshire *vsmile;
public:
   VCipher();
   VCipher(string keyword);
   ~VCipher();
};

#endif

