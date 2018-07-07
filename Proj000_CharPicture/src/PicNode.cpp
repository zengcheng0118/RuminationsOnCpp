#include "PicNode.h"
#include <string.h>

using namespace std;

namespace
{
    #define MAX(a, b) ((a) >= (b) ? (a) : (b))
    int total = 0;
}

PicNode::PicNode():count(1)
{
    ++total;
    cout << "[tatal:" << total << "]" << " Create PicNode" << endl;
}

PicNode::~PicNode()
{
    --total;
    cout << "[tatal:" << total << "]" << " Delete PicNode" << endl;
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
}

OrigPicNode::~OrigPicNode()
{
    delete[] data;
}

int OrigPicNode::getHeight() const
{
    return height;
}

int OrigPicNode::getWeith() const
{
    return weith;
}

void OrigPicNode::printLine(ostream &os, int line) const
{
    char *temp = getLineStartPtr(line);
    for (int i = 0; i < weithArr[line]; i++)
    {
        os << temp[i];
    }
    os << std::endl;
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