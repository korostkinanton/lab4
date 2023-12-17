#include "modAlphaCipher.h"
using namespace std;
string wst (int k, string s1)
{
    modAlphaCipher w(k);
    string s = w.encrypt(s1); 
    return s;
}
string wst1 (int k, string s1)
{
    modAlphaCipher w(k);
    string s = w.decrypt(s1); 
    return s;
}
SUITE (KeyTest)
{
    string test = "SHERBET";
    int k;
    TEST (ValidKey) {
        CHECK_EQUAL(wst(k=4,test),"RETHESB");
    }
    /*TEST(EmptyKey) {
        CHECK_THROW(wst(k, test), cipher_error);
    }*/
    TEST(NegativeKey) {
        CHECK_THROW(wst(k=-5,test), cipher_error);
    }
    TEST(LargeKey) {
        CHECK_THROW(wst(k=55,test), cipher_error);
    }
    /*TEST(Aonekey) {
        CHECK_THROW(wst(k=1,test), cipher_error);
    }*/
}
SUITE(EncryptTest)
{
    TEST(ValidText) {
        CHECK_EQUAL(wst(4,"SHERBET"),"RETHESB");
    }
    TEST(LowText) {
        CHECK_EQUAL(wst(4,"SHerBet"),"retHeSB");
    }
    TEST(SpaceText) {
        CHECK_THROW(wst(4,"SHER BET"), cipher_error);
    }
    TEST(EmptyText) {
        CHECK_THROW(wst(4," "),cipher_error);
    }
    TEST(ValiDTextWithoutletters) {
        CHECK_THROW(wst(4,"!*><?/,.123"),cipher_error);
    }
    TEST(TextWithNumber) {
        CHECK_THROW(wst(4,"SherB123eT"),cipher_error);
    }

}
SUITE(DecryptText)
{
    TEST(ValidTEXT) {
        CHECK_EQUAL(wst1(4,"RETHESB"),"SHERBET");
    }
    TEST(LowTEXT) {
        CHECK_EQUAL(wst1(4,"retHeSB"),"SHerBet");
    }
    TEST(SpaceTEXT) {
        CHECK_THROW(wst1(4,"SHB ETR"),cipher_error);
    }
    TEST(EmptyTEXT) {
        CHECK_THROW(wst1(4," "),cipher_error);
    }
    TEST(TextNumberText) {
        CHECK_THROW(wst1(4,"SHBR234ET"),cipher_error);
    }
    TEST(TextSymbolText) {
        CHECK_THROW(wst1(4,"SBER!!!HT"),cipher_error);
    }

}

int main()
{
    return UnitTest::RunAllTests();
}

