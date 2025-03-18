#include <iostream>
#include <string>
#include<stdlib.h>
#include "test2.h"
#include <vector>    
#include <unordered_map>
#define WAIT std::cin.get()


class Ex{
public:
 Ex(){
    std::cout<<"Ex create"<<std::endl;
 }
 Ex(int x){
    std::cout<<"Ex create with"<<x<<std::endl;
 }


};
template<typename T>
void Print(T value){ 
    std::cout<<value<<std::endl;

}



class Entity{
private:
    int m_x,m_y;
    std::string m_name;
    mutable int m_age;
    Ex ex;
public:
    Entity():m_x(0),m_y(0),m_name("unname"),m_age(2),ex(){
    }
    Entity(int x,int y):m_x(x),m_y(y){}
    Entity(int x):m_x(x){}
    Entity(const std::string& name):m_name(name){}
    ~Entity(){
        std::cout<<"Entity destroy"<<std::endl;
    }
    int getX ()const{
        return m_x;
    }
    const std::string& getName()const{
        return m_name;
    }
    void setX(int x){ 
        m_x=x;
    }


};


class ScopedPtr{

private:
    Entity* m_ptr;
public:
    ScopedPtr(Entity* entity):m_ptr(entity){}
    ~ScopedPtr(){
        delete m_ptr;
    }
    Entity* operator->(){
        return m_ptr;
    }
    ScopedPtr(const ScopedPtr&) = delete;


};



int fun1(int day){
    if(day==11){
        return 1;
    }
    return 2*(fun1(day+1)+1);
}
void printStr( std::string& str){
    str+="awe";
    std::cout<<str<<std::endl;
}
void PrintEntity( const Entity& e){
 
    std::cout<<e.getX()<<std::endl;
    std::cout<<e.getName()<<std::endl;
    
}

struct Vector2{

float x,y;
Vector2(float x,float y):x(x),y(y){}

    Vector2 add(const Vector2& other) const{
        return Vector2(x+other.x,y+other.y);
    }
    Vector2 operator+(const Vector2& other) const{
        return add(other);
    }


};
std::ostream& operator<<(std::ostream& stream, const Vector2& vector) {
    stream << "Vector2: (" << vector.x << ", " << vector.y << ")";
    return stream;
};
struct Vertex {
    float x,y,z;
    Vertex(float x ,float y,float z):x(x),y(y),z(z){}
    Vertex(const Vertex& other)
        :x(other.x),y(other.y),z(other.z){
            std::cout<<"copy"<<std::endl;
        }
};
std::ostream& operator<<(std::ostream& stream, const Vertex& vector) {
    stream << "Vector3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
    return stream;

}
int main(){
     std::vector<std::string> strings;
     strings.push_back("a");
     strings.push_back("b");
    //  for(std::vector<std::string>::iterator it = strings.begin();it!=strings.end();it++){
    //     std::cout<<*it<<std::endl;
    //  }
     for(auto it = strings.begin();it!=strings.end();it++){
        std::cout<<*it<<std::endl;
     }
     
     std::unordered_map<std::string,int> map ={{"a",1},{"b",2},{"c",3}};
     auto& maa=map;
     std::cout<<maa["a"]<<std::endl;
    // Entity e1;
    // Entity e2=22;
    // Entity e3=std::string("ssss");
    // PrintEntity(e2);
    // PrintEntity(e3);
    // Vector2 v(0.2f,0.3f);
    // Entity e1;
    // Vector2* v=new Vector2(0.2f,0.3f);
    // v->add(Vector2(2,3));
    // e1.getX();
    // Entity* e2=new Entity("xxxx");
    // {
    //     ScopedPtr e4(new Entity());
    // }
    // size_t offset=(size_t)&((Vector3*)nullptr)->z;

    // std::cout<<offset<<std::endl;
    std::vector<Vertex> vertexs;
    vertexs.reserve(10);
    vertexs.emplace_back(1,2,3);
    vertexs.push_back({4,5,6});
    // vertexs.push_back({7,8,9});
    // for(int i ;i<vertexs.size();i++){
    //     std::cout<<vertexs[i]<<std::endl;
    // }
    // vertexs.erase(vertexs.begin()+1);
    
    // for(Vertex& v:vertexs){
    //     std::cout<<v<<std::endl;
    // }

        // 方法1：直接通过索引访问
        Vertex& v1 = vertexs[0];
    
        // 方法2：使用 at() 方法（带边界检查）
        Vertex& v2 = vertexs.at(0);
    
    std::cout<<v1<<std::endl;
    std::cout<<v2<<std::endl;
    WAIT;
    // delete v;
    // delete e2;
    // int a =e1.getX()==1?1:2;
    // std::cout<<a<<std::endl;
    // PrintEntity(e1);
    // Entity e2(22,322);
    // PrintEntity(e2);

//    Multiply(1,3);
//     Multiply(2,3);
//    Multiply(3,3);
// //    Log("hwwwwwwwww") ;
//     using namespace std::string_literals;
//     const wchar_t* name =L"aaaa";
//     const char* name2 = R"(
//         r
//         a
//         v
//         c
//         d
//         )"; 
//     std::cout<<name2<<std::endl;
//     std::wcout<<name<<std::endl;
//    int i =0;
      // 1. wchar_t 类型的宽字符串
//       const wchar_t* str1 = L"你好";  // L 前缀表示宽字符串
    
//       // 2. UTF-16 字符串
//       const char16_t* str2 = u"你好";  // u 前缀
      
//       // 3. UTF-32 字符串
//       const char32_t* str3 = U"你好";  // U 前缀
      
//       // 4. 宽字符串输出
//       std::locale::global(std::locale(""));  // 设置本地化
//       std::wcout.imbue(std::locale());      // 设置输出流
//       std::wcout << str2 << std::endl;
// //     int i=0；
// const int MAX_VALUE=100;
// const int* a=new int;
// int* const b=new int;
// *b=10;
// std::cout<<*b<<std::endl;
// // *a=10;
// a=(int*)&MAX_VALUE;
// std::cout<<*a<<std::endl;
 



//     while(i<5){
//         continue;
//         break;
        
// }
    // std::string str = "Hello";
    
    // std::string str="你好啊，我是苏李磊";
    // bool a=str.find(",")!=std::string::npos;
    // std::cout<<a<<std::endl;
    // std::cout << str.length() << std::endl;
    // std::cout << str.substr() << std::endl;
    // std::cout << str.size() << std::endl;
    // printStr(str);
//    std::cin.get();



    return 0;
}


