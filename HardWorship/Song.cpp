#include "Song.h"
#include "MainWindow.h"

#include <QFile>
#include <QTextStream>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>
#include <QDomNodeList>
#include <QDomAttr>

using namespace std;

CSong::CSong(const QString& name)
{
    // Initialize the name of the song
    this->SetName(name);

    InitializeLyrics();
}

CSong::~CSong()
{
}

void CSong::InitializeLyrics()
{
    // Remove previous lyrics
    mLyrics.clear();

    QDomDocument song;

    // Initialize lyrics of the song
    QFile file(mDirectory + "/songs/" + mName + ".xml");
    if (file.open(QFile::ReadOnly | QFile::Text))
    {
        song.setContent(&file);

        // <song> is a root
        QDomElement root = song.documentElement();
        // <song>'s children such as <verse> <chorus> and <bridge>
        QDomNodeList lyricTypes = root.childNodes();

        for (int count = 0; count < lyricTypes.size(); ++count)
        {
            QDomNode lyricType = lyricTypes.at(count);
            // Inserting types first
            mLyrics.push_back(lyricType.toElement().tagName().toUpper());

            // Inserting number of types
            if (lyricType.hasAttributes())
            {
                mLyrics[count] += " " + lyricType.toElement().attributeNode("num").value();
            }
            mLyrics[count] += "\n";

            // Inserting lyrics
            QDomNodeList lyrics = lyricType.childNodes();
            for (int num = 0; num < lyrics.size(); ++num)
            {
                mLyrics[count] += lyrics.at(num).toElement().text() + "\n";
            }
        }

        file.close();
    }
}
