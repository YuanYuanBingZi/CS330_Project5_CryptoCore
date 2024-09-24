#include <string>
#include <iostream>
#include <vector>
#include "kcipher.h"
#include "vcipher.h"


// -------------------------------------------------------
// Running Key Cipher implementation
// -------------------------------------------------------

struct KCipher::KCipherCheshire{
       vector<string> conts;
       unsigned int page;
};

VCipher::VCipher()  :  KCipher(){}
VCipher::VCipher(string keyword) : KCipher(){
        for(int i = 0; i < keyword.length(); i++ ){
           if(!islower(keyword[i])){
               cout << "Error: not a valid Vigenere key word" << endl;
               exit(EXIT_FAILURE);}
               }
        
        while(keyword.length() < MAX_LENGTH){
            keyword += keyword;
        }
        add_key(keyword);
        set_id(1);
    
}

VCipher:: ~VCipher(){};