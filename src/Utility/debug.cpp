#include "debug.h"


Debug Debug::m_instance = Debug();

Debug::Debug()
{
    initConsoleColors();
    seeDate(false);
    seeTitle(true);
    setFileLog("");
}

Debug::~Debug()
{

}

Debug& Debug::Instance()
{
    return m_instance;
}
void Debug::base(std::string pMessage)
{
    color(_CURRENT_TEXT_COLOR, _CURRENT_BACKGROUND_COLOR);
    bool dateTmp = _date;
    bool titleTmp = _title;
    seeDate(false);
    seeTitle(false);
    writeConsole("", pMessage);
    seeDate(dateTmp);
    seeTitle(titleTmp);
}
void Debug::info(std::string pMessage)
{
    color(_CURRENT_INFO_TEXT_COLOR, _CURRENT_INFO_BACKGROUND_COLOR);
    writeConsole("[INFO]", pMessage);
    write("Info", pMessage);
}
void Debug::warning(std::string pMessage)
{
    color(_CURRENT_WARNING_TEXT_COLOR, _CURRENT_WARNING_BACKGROUND_COLOR);
    writeConsole("[WARNING]", pMessage);
    write("Warning", pMessage);
}
void Debug::error(std::string pMessage)
{
    color(_CURRENT_ERROR_TEXT_COLOR, _CURRENT_ERROR_BACKGROUND_COLOR);
    writeConsole("[ERROR]", pMessage);
    write("Error", pMessage);
}
void Debug::debug(std::string pMessage)
{
    color(_CURRENT_DEBUG_TEXT_COLOR, _CURRENT_DEBUG_BACKGROUND_COLOR);
    writeConsole("[DEBUG]", pMessage);
    write("Debug", pMessage);
}
#ifdef _WIN32
void Debug::color(int pTextColor, int pBackgroundColor)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,getBackgroundColor(pBackgroundColor)*16+getTextColor(pTextColor));
}
#endif
#ifdef __linux__
void Debug::color(int pTextColor, int pBackgroundColor)
{
    std::cout << "\033[" << getTextColor(pTextColor) << ";" << getBackgroundColor(pBackgroundColor) << "m";
}
#endif
#ifdef __APPLE__
void Debug::color(int pTextColor, int pBackgroundColor)
{
    std::cout << "\033[" << getTextColor(pTextColor) << ";" << getBackgroundColor(pBackgroundColor) << "m";
}
#endif
void Debug::endLine(int pLenghtText)
{
    int len = 80 - (pLenghtText%80);
    for(int i = 0 ; i < len ; i++)
        std::cout << " ";
    color(_CURRENT_TEXT_COLOR, _CURRENT_BACKGROUND_COLOR);
}
void Debug::seeDate(bool pState)
{
    _date = pState;
}
void Debug::seeTitle(bool pState)
{
    _title = pState;
}
std::string Debug::getDate()
{
    time_t now = time(0);
    std::string dt = ctime(&now);
    dt.replace(dt.find("\n"), 1,"");
    return dt;
}
void Debug::setFileLog(std::string pFileName, int pType, bool pFileAppend)
{
    setFileName(pFileName);
    setFileType(pType);
    setFileAppend(pFileAppend);
}
void Debug::setFileAppend(bool pFileAppend)
{
    _fileAppend = pFileAppend;
}
void Debug::setFileName(std::string pFileName)
{
    _fileName = pFileName;
}
void Debug::setInfoColor(int pTextColor, int pBackgroundColor)
{
    if(isValideColor(pTextColor) && isValideColor(pBackgroundColor))
    {
        _CURRENT_INFO_TEXT_COLOR = pTextColor;
        _CURRENT_INFO_BACKGROUND_COLOR = pBackgroundColor;
    }

}
void Debug::setWarningColor(int pTextColor, int pBackgroundColor)
{
    if(isValideColor(pTextColor) && isValideColor(pBackgroundColor))
    {
        _CURRENT_WARNING_TEXT_COLOR = pTextColor;
        _CURRENT_WARNING_BACKGROUND_COLOR = pBackgroundColor;
    }
}
void Debug::setErrorColor(int pTextColor, int pBackgroundColor)
{
    if(isValideColor(pTextColor) && isValideColor(pBackgroundColor))
    {
        _CURRENT_ERROR_TEXT_COLOR = pTextColor;
        _CURRENT_ERROR_BACKGROUND_COLOR = pBackgroundColor;
    }
}
void Debug::setDebugColor(int pTextColor, int pBackgroundColor)
{
    if(isValideColor(pTextColor) && isValideColor(pBackgroundColor))
    {
        _CURRENT_DEBUG_TEXT_COLOR = pTextColor;
        _CURRENT_DEBUG_BACKGROUND_COLOR = pBackgroundColor;
    }
}
void Debug::setConsoleColor(int pTextColor, int pBackgroundColor)
{
    if(isValideColor(pTextColor) && isValideColor(pBackgroundColor))
    {
        _CURRENT_TEXT_COLOR = pTextColor;
        _CURRENT_BACKGROUND_COLOR = pBackgroundColor;
    }
}
void Debug::setFileType(int pFileType)
{
    if(pFileType == TXT || pFileType == CSV)
        _fileType = pFileType;
    else
        _fileType = TXT;
}
std::string &Debug::getFileName()
{
    return _fileName;
}
void Debug::write(std::string pTitle, std::string pMessage)
{
    if(getFileName().length() != 0)
    {
        std::ofstream file;
        if(_fileAppend)
            file.open(getFileName().c_str(), std::ios::out | std::ios::app);
        else
            file.open(getFileName().c_str(), std::ios::out | std::ios::trunc);
        if(file)
        {
            std::cout << _fileType << std::endl;
            if(_fileType == TXT)
            {
                file << "[" << pTitle << "] " << getDate() << " : " << pMessage << std::endl;
            }
            else if(_fileType == CSV)
            {
                file << pTitle << '\t' << getDate() << '\t' << pMessage << std::endl;
            }
            file.close();
        }
    }
}
void Debug::writeConsole(std::string pTitle, std::string pMessage)
{
    int len = pMessage.length();
    if(_title)
    {
        std::cout << pTitle << " ";
        len += pTitle.length() +1 ;
    }
    if(_date)
    {
        std::string date = getDate();
        std::cout << date << " ";
        len += date.length() + 1 ;
    }
    if(_title || _date)
    {
        std::cout << ": ";
        len +=2;
    }
    std::cout << pMessage;
    endLine(len);
}
void Debug::initConsoleColors()
{
    setInfoColor(BLACK, GREEN);
    setWarningColor(BLACK, YELLOW);
    setErrorColor(BLACK, RED);
    setDebugColor(WHITE, BLACK);
    setConsoleColor(WHITE, BLACK);
}
void Debug::log(const int pType, const std::string & fmt, ...)
{
    int size = 100;
    std::string str;
    va_list ap;
    while(1)
    {
        str.resize(size);
        va_start(ap, fmt);
        int n = vsnprintf((char *)str.c_str(), size, fmt.c_str(), ap);
        va_end(ap);
        if (n > -1 && n < size)
        {
            str.resize(n);
            break;
        }
        if (n > -1)
            size = n + 1;
        else
            size *= 2;
    }
    if(pType == LOG_INFO)
    {
        info(str);
    } else if(pType == LOG_WARNING)
    {
        warning(str);
    } else if(pType == LOG_WARNING)
    {
        error(str);
    } else if(pType == LOG_WARNING)
    {
        debug(str);
    } else
    {
        base(str);
    }
}
void Debug::log(const std::string & fmt, ...)
{
    int size = 100;
    std::string str;
    va_list ap;
    while(1)
    {
        str.resize(size);
        va_start(ap, fmt);
        int n = vsnprintf((char *)str.c_str(), size, fmt.c_str(), ap);
        va_end(ap);
        if (n > -1 && n < size)
        {
            str.resize(n);
            break;
        }
        if (n > -1)
            size = n + 1;
        else
            size *= 2;
    }
    base(str);
}
void Debug::resetColor()
{
    initConsoleColors();
}

