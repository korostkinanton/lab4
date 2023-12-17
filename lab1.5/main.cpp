
#include "modAlphaCipher.h"
using namespace std;
// проверка, чтобы строка состояла только из прописных букв

void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{
	try {
		wstring cipherText;
		wstring decryptedText;
		modAlphaCipher cipher(key);
		cipherText = cipher.encrypt(Text); // зашифровывание
 		if (destructCipherText) // надо "портить"?
 			cipherText.front() = tolower(cipherText.front()); // "портим"
 		decryptedText = cipher.decrypt(cipherText); 
		wcout<<"key="<<key<<endl;
		wcout<<Text<<endl;
		wcout<<cipherText<<endl;
		wcout<<decryptedText<<endl;
	} catch (const cipher_error & e) {
		wcerr<<"Error: "<<e.what()<<endl;
	
	}
}
int main(){
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	check(L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ",L"Просто");
	check(L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ",L"");
	check(L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ",L"АБВГ123");
	check(L"абвгдеёжзийклмнопрстуфхцчшщъыьэюя",L"СУПЕР");
	check(L"1234567890",L"АБВГ");
	check(L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ",L"ТОПСЕКРЕТ",true);
return 0;
}
