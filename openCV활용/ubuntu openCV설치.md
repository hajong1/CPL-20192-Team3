Step 1. 필요한 패키지 다운로드
----
# Build tools & required
$ sudo apt install build-essential cmake git pkg-config

# For still images
$ sudo apt install libjpeg-dev libtiff5-dev libjasper-dev libpng-dev

# For videos
$ sudo apt install libavcodec-dev libavformat-dev libswscale-dev
$ sudo apt install libdc1394-22-dev libxvidcore-dev libx264-dev x264
$ sudo apt install libxine2-dev libv4l-dev v4l-utils
$ sudo apt install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev

# GUI
$ sudo apt install libgtk-3-dev

# Optimization, Python3, etc.
$ sudo apt install libatlas-base-dev libeigen3-dev gfortran
$ sudo apt install python3-dev python3-numpy libtbb2 libtbb-dev


Step 2. OpenCV 3.4.0 소스 코드 다운로드
----
# Create a working directory named opencv
$ cd ~
$ mkdir opencv
$ cd opencv

# Download sources
$ wget -O opencv-3.4.0.zip https://github.com/opencv/opencv/archive/3.4.0.zip
$ wget -O opencv_contrib-3.4.0.zip https://github.com/opencv/opencv_contrib/archive/3.4.0.zip

# Unpack
$ unzip opencv-3.4.0.zip
$ unzip opencv_contrib-3.4.0.zip

Step 3. CMake를 이용하여 Makefile 생성
----
# Create a build directory
$ mkdir build && cd build

# Run CMake
$ cmake \
-D CMAKE_BUILD_TYPE=Release \
-D CMAKE_INSTALL_PREFIX=/usr/local \
-D BUILD_WITH_DEBUG_INFO=OFF \
-D BUILD_EXAMPLES=ON \
-D BUILD_opencv_python2=OFF \
-D BUILD_opencv_python3=ON \
-D INSTALL_PYTHON_EXAMPLES=ON \
-D OPENCV_EXTRA_MODULES_PATH=../opencv_contrib-3.4.0/modules \
-D WITH_TBB=ON \
-D WITH_V4L=ON \
../opencv-3.4.0/ 2>&1 | tee cmake_messages.txt


Step 4. 컴파일 및 설치
----
# find out the number of CPU cores in your machine
$ nproc

# substitute 2 after -j by the output of nproc
$ make -j2 2>&1 | tee build_messages.txt
$ sudo make install
$ sudo ldconfig

# If the output of next command is '3.4.0' then it's ok!
$ pkg-config --modversion opencv


출처 : https://kkokkal.tistory.com/1328