bool Debug::isValideColor(int pColor)
{
    if(pColor >= 0 && pColor <= 7)
        return true;
    return false;
}
#ifdef _WIN32
int Debug::getTextColor(int pColor)
{
    switch(pColor)
    {
    case BLACK :
        return 0;
        break;
    case BLUE :
        return 9;
        break;
    case GREEN :
        return 10;
        break;
    case CYAN :
        return 11;
        break;
    case RED :
        return 12;
        break;
    case MAGENTA :
        return 13;
        break;
    case YELLOW :
        return 14;
        break;
    case WHITE :
        return 15;
        break;
    default :
        return -1;
    }
}
int Debug::getBackgroundColor(int pColor)
{
    return getTextColor(pColor);
}
#endif
#ifdef __linux__
int Debug::getTextColor(int pColor)
{
    switch(pColor)
    {
    case BLACK :
        return 30;
        break;
    case BLUE :
        return 34;
        break;
    case GREEN :
        return 32;
        break;
    case CYAN :
        return 36;
        break;
    case RED :
        return 31;
        break;
    case MAGENTA :
        return 35;
        break;
    case YELLOW :
        return 33;
        break;
    case WHITE :
        return 37;
        break;
    default :
        return -1;
    }
}
int Debug::getBackgroundColor(int pColor)
{
    return getTextColor(pColor) + 10;
}
#endif
#ifdef __APPLE__
int Debug::getTextColor(int pColor)
{
    switch(pColor)
    {
    case BLACK :
        return 30;
        break;
    case BLUE :
        return 34;
        break;
    case GREEN :
        return 32;
        break;
    case CYAN :
        return 36;
        break;
    case RED :
        return 31;
        break;
    case MAGENTA :
        return 35;
        break;
    case YELLOW :
        return 33;
        break;
    case WHITE :
        return 37;
        break;
    default :
        return -1;
    }
}
int Debug::getBackgroundColor(int pColor)
{
    return getTextColor(pColor) + 10;
}
#endif
bool Debug::isSeeDate() const
{
    return _date;
}
bool Debug::isSeeTitle() const
{
    return _title;
}
