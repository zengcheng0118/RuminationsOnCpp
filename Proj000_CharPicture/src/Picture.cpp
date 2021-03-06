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

    return *this;
}

void Picture::display() const
{
    for (int i = 0; i < height(); i++)
    {
        p->printLine(std::cout, i);
        std::cout << std::endl;
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

bool Picture::printLine(ostream & os, int line) const
{
    if (line >= height())
        return false;
    p->printLine(os, line);
    return true;
}

Picture Picture::deframe() const
{
    if (!p->hasFrame())
        return *this;
    
    return ((FramePicNode *)p)->pic;
}

Picture::Picture(PicNode* p_):p(p_)
{}

Picture frame(const Picture& pic)
{
    if (nullptr == pic.p)
    {
        throw "Enpty Picture Can't add frame\n";
    }
    return Picture(new FramePicNode(pic));
}

Picture deframe(const Picture& pic)
{
    if (nullptr == pic.p)
    {
        throw "Enpty Picture Can't delete frame\n";
    }
    return pic.deframe();
}

Picture hJoinPicture(const Picture & pic1, const Picture & pic2)
{
    return Picture(new HJoinPicNode(pic1, pic2));
}

Picture vJoinPicture(const Picture & pic1, const Picture & pic2)
{
    return Picture(new VJoinPicNode(pic1, pic2));
}
