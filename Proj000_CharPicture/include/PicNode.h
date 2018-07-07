#ifndef PICNODE_H
#define PICNODE_H
#include <iostream>
#include "Picture.h"

using std::ostream;

class PicNode
{
    friend class Picture;
public:
    PicNode();
    virtual ~PicNode();

protected:    
    virtual int getHeight() const = 0;
    virtual int getWeith() const = 0;
    virtual void printLine(ostream &os, int line) const = 0;

private:
    int count;
};

class OrigPicNode : public PicNode
{
    friend class Picture;    
public:
    OrigPicNode(const char* const*, int);
    virtual ~OrigPicNode();

protected:    
    virtual int getHeight() const;
    virtual int getWeith() const;
    virtual void printLine(ostream &os, int line) const;
    char* getLineStartPtr(int line) const;

private:
    char *data;
    int height;
    int weith;
    int *weithArr;
};

class FramePicNode : public PicNode
{
    friend class Picture;

public:
    FramePicNode(const Picture &pic_);
    virtual ~FramePicNode();

protected:    
    virtual int getHeight() const;
    virtual int getWeith() const;
    virtual void printLine(ostream &os, int line) const;

private:
    Picture pic;
};

class HJoinPicNode : public PicNode
{
    friend class Picture;

public:
    HJoinPicNode(const Picture &pic1_, const Picture &pic2_);
    virtual ~HJoinPicNode();

protected:    
    virtual int getHeight() const;
    virtual int getWeith() const;
    virtual void printLine(ostream &os, int line) const;

private:
    Picture pic1;
    Picture pic2;
};
#endif