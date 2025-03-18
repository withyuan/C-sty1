#include<iostream>
class Log
{
public:
    enum Level{
        LevelError=0,LevelWarning,LevelInfo
    };
private:
    Level m_LogLevel=LevelInfo;  //  

public:
    
    void SetLevel(Level level){
        m_LogLevel = level;
    }
    void Warn(const char* message){
        if(m_LogLevel >= LevelWarning)
            std::cout << "[WARNING]:" << message << std::endl;
    }
    void Error(const char* message){
        if(m_LogLevel >= LevelError)
            std::cout << "[ERROR]:" << message << std::endl;
    }
    void Info(const char* message){
        if(m_LogLevel >= LevelInfo)
            std::cout << "[INFO]:" << message << std::endl;
    }
};

int main(){
    // 方式1：在栈上创建对象
    Log log1;
    log1.SetLevel(Log::LevelInfo);
    log1.Info("Hello!");
    
    // // 或者方式2：在堆上创建对象
    // Log* log1_ptr = new Log();
    // log1_ptr->SetLevel(Log::LogLevelInfo);
    // log1_ptr->Info("Hello!");
    // delete log1_ptr;  // 不要忘记释放内存

    std::cin.get();
    return 0;
}