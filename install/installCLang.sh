# Ubuntu and Debian
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -
sudo apt-add-repository "deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-6.0 main"
sudo apt-get update
sudo apt-get install -y clang-6.0


# update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-3.8 100
# update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-6.0 1000
# update-alternatives --install /usr/bin/clang++ clang /usr/bin/clang-3.8 100
# update-alternatives --install /usr/bin/clang clang /usr/bin/clang-3.8 100
# update-alternatives --install /usr/bin/clang clang /usr/bin/clang-6.0 1000
# update-alternatives --config clang
# update-alternatives --config clang++