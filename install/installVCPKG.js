const sudo = process.sudo;

let extraPackages = "";
switch (process.distro) {
  case process.distros.UBUNTU:
    extraPackages = "build-essential";
    break;
}

const vcpkgInstall = `echo Installing package manager vcpkg..
if ! command -v git &> /dev/null; then ${sudo}apt-get install -y git; fi
if [ ! -d ${process.env.NEXSS_APPS_PATH}/vcpkg ] ; then git clone https://github.com/microsoft/vcpkg ${process.env.NEXSS_APPS_PATH}/vcpkg --depth=1 ; fi
${sudo}apt-get install ${extraPackages} curl unzip tar cmake 
if ! command -v vcpkg &> /dev/null; then ${process.env.NEXSS_APPS_PATH}/vcpkg/bootstrap-vcpkg.sh; fi
if ! command -v vcpkg &> /dev/null; then cd ${process.env.NEXSS_APPS_PATH}/vcpkg; fi
if ! command -v vcpkg &> /dev/null; then ${sudo}ln -s $(pwd)/vcpkg /usr/bin/vcpkg; fi
if ! command -v vcpkg &> /dev/null; then ${sudo}vcpkg integrate install; fi`;

module.exports = { vcpkgInstall };
