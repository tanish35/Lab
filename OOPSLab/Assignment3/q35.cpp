#include <iostream>
using namespace std;

class Artist
{
    string name;
    string topSong;

public:
    Artist(string name, string topSong)
    {
        this->name = name;
        this->topSong = topSong;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Top Song: " << topSong << endl;
    }
    virtual ~Artist() = 0;
};

Artist::~Artist()
{
    cout << "Artist Destructor" << endl;
}

class LanaDelRey : public Artist
{
    string album;

public:
    LanaDelRey(string name, string topSong, string album) : Artist(name, topSong)
    {
        this->album = album;
    }
    void display()
    {
        Artist::display();
        cout << "Album: " << album << endl;
    }
};

int main()
{
    LanaDelRey lana("Lana Del Rey", "Summertime Sadness", "Born to Die");
    lana.display();

    // Artist *a = new LanaDelRey("Lana Del Rey", "Summertime Sadness", "Born to Die");
    // a->display();
    // delete a;

    return 0;
}