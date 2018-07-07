#include <iostream>
#include "Picture.h"

using namespace std;
int main(int argc, char **argv)
{
    const char* init[] = {"It's ", "a", "picture"};
    Picture pic(init, 3);
    pic.display();

    Picture pic2(pic);
    pic2.display();

    Picture pic3;
    pic3 = pic2;
    pic3.display();

    //////////////////////////////////
    Picture pic4(frame(pic));
    pic4.display();

    Picture pic5(frame(pic4));
    pic5.display();

    //////////////////////////////////
    Picture pic6(hJoinPicture(pic3, pic4));
    pic6.display();
    frame(pic6).display();

    Picture pic7(vJoinPicture(pic5, pic6));
    pic7.display();
    frame(pic7).display();

    return 0;
}