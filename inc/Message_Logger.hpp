#include<fstream>
#include<iostream>
#include<string.h>
#include<sstream>

class Log_stream{
   
    private:
    int maxFileSize;
    int stableLineCount;
    int currentLineCount;
    std::fstream file;
    std::string single_log;
    std::string filePath;


    public:
    Log_stream(const std::string&path,const int& maxSize);

    template<typename T>
    Log_stream& operator<<(const T& message);
    

};

template<typename T>
Log_stream& Log_stream:: operator<<(const T& message){
    if(file.tellp()+sizeof(message)>(maxFileSize<<10)){//maxFilesize is in Mbs while tellp return bytes
        file.close();
        file.open(filePath,std::fstream::out);
    }

    if(file)
        file<<message;
    
    if(currentLineCount == stableLineCount){
        file.flush();

        currentLineCount = 0;
    }
    else    
        currentLineCount++;
    
    return *this;
}

