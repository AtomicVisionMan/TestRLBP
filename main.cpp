/**
Yoti Senior Research Engineer Test

The assignment is to implement a simple version of a Robust Local Binary Pattern.
http://www.bmva.org/bmvc/2013/Papers/paper0122/paper0122.pdf

The program will follow the following constraints:
1. It will be a C or C++ program that will implement an RLBP of 8,1 architecture as described on the above paper.

2. It will be a command-line program that takes 2 arguments. The first argument will be an existing source image and the second argument will be the output file location that will store the histogram of the generated RLBP.

*/


#include <iostream>
#include <fstream>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "LBP.hpp"

using namespace std;
using namespace cv;
using namespace lbp;

int main(int argc, char* argv[])
{
	// Only two input arguments are needed according to requirements
	if( argc != 3 )
	{
		cout << "Wrong number of input arguments!" << endl;
		cout << "	Usage: " << argv[0] << " <src_img> <out_file>" << endl;
		return 1;
	}

	Mat src, img, grey;
	img = imread(argv[1]);
	string outHistFile = argv[2];
	
	cout << img.cols << "," << img.rows << endl;
	// convert to grey scale
	cvtColor(img, grey, CV_BGR2GRAY);

	int rad = 1;
	int pts = 8;
	string mapping = "u2";
	string mapFileName = "map_" + mapping + ".txt";
	bool normalizeHist = false;
	
	// RLBP codes here
	LBP lbp(pts, LBP::strToType( mapping ));
	lbp.calcLBP( grey, rad, true );

	// Output histogram
	// Calculate Fourier tranformed histogram
	vector<double> hist = lbp.calcHist().getHist( normalizeHist );
	ofstream ofs;
	ofs.open( (outHistFile), ios::out );
	for( int i = 0; i < hist.size(); i++ ) {
		if( i > 0 ) ofs << ", ";
		ofs << hist[i];
	}
	ofs << endl;
	ofs.close();

	lbp.saveMapping(mapFileName);
	
	return 0;
}

