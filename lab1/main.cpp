
#include "modAlphaCipher.h"
using namespace std;
void check(const string& Text, const string& key)
{
	try {
		string cipherText;
		string decryptedText;
		if (key.empty())
            throw cipher_error("Empty key");
        if (stoi(key) > 1) {
            modAlphaCipher cipher(stoi(key));
            cipherText = cipher.encrypt(Text);
            decryptedText = cipher.decrypt(cipherText);
			cout<<"key="<<key<<endl;
			cout<<cipherText<<endl;
			cout<<decryptedText<<endl;
		}else
			throw cipher_error(std::string("Invalid key ")+key);

	
 	} catch (const cipher_error & e) {
 		cerr<<"Error: "<<e.what()<<endl;
 }
}
int main()
{
    check("SHERBET","0");
    check("SHERBET", "1");
    check("SHERBET", "-65");
    check("SHERBET","");
    check("S H E R B E T","8");
    check("SHERBET","28");
    check("123456789","7");
    check("SHERBET","4");
}














































/* проверка, чтобы строка состояла только из прописных букв
bool isValid(const string& s)
{
	for(const auto &c:s)
		if (!isalpha(c))
			return false;
	return true;
}
int main()
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	int key;
	string st;
	unsigned op;
	cout<<"Cipher ready. Input key(number): ";
	cin>>key;
	if (!cin.good()) {
		cerr<<"key not valid\n";
		return 1;
 	}
 cout<<L"Key loaded\n";
 modAlphaCipher cipher(key);
 do {
 	cout<<L"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
 	cin>>op;
 	if (op > 2) {
 		cout<<L"Illegal operation\n";
 	} else if (op >0) {
 		cout<<L"Cipher ready. Input text: ";
 		cin>>st;
 		if (isValid(st)) {
 			if (op==1) {
 				cout<<L"Encrypted text: "<<cipher.encrypt(st)<<endl;
 			} else {
 				cout<<L"Decrypted text: "<<cipher.decrypt(st)<<endl;
 			}
 		} else {
 			wcout<<L"Operation aborted: invalid text\n";
		}
	 }
 } while (op!=0);
 return 0;
}*/
