#ifndef DEBUG_H
#define DEBUG_H

#include <ctime>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdarg.h>
#ifdef _WIN32
#include <windows.h>
#endif
// Singleton
/*
    Pour l'appeler :
    Debug& ptr = Debug::Instance();
*/
class Debug
{
public:
    enum Colors
    {
        BLACK=0,
        BLUE=1,
        GREEN=2,
        CYAN=3,
        RED=4,
        MAGENTA=5,
        YELLOW=6,
        WHITE=7
    };
    enum FileType
    {
        TXT = 0,
        CSV = 1
    };
    enum LogType
    {
        LOG_INFO,
        LOG_WARNING,
        LOG_ERROR,
        LOG_DEBUG
    };
    static Debug& Instance();
    void log(const std::string & fmt_str, ...);
    void log(const int pType, const std::string & fmt_str, ...);
    void seeDate(bool pState);
    void seeTitle(bool pState);
    bool isSeeDate() const;
    bool isSeeTitle() const;
    void setFileAppend(bool pFileAppend);
    void setFileLog(std::string pFileName, int pType = 0, bool pFileAppend = true);
    void setFileName(std::string pFileName);
    void setFileType(int pFileType);
    void setInfoColor(int pTextColor,int pBackgroundColor);
    void setWarningColor(int pTextColor,int pBackgroundColor);
    void setErrorColor(int pTextColor,int pBackgroundColor);
    void setDebugColor(int pTextColor,int pBackgroundColor);
    void setConsoleColor(int pTextColor,int pBackgroundColor);
    void resetColor();
    std::string &getFileName();

private:
    int _CURRENT_INFO_TEXT_COLOR;
    int _CURRENT_INFO_BACKGROUND_COLOR;

    int _CURRENT_WARNING_TEXT_COLOR;
    int _CURRENT_WARNING_BACKGROUND_COLOR;

    int _CURRENT_ERROR_TEXT_COLOR;
    int _CURRENT_ERROR_BACKGROUND_COLOR;

    int _CURRENT_DEBUG_TEXT_COLOR;
    int _CURRENT_DEBUG_BACKGROUND_COLOR ;

    int _CURRENT_TEXT_COLOR;
    int _CURRENT_BACKGROUND_COLOR;

    bool _date;
    bool _title;
    bool _fileAppend;
    int _fileType;
    std::string _fileName;
    void base(std::string pMessage);
    void info(std::string pMessage);
    void warning(std::string pMessage);
    void error(std::string pMessage);
    void debug(std::string pMessage);
    std::string getDate();
    void initConsoleColors();
    void color(int pTextColor, int pBackgroundColor);
    void endLine(int pSizeMessage);
    void write(std::string pTitle, std::string pMessage);
    void writeConsole(std::string pTitle, std::string pMessage);
    bool isValideColor(int pColor);
    int getTextColor(int pColor);
    int getBackgroundColor(int pColor);
    static Debug m_instance;
    Debug();
    ~Debug();
};
#endif
