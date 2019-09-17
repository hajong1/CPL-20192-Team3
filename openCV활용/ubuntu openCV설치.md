Step 1. 필요한 패키지 다운로드
----
### Build tools & required
$ sudo apt install build-essential cmake git pkg-config

### For still images
$ sudo apt install libjpeg-dev libtiff5-dev libjasper-dev libpng-dev

### For videos
$ sudo apt install libavcodec-dev libavformat-dev libswscale-dev<br>
$ sudo apt install libdc1394-22-dev libxvidcore-dev libx264-dev x264<br>
$ sudo apt install libxine2-dev libv4l-dev v4l-utils<br>
$ sudo apt install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev

### GUI
$ sudo apt install libgtk-3-dev

### Optimization, Python3, etc.
$ sudo apt install libatlas-base-dev libeigen3-dev gfortran<br>
$ sudo apt install python3-dev python3-numpy libtbb2 libtbb-dev<br>
<br>
<br>

Step 2. OpenCV 3.4.0 소스 코드 다운로드
----
### Create a working directory named opencv
$ cd ~<br>
$ mkdir opencv<br>
$ cd opencv<br>

### Download sources
$ wget -O opencv-3.4.0.zip https://github.com/opencv/opencv/archive/3.4.0.zip<br>
$ wget -O opencv_contrib-3.4.0.zip https://github.com/opencv/opencv_contrib/archive/3.4.0.zip<br>

### Unpack
$ unzip opencv-3.4.0.zip<br>
$ unzip opencv_contrib-3.4.0.zip<br>
<br>
<br>

Step 3. CMake를 이용하여 Makefile 생성
----
### Create a build directory
$ mkdir build && cd build

### Run CMake
$ cmake \\<br>
-D CMAKE_BUILD_TYPE=Release \\<br>
-D CMAKE_INSTALL_PREFIX=/usr/local \\<br>
-D BUILD_WITH_DEBUG_INFO=OFF \\<br>
-D BUILD_EXAMPLES=ON \\<br>
-D BUILD_opencv_python2=OFF \\<br>
-D BUILD_opencv_python3=ON \\<br>
-D INSTALL_PYTHON_EXAMPLES=ON \\<br>
-D OPENCV_EXTRA_MODULES_PATH=../opencv_contrib-3.4.0/modules \\<br>
-D WITH_TBB=ON \\<br>
-D WITH_V4L=ON \\<br>
../opencv-3.4.0/ 2>&1 | tee cmake_messages.txt<br>
<br>
<br>

Step 4. 컴파일 및 설치
----
### find out the number of CPU cores in your machine
$ nproc

### substitute 2 after -j by the output of nproc
$ make -j2 2>&1 | tee build_messages.txt<br>
$ sudo make install<br>
$ sudo ldconfig<br>

### If the output of next command is '3.4.0' then it's ok!
$ pkg-config --modversion opencv<br>
<br>
<br>
<br>


출처 : https://kkokkal.tistory.com/1328
