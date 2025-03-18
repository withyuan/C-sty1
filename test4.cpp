#include <iostream>
#include <array>
#include<vector>
#include<algorithm>
#define LOG(x) std::cout << x << std::endl;


int s_value = 8;
void ind(int* a){
    (*a)++;
}
void inda(int& a){
    a++;

}
struct Player{
public:
    int x ,y,speed ;
    void move(int right,int up){
        x+=right*speed;
        y+=up*speed;
        std::cout << "移动了 " << x << "," << y << std::endl;  
    }


};



class Singleton
{
private:
public:
    static Singleton& Get(){
       static Singleton s_Instance;
        return s_Instance;
    }
    void Print(){
        std::cout << "hello" << std::endl;
    }

};

//斐波那契 数列

int fun1(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1 || n == 2) {  // 前两个数都是1
        return 1;
    }
    return fun1(n-1) + fun1(n-2);
}

int fun2(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1 || n == 2) {  // 前两个数都是1
        return 1;
    }
    int* dp=new int[n+1];
    dp[1]=dp[2]=1;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
 int result = dp[n];
    delete[] dp;               // 释放内存
    return result;
}




void ForEache(std::vector<int>& values,std::function<void(int)>  fun)
{
    for(int i=0;i<values.size();i++){
        fun(values[i]);
    }
}


int main() {
    // int var = 9;
    // int* ptr = &var;
    // *ptr =10;
    // LOG(var);
    // char* buffer =new char[8];
    // memset(buffer,'a',8);
    // LOG(buffer);
    // delete[] buffer;
    // int x=2;
    // int y=3;
    // int* ref=&x;
    // *ref=1;
    // ref=&y;
    // *ref=6;
    // Player player;
    // player.x=2;
    // player.y=3;
    // player.speed=2;
    // player.move(1,2);
    // LOG(s_value)
    // Singleton::Get().Print();
    // std::cout << fun1(5) << std::endl;  // 输出第

    // std::array<int,5> arr={1,2,3,4,5};
    // std::sort(arr.begin(),arr.end());
     std::vector<int> vec={11,2,3,4,5};
     int multiplier = 2;
     ForEache(vec,[multiplier](int value){
        std::cout<<value*multiplier<<std::endl;
     });
    auto  a=std::find_if(vec.begin(),vec.end(),[](int value){
        return value>100;
     });

     std::cout<<*vec.begin()<<std::endl;
     std::cout<<*vec.end()<<std::endl;
        std::cout<<*a<<std::endl;
   
    std::cin.get();
    return 0;
}