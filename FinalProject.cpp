#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int opCode(string);
int rs(string);
int rt(string);
int rd(string);
int shamt(string);
int func(string);
int lastSixteen(string);
void displayRTypeAdd(int, int, int);
void displayRTypeSub(int, int, int);
void displayLoadWord(int, int, int);
void displayStoreWord(int, int, int);
void displayAddImmediate(int, int, int);
void displayBranchNotEqual(int, int);
void displayBranchEqual(int, int);
void displayAnd(int, int, int);
void displayOr(int, int, int);



int main()
{
    string temp1, temp2, temp3, temp4, temp5, temp6;
    int opcode, rsCode, rtCode, rdCode, shamtCode, funcCode, sixteenBits;
    string hexDecimal;
    cout << "Please enter a hexadecimal number. If you enter a letter, " <<
        "please make sure it is no greater than f." << endl;
    cin >> hexDecimal;
    string binaryString;

    cout << endl << endl;

    for(int i = 0; i < 8; i++)
    {
        switch(hexDecimal[i])
        {
            case '0':
            {
                binaryString += "0000";
                break;
            }
            case '1':
            {
                 binaryString += "0001";
                break;
            }
            case '2':
            {
                 binaryString += "0010";
                break;
            }
            case '3':
            {
                 binaryString += "0011";
                break;
            }
            case '4':
            {
                 binaryString += "0100";
                break;
            }
            case '5':
            {
                 binaryString +="0101";
                break;
            }
            case '6':
            {
                 binaryString += "0110";
                break;
            }
            case '7':
            {
                 binaryString += "0111";
                break;
            }
            case '8':
            {
                 binaryString +="1000";
                break;
            }
            case '9':
            {
                 binaryString +="1001";
                break;
            }
            case 'A':
            {
                 binaryString += "1010";
                break;
            }
            case 'B':
            {
                 binaryString +="1011";
                break;
            }
            case 'C':
            {
                 binaryString += "1100";
                break;
            }
            case 'D':
            {
                 binaryString +="1101";
                break;
            }
            case 'E':
            {
                binaryString += "1110";
                break;
            }
            case 'F':
            {
                 binaryString += "1111";
                break;
            }
            default:
            {
                cout << "This is an invalid digit" << endl;
                break;
            }
        }
    }

    cout <<"The Binary equivalent is: " << binaryString << endl << endl;

    temp1 = binaryString.substr(0,6);
    opcode = opCode(temp1);
    if(opcode == 0) //This will determine if this is an R type
    {
        temp2 = binaryString.substr(6,5);
        rsCode = rs(temp2);
        temp3 = binaryString.substr(11,5);
        rtCode = rt(temp3);
        temp4 = binaryString.substr(16, 5);
        rdCode = rd(temp4);
        temp5 = binaryString.substr(21, 5);
        shamtCode = shamt(temp5);
        temp6 = binaryString.substr(26, 6);
        funcCode = func(temp6);

        if(funcCode == 32)
        {
            displayRTypeAdd(rsCode, rtCode, rdCode);
        }

        else if(funcCode == 34)
        {
            displayRTypeSub(rsCode, rtCode, rdCode);
        }

        else if(funcCode == 37)
        {
            displayOr(rsCode, rtCode, rdCode);
        }

        else if(funcCode == 36)
        {
            displayAnd(rsCode, rtCode, rdCode);
        }
    }

    else if(opcode == 35) //This is load word
    {
        temp2 = binaryString.substr(6,5);
        rsCode = rs(temp2);
        temp3 = binaryString.substr(11,5);
        rtCode = rt(temp3);
        temp4 = binaryString.substr(16, 16);
        sixteenBits = lastSixteen(temp4);

        displayLoadWord(rsCode, rtCode, sixteenBits);
    }

    else if(opcode == 43) //This is store word
    {
        temp2 = binaryString.substr(6,5);
        rsCode = rs(temp2);
        temp3 = binaryString.substr(11,5);
        rtCode = rt(temp3);
        temp4 = binaryString.substr(16, 16);
        sixteenBits = lastSixteen(temp4);

        displayStoreWord(rsCode, rtCode, sixteenBits);
    }

    else if(opcode == 8) //This is add immediate
    {
        temp2 = binaryString.substr(6,5);
        rsCode = rs(temp2);
        temp3 = binaryString.substr(11,5);
        rtCode = rt(temp3);
        temp4 = binaryString.substr(16, 16);
        sixteenBits = lastSixteen(temp4);

        displayAddImmediate(rsCode, rtCode, sixteenBits);
    }

    else if(opcode == 5) //This is branch not equal word
    {
        temp2 = binaryString.substr(6,5);
        rsCode = rs(temp2);
        temp3 = binaryString.substr(11,5);
        rtCode = rt(temp3);
        temp4 = binaryString.substr(16, 16);
        sixteenBits = lastSixteen(temp4);

        displayBranchNotEqual(rsCode, rtCode);
    }

    else if(opcode == 4) //This is branch equal
    {
        temp2 = binaryString.substr(6,5);
        rsCode = rs(temp2);
        temp3 = binaryString.substr(11,5);
        rtCode = rt(temp3);
        temp4 = binaryString.substr(16, 16);
        sixteenBits = lastSixteen(temp4);

        displayBranchEqual(rsCode, rtCode);
    }

    cout << endl << endl;
    //cout << opcode << endl;
    //cout << rsCode << endl;
    //cout << rtCode << endl;
    //cout << rdCode << endl;
    //cout << funcCode << endl;
    //cout << sixteenBits << endl;

    return 0;

}

