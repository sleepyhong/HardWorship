#ifndef CSONG_H
#define CSONG_H

#include <QString>

#include <vector>

class MainWindow;

class CSong
{
public:
    CSong(const QString& name);
    ~CSong();

    /** Default contructor disabled */
    CSong() = delete;
    /** Copy constructor disabled */
    CSong(const CSong&) = delete;
    /** Assignment Operator disabled */
    void operator=(const CSong&) = delete;

    /** Get the title of the song
     * \return the title of the song */
    QString GetName() {return mName;}
    /** Set the title of the song
     * \param titel of the song */
    void SetName(QString name) {mName = name;}

    /** Get the shared pointer to the main window
     * \return the pointer to the main window */
    QString GetDirectory() {return mDirectory;}
    /** Set the shared pointer to the main window
     * \param the pointer to the main window */
    void SetDirectory(QString directory) {mDirectory = directory;}

    /** Get the lyrics of the song
     * \return vector of lyrics */
    std::vector<QString> GetLyrics() {return mLyrics;}

    void InitializeLyrics();

private:
    QString mName;  // title of the song
    std::vector<QString> mLyrics;

    QString mDirectory;
};

#endif // CSONG_H
