#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

/**********Program**********/

 //TODO£º
class Box
{
private:
    int length;
    int width;
	int height;
public:
    Box()
    {
        length = 1;
        width = 1;
        height = 1;
    }

    Box(int l, int w)
    {
        length = l;
        width = w;
        height = 1;
    }

    Box(int l, int w, int h)
    {
        length = l;
        width = w;
        height = h;
	}

    int Volume()
    {
		return length * width * height;
    }

    int print()
    {
        cout << "length: " << length << endl
            << "width: " << width << endl
            << "height: " << height << endl;
        
        return 0;
     }
};

/**********  End  **********/

void wwjt(Box b1, Box b2, Box b3);

void main()

{
    Box box1, box2(10, 20), box3(15, 15, 15);

    box1.print();

    box1.Volume();

    box2.print();

    box2.Volume();

    box3.print();

    box3.Volume();



    wwjt(box1, box2, box3);

}

void wwjt(Box b1, Box b2, Box b3)

{
    fstream myfile;

    myfile.open("out.txt", ios::out);

    myfile << b1.Volume() << endl;

    myfile << b2.Volume() << endl;

    myfile << b3.Volume() << endl;

    myfile.close();
}

