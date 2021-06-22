    #include <string>
    #include <iostream>
    #include <map>
    #include <stdlib.h>

    using namespace std;

    
    string fractionToDecimal(int numerator, int denominator) {
        long long      quotiennt = 0, remainder = numerator, ldenominator = denominator;
        map<int, int>   mymap;
        string  ret;
        if (numerator == 0)
            return "0";

        if(numerator<0 && denominator>0){
            ret = "-";
            remainder = -remainder;
        }else if (numerator>0 && denominator<0){
            ret = "-";
            ldenominator = -denominator;
        }else if (numerator<0 && denominator<0){
            remainder = -remainder;
            ldenominator = -ldenominator;
        }

        bool    b = true;
        while(true){
            quotiennt = remainder / ldenominator;    //商 0
            remainder = remainder % ldenominator;    //余 2
            ret += to_string(quotiennt);
            if (b && remainder){
                ret += ".";
                b = false;
            }


            if (remainder == 0)//余数为0  得到全部小数 return
                break;

            if (mymap.find(remainder) != mymap.end()){//有循环
                int     preindex = mymap[remainder];
                int     postindex = ret.length();
                string  str1(ret, 0, preindex);
                string  str2(ret, preindex, postindex-preindex);
                ret = str1 + "(" + str2 + ")";
                break;
            }else{
                mymap[remainder] = ret.length(); // 2 
                remainder = 10 * remainder;
            }
        }

        return ret;
    }

    int main(int argc, char** argv){
        string ret = fractionToDecimal(atoi(argv[1]), atoi(argv[2]));
        cout << ret << '\n';
        return 0;
    }