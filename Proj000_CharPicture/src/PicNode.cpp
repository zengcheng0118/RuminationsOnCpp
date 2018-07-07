#include "PicNode.h"
#include <string.h>

using namespace std;

namespace
{
    #define MAX(a, b) ((a) >= (b) ? (a) : (b))
    int totalCount = 0;
}

PicNode::PicNode():count(1)
{
}

PicNode::~PicNode()
{
}

OrigPicNode::OrigPicNode(const char * const * initCharArr, int lineNum):data(nullptr), height(lineNum), weith(0), weithArr(new int[lineNum])
{
    int total = 0;
    for (int i = 0; i < lineNum; ++i)
    {
        weithArr[i] = strlen(initCharArr[i]);
        total += weithArr[i];
        weith = MAX(weith, weithArr[i]);
    }

    data = new char[total];

    int offset = 0;
    for (int i = 0; i < lineNum; ++i)
    {
        strncpy(data + offset, initCharArr[i], weithArr[i]);
        offset += weithArr[i];
    }

    ++totalCount;
    cout << "[totalCount:" << totalCount << "]" << " Create OrigPicNode" << endl;
}

OrigPicNode::~OrigPicNode()
{
    delete[] data;
    --totalCount;
    cout << "[totalCount:" << totalCount << "]" << " Delete OrigPicNode" << endl;
}

int OrigPicNode::getHeight() const
{
    return height;
}

int OrigPicNode::getWeith() const
{
    return weith;
}

int OrigPicNode::getWeith(int line) const
{
    return weithArr[line];
}

void OrigPicNode::printLine(ostream &os, int line) const
{
    char *temp = getLineStartPtr(line);
    for (int i = 0; i < weithArr[line]; i++)
    {
        os << temp[i];
    }

    for (int j = weithArr[line]; j < weith; j++)
    {
        os << ' ';
    }
}

char* OrigPicNode::getLineStartPtr(int line) const
{
    int offset = 0;
    for (int i = 0; i < line; i++)
    {
        offset += weithArr[i];
    }

    return data + offset;
}

FramePicNode::FramePicNode(const Picture &pic_):pic(pic_)
{
    ++totalCount;
    cout << "[totalCount:" << totalCount << "]" << " Create FramePicNode" << endl;
}

FramePicNode::~FramePicNode()
{
    --totalCount;
    cout << "[totalCount:" << totalCount << "]" << " Delete FramePicNode" << endl;
}

int FramePicNode::getHeight() const
{
    return pic.height() + 2;
}

int FramePicNode::getWeith() const
{
    return pic.weith() + 2;
}

int FramePicNode::getWeith(int line) const
{
    return pic.weith() + 2;
}

void FramePicNode::printLine(ostream &os, int line) const
{
    if (0 == line || (getHeight() -1) == line)
    {
        for (int i = 0; i < getWeith(); i++)
        {
            if (0 == i || getWeith()-1 == i)
            {
                os << "+";
            }
            else
                os << "-";
        }
    }
    else
    {
        os << "|";
        // pic.p->printLine(os, line); // TODO(zc) 为什么不能这么访问受保护的接口??
        pic.printLine(os, line-1);
        os << "|";
    }
}