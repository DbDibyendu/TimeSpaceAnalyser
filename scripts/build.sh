apt-get install -y swig cmake
rm -rf build
mkdir build && cd build 
cmake ../
make 
sudo make install
sudo make pyinstall
