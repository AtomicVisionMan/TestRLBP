/**
Yoti Senior Research Engineer Test

The assignment is to implement a simple version of a Robust Local Binary Pattern.
http://www.bmva.org/bmvc/2013/Papers/paper0122/paper0122.pdf

The program will follow the following constraints:
1. It will be a C or C++ program that will implement an RLBP of 8,1 architecture as described on the above paper.

2. It will be a command-line program that takes 2 arguments. The first argument will be anexisting source image and the second argument will be the output file location that will store the histogram of the generated RLBP.

*/


#include <iostream>
#include <fstream>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	// Only two input arguments are needed according to requirements
	if( argc != 2 )
	{
		cout << "Wrong number of input arguments!" << endl;
		cout << "	Usage: " << argv[0] << " <src_img> <out_file>" << endl;
		return 1;
	}

	Mat src, img, grey;
	img = imread(argv[1]);

	// convert to grey scale
	cvtColor(img, grey, CV_BGR2GRAY);

	// RLBP codes here

	// Output codes

	return 0;
}

