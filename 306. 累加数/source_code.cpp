/*
 * @Author: Mayc
 * @Date: 2021-01-17 12:51:37
 * @LastEditTime: 2021-01-17 12:51:45
 * @FilePath: \undefinedd:\VSC++&GO\LeetCode\306. 累加数\source_code.cpp
 * @这是一个漂亮的注释头
 */
class Solution {
public:
    string getSum(string& num1,string& num2){           //两个字符串表示的数字相加的算法，最后返回一个字符串sum
        int val,flag=0,len1=num1.size(),len2=num2.size();
        string sum;
        while(len1||len2){          //字符串相加，从个位数到百位，千位，万位
            int val=0;          //每一位数的和
           if(len1>0) {val+=num1[len1-1]-'0'; len1--;}
            if(len2>0){val+=num2[len2-1]-'0'; len2--;}
            sum+=to_string((val+flag)%10);
            flag=(val+flag)/10;
        }
        if(flag)sum+="1";   //最后的进位要加上去
        reverse(sum.begin(),sum.end());
        return sum;
    }
    bool dfs(string& num1,string& num2,string& num3){       //num1,num2相加是否等于后面的数字，同时探索到最后一个数字
        if(num3.size()==0)return true;
        string sum=getSum(num1,num2);
        for(int i=1;i<=num3.size();i++){
            string str=num3.substr(0,i), tem=num3.substr(i);
            if(str==sum&&dfs(num2,sum,tem))return true;  //三个数字分别为num2,sum,tem
            if(num3[0]=='0')break;       //"0"在首位那么跳过
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
       if(num.size()<3)return false;
        int size=num.size();
        for(int i=1;i<size-1;i++){  
             string num1=num.substr(0,i);    //先获得三个数字，i从1开始，就是获得三个个位数
          for(int j=i+1;j<size;j++){
               //c++的substr函数是string.substr(index,len)  len表示切割的长度。 如s=“0123456"  s.substr(4)="456"
              string num2=num.substr(i,j-i);
              string num3=num.substr(j);
              if(dfs(num1,num2,num3))return true;
              if(num[i]=='0')break;
          }
            if(num[0]=='0')break;
        }
        return false;
    }
    
};