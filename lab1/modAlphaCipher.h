/** @file modAlphaCipher
 * @author Коросткин А.П.
 * @version 1.0
 * @date 16.12.2023
 * @copyright ИБСТ ПГУ
 * @brief Классы для шифрования методом маршрутной перестановки
 */
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <locale>
#include <codecvt>
#include <algorithm>
#include <UnitTest++/UnitTest++.h>
using namespace std;
/**
 * @brief класс для шифровки методом маршрутной перестановки
 * @warning класс работает только на английском языке
*/
class modAlphaCipher
{
private:
/**
 * @brief создан объект newkey типа int.
*/
    int newkey;
/**
 * @brief Объявляется функция getValidOpenText,которая принимает константную ссылку на объект типа string в качестве аргумента и возвращает объект типа string.
*/
    string getValidOpenText(const string & s);
/**
 * @brief Объявляется функция getValidKey,которая принимает константную ссылку на объект типа wstring в качестве аргумента и возвращает объект типа wstring.
*/
    string getValidKey(const string & newkey);
public:
/**
 * @brief Удаление конструкторов без параметров
*/
    modAlphaCipher()=delete;
/**
 * @brief  Объявляется конструктор для класса modAlphaCipher, который принимает константную ссылку на объект типа int в качестве аргумента key. Далее, через инициализацию списка членов, в конструкторе устанавливается значение переменной newkey равным значению key.
 * @details Таким образом, этот конструктор позволяет инициализировать объект класса modAlphaCipher с использованием целочисленного ключа.
*/
    modAlphaCipher(const int& key) :newkey(key) {};
/**
 * @brief Объявляется конструктор для класса modAlphaCipher, который принимает константную ссылку на объект типа string в качестве аргумента.
 * @details Этот конструктор предназначен для инициализации объекта класса modAlphaCipher с использованием строки ключа типа string.
*/
    modAlphaCipher(const string& skey);
    //modAlphaCipher(const int k)
/**
 * @brief Объявляется функция encrypt, которая принимает константную ссылку на объект типа string в качестве аргумента и возвращает объект типа string.
*/ 
    string encrypt(const string& open_st);
/**
 * @brief Объявляется функция decrypt, которая принимает константную ссылку на объект типа string в качестве аргумента и возвращает объект типа string.
*/   
    string decrypt(const string& cipher_st);
    //static int getValidKey(const std::string & s);
};
/**
 * @brief Класс для вывода ошибок при шифровании
*/
class cipher_error: public invalid_argument {
public:
/**
 * @brief Определяется явный конструктор cipher_error, который принимает ссылку на объект типа string в качестве аргумента what_arg
 * @details Внутри конструктора вызывается конструктор базового класса invalid_argument с переданным аргументом what_arg
*/
	explicit cipher_error (const string& what_arg):
		invalid_argument(what_arg) {}
/**
 * @brief Определяется явный конструктор cipher_error, который принимает ссылку на объект типа char в качестве аргумента what_arg
 * @details Внутри конструктора вызывается конструктор базового класса invalid_argument с переданным аргументом what_arg
*/
	explicit cipher_error (const char* what_arg):
		invalid_argument(what_arg) {}
};