int opCode(string temp1)
{

    int total = 0;
    int counter = 0;
    for(int i = temp1.length() - 1; i >= 0; i--)
    {
        if(temp1[i] == '1')
        {
            total += pow(2, counter);
        }
        counter++;
    }

    return total;
}

int rs(string temp2)
{
    int total = 0;
    int counter = 0;
    for(int i = temp2.length() - 1; i >= 0; i--)
    {
        if(temp2[i] == '1')
        {
            total += pow(2, counter);
        }
        counter++;
    }

    return total;
}

int rt(string temp3)
{
    int total = 0;
    int counter = 0;
    for(int i = temp3.length() - 1; i >= 0; i--)
    {
        if(temp3[i] == '1')
        {
            total += pow(2, counter);
        }
        counter++;
    }

    return total;
}

int rd(string temp4)
{
   int total = 0;
   int counter = 0;
   for(int i = temp4.length() - 1; i >= 0; i--)
   {
       if(temp4[i] == '1')
       {
           total += pow(2, counter);
       }
       counter++;
   }
   return total;
}

int shamt(string temp5)
{
   int total = 0;
   int counter = 0;
   for(int i = temp5.length() - 1; i >= 0; i--)
   {
       if(temp5[i] == '1')
       {
           total += pow(2, counter);
       }
       counter++;
   }
   return total;
}

int func(string temp6)
{
   int total = 0;
   int counter = 0;
   for(int i = temp6.length() - 1; i >= 0; i--)
   {
       if(temp6[i] == '1')
       {
           total += pow(2, counter);
       }
       counter++;
   }
   return total;
}

int lastSixteen(string temp4)
{
    int total = 0;
    int counter = 0;
   for(int i = temp4.length() - 1; i >= 0; i--)
   {
       if(temp4[i] == '1')
       {
           total += pow(2, counter);
       }
       counter++;
   }
   return total;
}


void displayRTypeAdd(int rsCode, int rtCode, int rdCode)
{
    cout << "This is an add instruction. " << endl << endl;
    cout << "Your rs is " << rsCode << endl;
    cout << "Your rt is " << rtCode << endl;
    cout << "Your rd is " << rdCode << endl << endl;
    cout << "add $" << rdCode << ", $" << rsCode << ", $" << rtCode << endl;
}

void displayRTypeSub(int rsCode, int rtCode, int rdCode)
{
    cout << "This is a sub instruction." << endl << endl;
    cout << "Your rs is " << rsCode << endl;
    cout << "Your rt is " << rtCode << endl;
    cout << "Your rd is " << rdCode << endl << endl;
    cout << "sub $" << rdCode << ", $" << rsCode << ", $" << rtCode << endl;
}

void displayAnd(int rsCode, int rtCode, int rdCode)
{
    cout << "This is an AND instruction." << endl << endl;
    cout << "Your rs is " << rsCode << endl;
    cout << "Your rt is " << rtCode << endl;
    cout << "Your rd is " << rdCode << endl << endl;
    cout << "and $" << rdCode << ", $" << rsCode << ", $" << rtCode << endl;
}

void displayOr(int rsCode, int rtCode, int rdCode)
{
    cout << "This is an OR instruction." << endl << endl;
    cout << "Your rs is " << rsCode << endl;
    cout << "Your rt is " << rtCode << endl;
    cout << "Your rd is " << rdCode << endl << endl;
    cout << "or $" << rdCode << ", $" << rsCode << ", $" << rtCode << endl;
}

void displayAddImmediate(int rsCode, int rtCode, int sixteenBits)
{
    cout << "This is an add immediate instruction." << endl << endl;
    cout << "Your rs is " << rsCode << endl;
    cout << "Your rt is " << rtCode << endl;
    cout << "Your constant is " << sixteenBits << endl << endl;
    cout << "addi $" << rtCode << ", $" << rsCode << ", " << sixteenBits;
}

void displayStoreWord(int rsCode, int rtCode, int sixteenBits)
{
    cout << "This is a store word instruction." << endl << endl;
    cout << "Your rs is " << rsCode << endl;
    cout << "Your rt is " << rtCode << endl;
    cout << "Your constant is " << sixteenBits << endl << endl;
    cout << "sw $" << rtCode << ", " << sixteenBits << "($" << rsCode << ")" << endl;
}

void displayLoadWord(int rsCode, int rtCode, int sixteenBits)
{
    cout << "This is a load word instruction." << endl << endl;
    cout << "Your rs is " << rsCode << endl;
    cout << "Your rt is " << rtCode << endl;
    cout << "Your constant is " << sixteenBits << endl << endl;
    cout << "lw $" << rtCode << ", " << sixteenBits << "($" << rsCode << ")" << endl;
}

void displayBranchEqual(int rsCode, int rtCode)
{
    cout << "This is a branch equal instruction." << endl;
    if(rsCode != rtCode)
    {
        cout << "The rs, " << rsCode << ", does not equal the rt, " << rtCode << "." << endl;
    }

    else
    {
        cout << "The rs, " << rsCode << ", equals the rt, " << rtCode << "." << endl;
    }
}

void displayBranchNotEqual(int rsCode, int rtCode)
{
    cout << "This is a branch not equal instruction." << endl;
    if(rsCode != rtCode)
    {
        cout << "The rs, " << rsCode << ", does not equal the rt, " << rtCode << "." << endl;
    }

    else
    {
        cout << "The rs, " << rsCode << ", equals the rt, " << rtCode << "." << endl;
    }
}

