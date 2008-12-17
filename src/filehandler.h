#ifndef QOM_FILEHANDLER
#define QOM_FILEHANDLER

#include <QTcpSocket>

#include "messenger.h"
#include "ipobjects.h"

class FileHandler : public QObject
{
    Q_OBJECT
    
public:
    FileHandler() : QObject() { m_id = 0 ; } ;
    ~FileHandler() { } ;
    
    // UDP
    void sendFilesRequest(QStringList, Member*, QString);
    
    // usually shouldn't be called from outside, see the .cpp for details
    void sendDirectoryRequest(QString, Member*);
    
    inline void sendFilesRequest(QString filename, Member* to, QString message="") { return sendFilesRequest(QStringList(filename), to, message); } ;
    
    // TCP
    //void sendFiles(QStringList);
    //void sendDirectory(QString);
    
signals:
    /**
     * Emitted every time a certain number of bytes are transmitted
     * QString is the filename
     * int is the bytes written till now
     * int is the total bytes
     */
    void updateSend(QString, int, int);
    void finishedSending(QString);
    
private:
    int m_id;
    int nextId() { return m_id++ ; } ;
    QString formatFileData(QString);
};

FileHandler* fileHandler();

#endif