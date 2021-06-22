#include <string>
using namespace std;
/*修改一个文件后 再提交到暂存区 版本库*/
bool isLongPressedName(string name, string typed) {
        int index1 = 0, index2 = 0;
        while(index1 < name.length() || index2 < typed.length()){
            if (name[index1] == typed[index2]){
                index1++;
                index2++;
            }else if(index1 > 0 && typed[index2] == name[index1 - 1]){
                index2++;
            }else{
                return false;
            }
        }
        return true;
    }