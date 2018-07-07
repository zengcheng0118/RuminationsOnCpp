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

    Picture pic4(frame(pic));
    pic4.display();

    Picture pic5(frame(pic4));
    pic5.display();

    return 0;
}