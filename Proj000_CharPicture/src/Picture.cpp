#include "Picture.h"
#include "PicNode.h"

Picture::Picture():p(nullptr)
{}

Picture::Picture(const char* const* initCharArr, int lineNum):p(new OrigPicNode(initCharArr, lineNum))
{}

Picture::Picture(const Picture& pic):p(pic.p)
{
    if (p != nullptr)
    {
        ++(p->count);
    }
}

Picture::~Picture()
{
    if ((p != nullptr) && (0 == --p->count))
    {
        delete p;
    }
}

Picture& Picture::operator=(const Picture& pic)
{
    if (pic.p != nullptr)
    {
        ++(pic.p->count);
    }
    if ((p != nullptr) && (0 == --(p->count)))
    {
        delete p;
    }

    p = pic.p;
}

void Picture::display() const
{
    for (int i = 0; i < height(); i++)
    {
        p->printLine(std::cout, i);
    }
}

int Picture::height() const
{
    return p->getHeight();
}

int Picture::weith() const
{
    return p->getWeith();
    
}

// Picture::Picture(PicNode* p_):p(p_)
// {}

// Picture& frame(const Picture& pic)
// {
//     if (nullptr == pic.p)
//     {
//         throw "Enpty Picture Can't add frame\n";
//     }
//     return Picture(new FramePicNode(pic.p));
// }