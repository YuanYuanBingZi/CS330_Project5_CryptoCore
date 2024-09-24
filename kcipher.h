#ifndef KCIPHER_H_
#define KCIPHER_H_
#include "cipher.h"
#include "ccipher.h"

using namespace std;

const unsigned int MAX_LENGTH = 100;

/* A class that implements a
   Running key cipher class. It 
   inherts class Cipher */
// TODO: Implement this function
class KCipher : public Cipher{
protected:
	struct KCipherCheshire;
	KCipherCheshire *ksmile;
public:
   KCipher();
   KCipher(string cont);
   ~KCipher();
   string encrypt(string raw);
   string decrypt(string enc);
   void add_key(string cont);
   void set_id(unsigned int page);
};

#endif

string generate_row(string &in_str, int rot);

