#pragma once
#include "clsDate.h"


class clsUtility {

private:



public:

    enum  enCharType{smallLetter=1,capitalLetter=2,digit=3,mix=4};




    static void seed() {
        srand((unsigned)time(NULL));

    }



    static int randomNumber(int from,int to)
    {

        return rand()%(to-from+1)+from;
    }



    static char getRandomCharacter(enCharType CharType)
    {
        switch (CharType)
        {
            case enCharType::smallLetter:
            {
                return char(randomNumber(97, 122));
                break;
            }
            case enCharType::capitalLetter:
            {
                return char(randomNumber(65, 90));
                break;
            }

            case enCharType::digit:
            {
                return char(randomNumber(48, 57));
                break;
            }

            case enCharType::mix:
                return getRandomCharacter((enCharType)randomNumber(1,3));
            default:
                return char(randomNumber(97, 122));
                break;
        }
    }

    static std::string generateWord(enCharType charType,unsigned short nbrChar) {

        std::string word;
        for (short i=0;i<nbrChar;i++) {
            word+=getRandomCharacter(charType);
        }
        return word;
    }



    static std::string generateKey(enCharType charType,unsigned short charNumber,unsigned short nbrSlots) {

        std::string key;
        for (short i=0;i<nbrSlots;i++) {
            key+=generateWord(charType,charNumber)+"-";
        }
        return  key.substr(0,key.length()-1);

    }

    static void generateKeys(unsigned short nbrKeys,enCharType charType,unsigned short charNumber,unsigned short nbrSlots) {
        for (short i=0;i<nbrKeys;i++) {
            std::cout<<"Key["<<i<<"] : "<<generateKey(charType,charNumber,nbrSlots)<<endl;;
        }
    }



    static void swap(int& a,int& b) {
        const int temp = a;
        a=b;
        b=temp;
    }


    static void swap(double& a,double& b) {
        const double temp = a;
        a=b;
        b=temp;
    }

    static void swap(std::string& a,std::string& b) {
        const std::string temp = a;
        a=b;
        b=temp;
    }

    static void swap(clsDate& a,clsDate& b) {
        const clsDate temp = a;
        a=b;
        b=temp;
    }


    static void shuffleArray(int arr[],const unsigned short arrLength) {
        short index1,index2;
        for (short i=0;i<arrLength;i++) {
            index1=randomNumber(0,arrLength-1);
            index2=randomNumber(0,arrLength-1);
            swap(arr[index1],arr[index2]);
        }
    }

    static void shuffleArray(std::string arr[],const unsigned short arrLength) {
        short index1,index2;
        for (short i=0;i<arrLength;i++) {
            index1=randomNumber(0,arrLength-1);
            index2=randomNumber(0,arrLength-1);
            swap(arr[index1],arr[index2]);
        }
    }




    static void fillArrayWithRandomNumber(int arr[],unsigned short arrLength,unsigned short randomFrom,unsigned short randomTo) {

        for (short i=0;i<arrLength;i++) {
            arr[i]=randomNumber(randomFrom,randomTo);
        }
    }


    static void fillArrayWithRandomWords(std::string arr[],const unsigned short arrLength,const enCharType charType,const unsigned short wordLength) {
        for (short i=0;i<arrLength;i++) {
            arr[i]=generateWord(charType,wordLength);
        }
    }

    static void fillArrayWithRandomKeys(std::string arr[],const unsigned short arrLength,const enCharType charType,const unsigned short nbrChar,unsigned short nbrSlots) {
        for (short i=0;i<arrLength;i++) {
            arr[i]=generateKey(charType,nbrChar,nbrSlots);
        }
    }





    static std::string tabs(const unsigned short nbrTabs) {
        std::string tab="";
        for (short i=0;i<nbrTabs;i++) {
            tab+="\t";
        }
        return tab;
    }






    static std::string  encryptText(std::string Text,const  short EncryptionKey)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text;
    }

    static std::string  decryptText(std::string Text,const  short EncryptionKey)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }







};

