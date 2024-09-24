#include <string>
#include <iostream>
#include <vector>
#include "kcipher.h"




/* Helper function definitions
 */
void add_key(string cont);
void set_id(unsigned int page);
string generate_row(string &in_str, int rot);
// -------------------------------------------------------
// Running Key Cipher implementation
// -------------------------------------------------------

struct KCipher::KCipherCheshire{
       vector<string> conts;
       unsigned int page;
};

KCipher::KCipher() :Cipher(){
       ksmile = new KCipherCheshire;
       string init_page;
       for(unsigned int i = 0; i < MAX_LENGTH; i++){
              init_page.push_back('a');
       }
       add_key(init_page);
       set_id(0);
}

KCipher::KCipher(string cont) : Cipher(){
       ksmile = new KCipherCheshire;
       add_key(cont);
}

KCipher:: ~KCipher(){
       delete ksmile;
}

string KCipher::encrypt (string raw){
       cout << "Encrypting...";
       string retStr;
       string alphabet = "abcdefghijklmnopqrstuvwxyz";
       // get the key from the assigned page
       // get the plain text character
       // find the encrypted character
       int index = 0;
       for(int i = 0; i < raw.length(); i++){
              if (raw[i] == ' '){
                     retStr.push_back(' ');
                     continue;
              }
              else{
                  //generate the row 
                  int dis = LOWER_CASE(raw[i]) - 'a';
                  string row = generate_row(alphabet, dis);
                  // get the column
                  int length = ksmile->conts[ksmile->page].length();
                  while (ksmile->conts[ksmile->page][index] == ' '){
                     index += 1;}
                  if (index > length - 1){
                      cout << "Invalid Running Key: " << ksmile->conts[ksmile->page] << endl;
                      exit(EXIT_FAILURE);
                     }
                  int column = find_pos(alphabet,ksmile->conts[ksmile->page][index]);
                  if (isupper(raw[i])){
                     retStr.push_back(UPPER_CASE(row[column]));
                  }else{
                     retStr.push_back(row[column]);}
                  index += 1;
                  }

       }


       cout << "Done" << endl;

	return retStr;

}

string KCipher::decrypt (string enc){
       cout << "Decrypting...";
       string retStr;
       string alphabet = "abcdefghijklmnopqrstuvwxyz";
       int index = 0;
       for(int i = 0; i < enc.length(); i++){
              if (enc[i] == ' '){
                     retStr.push_back(' ');
                     continue;
              }
              else{
                  int length = ksmile->conts[ksmile->page].length();
                  while (ksmile->conts[ksmile->page][index] == ' '){
                     index += 1;}
                  if (index > length - 1){
                      cout << "Invalid Running Key: " << ksmile->conts[ksmile->page] << endl;
                      exit(EXIT_FAILURE);
                     }
                  //generate the row 
                  int dis = (ksmile->conts[ksmile->page][index]) - 'a';
                  string row = generate_row(alphabet, dis);
                  // get the column
                  int column = find_pos(row, LOWER_CASE(enc[i]));
                  if (isupper(enc[i])){
                     retStr.push_back(UPPER_CASE(alphabet[column]));
                  }else{
                     retStr.push_back(alphabet[column]);}
                  index += 1;
                  }

       }


       cout << "Done" << endl;

	return retStr;

}

void KCipher::add_key(string cont){
       if(cont.length() == 0){
              cout << "Invalid Running Key: " << cont << endl;
              exit(EXIT_FAILURE);
       }else{
              for(unsigned int i = 0; i < cont.length(); i++){
                 if(!(islower(cont[i]) || cont[i] == ' ' )){
                     cout << "Invalid Running Key: " << cont << endl;
                     exit(EXIT_FAILURE);
                 }
              }
       }
       ksmile->conts.push_back(cont);
}

void KCipher::set_id(unsigned int page){
       if(page < ksmile->conts.size() && page >= 0){
           ksmile->page = page;
       }else{
           cout << "Warning: invalid id: " << page << endl;
           exit(EXIT_FAILURE);
       }


}



// Rotates the input string in_str by rot positions
string generate_row(string &in_str, int rot)
{
    string retStr;
    for(int i = 0; i < in_str.length(); i++){
            retStr.push_back(char(int(in_str[i] + rot - 97) % 26 + 97));}
    return retStr;
}



