## TestRLBP

### Introduction
I was given an assignment as part of a interview process, to 
> implement a simple version of a Robust Local Binary Pattern. 
> as described in http://www.bmva.org/bmvc/2013/Papers/paper0122/paper0122.pdf

The programme has the following constraints:
>- It will be a C or C++ program that will implement an RLBP of 8,1 architecture as described on the above paper.

>- It will be a command-line program that takes 2 arguments. The first argument will be anexisting source image and the second argument will be the output file location that will store the histogram of the generated RLBP.

The other major requirements have been:
>- Save the progress in a git repository - coundn't agree more! and what's better than github?!
>- Use GNU Make tools or CMake - I've abandoned Make files (sort of) for a long while. since the machines I use include . Have to be CMake.



### Day 1 (July 2)
I've got the assignment rather late due to some agency issues. Have to manage it over weekend somehow steal some time here and there.

The tasks for first day then:

1) Register a new test account on github and create test project for RLBP - done!

2) Create a shell application locally with basic functionalities like load and save images etc. - done!

3) Set up CMake environment for the project (i.e. simplest CMakeLists.txt with total 12 lines including 3 empty lines) - done!

4) Commit to github repo - done!

5) Read the paper - to do...

6) Compile OpenCV 3 on MBP (OSX 10.9.5, Xcode 6.1) - to do...

```
NOTE: Regarding the last point, OpenCV version 3 is not necessary. Just since v3 is officially out for more than one year, maybe I should take this opportunity to catch up a bit. Hopefully not too much interface changes, again...
```

### Day 2 (July 3)
No coding done. Just read paper and some online articles regarding LBP.

### Day 3 (July 4)
First a quick recap of what learnt over weekend.

1). loads resources available online as expected. I read the following into different extent of details. It's a simple technique anyway.

>- [Local Binary Pattern for texture classification](http://scikit-image.org/docs/dev/auto_examples/plot_local_binary_pattern.html)
>- [Local Binary Pattern](http://pi-virtualworld.blogspot.co.uk/2014/01/local-binary-pattern.html)
>- [Texture Matching using Local Binary Patterns (LBP), OpenCV, scikit-learn and Python](http://hanzratech.in/2015/05/30/local-binary-patterns.html)
>- [Local Binary Patterns with Python & OpenCV](http://www.pyimagesearch.com/2015/12/07/local-binary-patterns-with-python-opencv/)

2). Original LBP
>- Local binary pattern binarizes the local neighborhood of each pixel and builds a histogram on these binary neighborhood patterns.
>- It is claimed to be illumination and translation invariant [Texture Matching using Local Binary Patterns (LBP), OpenCV, scikit-learn and Python](http://hanzratech.in/2015/05/30/local-binary-patterns.html)
>- Refer to Eq. (1) in the RLBP paper
>- many, many extensions, as listed in the paper or [wiki](https://en.wikipedia.org/wiki/Local_binary_patterns#cite_note-5)

3). RLBP
> - It seems that this particular extension is to improve on one of the key concept - **_ uniform pattern _**
> - Basically, the authors assume that two particular substrings are very likely caused by noise, therefore simply modify them to smoother version of substring. Namely, from (010)-->(000), and (101)-->(111)
> - This apparently will effect uniform mapping process where this paper claims the primary contribution

4). Codes

NOW the favourite part... Since the total time I can spend on this is really limited, I've decided to go with some existing implementations, shouldn't be too difficult to find!

The first google result returned by "Local Binary Patterns c++" seems reasonable:[C++ implementation of the Local Binary Pattern texture descriptors](https://github.com/nourani/LBP). As the author has noted: 
```
 *  The methods implemented here are inspired by the Matlab code available
 *  from web site of the University of Oulu:
 *  	http://www.cse.oulu.fi/CMV/Downloads/LBPMatlab
```

which are literally a line-by-line translation from the original Matlab implementation to C++ codes.

In fact, I quite like it because:
> - at first glance, appears to be well structured C++ code
> - **Most importantly,** it has the `real` low level LBP implementation rather than a single function call to `local_binary_pattern` as have been done in some of the threads above
> - It has GPU version!! if I've got time...

5). Compilation & Run
> - Got OpenCV installed through MacPorts so LBP class is easy enough to build. 
> - Spent little bit more time on finding the right FFTW3 library for Mac. Eventually job done through MacPorts again.

Day 4 (July 5)
This day just play with codes and examples and parameters of the above listed C++ and python code example.

Now I know the meaning of 'uniform patterns' and mapping table etc.
> - A local binary pattern is called uniform if the binary pattern contains at most two 0-1 or 1-0 transitions [wiki](https://en.wikipedia.org/wiki/Local_binary_patterns)
> - In original Matlab implementation (hence C++ version too), this is done by a nice little trick as `the number of 1-bits in XOR(x,Rotate left(x))`
> - Now for the RLBP extension, once a non-uniform pattern is found, then search for all of its neighboring three-bit of (010) and (101) - done!!

Day 5 (July 6)
Implemented the above solution and update the git repo.




