#include<../inc/Message_Logger.hpp>

Log_stream::Log_stream(const std::string&path,const int& maxSize) : filePath(path),maxFileSize(maxSize){
    file.open(filePath,std::fstream::out);
    if(!file.is_open()){
        std::cout<<"File not Open"<<std::endl;
    }   
    stableLineCount = 5;
    currentLineCount = 0;
}

