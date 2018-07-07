#ifndef PICTURE_H
#define PICTURE_H
#include <iostream>

using std::ostream;
class PicNode;
class Picture
{
    // friend ostream& operator<<(ostream&, const Picture&);
    friend Picture frame(const Picture&);
    friend Picture hJoinPicture(const Picture&, const Picture&);
    friend Picture vJoinPicture(const Picture&, const Picture&);
    friend class FramePicNode;
    friend class HJoinPicNode;
    friend class VJoinPicNode;
public:
    Picture();
    Picture(const char * const *, int);
    Picture(const Picture&);
    ~Picture();

    Picture& operator=(const Picture&);

    void display() const;
    int height() const;
    int weith() const;

private:
    Picture(PicNode*);
    int weith(int line) const;
    bool printLine(ostream & os, int line) const;

private:
    PicNode* p;
};


#endif