#include<iostream>
int main()
{
    int arr[5];

    // arr[2]=100;
    // int* pr=arr;
    // std::cout << arr[2] << std::endl;
    // std::cout << *(int*)((char*)arr+8) << std::endl;

    // std::cout << *(pr+2)<< std::endl;
    int* anchor = new int [5];
    for(int i= 0;i<5;i++){
        anchor[i] = 2;
        arr[i]=2; 
    }
     

    std::cout << sizeof(arr)/sizeof(int) << std::endl;        
    std::cout << sizeof(*anchor)/sizeof(int) << std::endl;      
    delete [] anchor;
    std::cin.get();
}