/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数。
*/

//快速幂算法
class Solution {
public:

    double pow(double x,int n){
        if(n == 0)
            return 1;
        if(n % 2 == 1){
            return x * pow(x,n-1);
        }else{
            double temp = pow(x, n / 2);
            return temp * temp;
        }
    }
    double myPow(double x, int n) {
        if(n < 0){
            return 1.0 / pow(x,-n);
        }else{
            return pow(x,n);
        }
    }
};