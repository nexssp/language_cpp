let languageConfig = Object.assign({}, require("./cpp.win32.nexss.config"));
const os = require("@nexssp/os");
const sudo = os.sudo();
const distName = os.name();
languageConfig.dist = distName;

const vcpkgInstall = `echo Installing package manager vcpkg..
if [ ! -d ${process.env.NEXSS_APPS_PATH}/vcpkg ] ; then git clone https://github.com/microsoft/vcpkg ${process.env.NEXSS_APPS_PATH}/vcpkg ; fi
${sudo}apt-get install curl unzip tar cmake
${process.env.NEXSS_APPS_PATH}/vcpkg/bootstrap-vcpkg.sh
cd ${process.env.NEXSS_APPS_PATH}/vcpkg
${sudo}ln -s $(pwd)/vcpkg /usr/bin/vcpkg`;

languageConfig.builders = {
  gcc: {
    install: `${sudo}apt install -y gcc cmake
${vcpkgInstall}`,
    command: "g++",
    build: () => {
      return "g++";
    },
    args: `-std=c++17 -o <destinationFile> <file> && <destinationFile>`,
    help: ``,
  },
  "g++": {
    install: `${sudo}apt install -y llvm
${vcpkgInstall}`,
    command: "g++",
    args: "-o <file>.exe && <file>.exe && rm <file>.exe",
    help: ``,
  },
};

switch (distName) {
  case os.distros.CENTOS:
    // languageConfig.builders.gcc.install += ``;
    languageConfig.builders.gcc.args = `-o <destinationFile> <file> && <destinationFile>`;
    break;
  case os.distros.UBUNTU:
  case os.distros.DEBIAN:
    languageConfig.builders.gcc.install += `
${sudo}apt-get install -y build-essential g++`;
    languageConfig.builders["g++"].install += `
${sudo}apt-get install -y build-essential g++`;
    break;
  case os.distros.ORACLE:
    languageConfig.builders.gcc.install += `
${sudo}apt-get install -y gcc-c++ cmake make ncurses-devel`;
    languageConfig.builders["g++"].install += `
${sudo}apt-get install -y gcc-c++`;
    break;
  case os.distros.ARCH:
    languageConfig.builders.gcc.install += `
${sudo}apt-get install -y gcc-c++`;
    languageConfig.builders["g++"].install += `
${sudo}apt-get install -y gcc-c++`;
    break;
  default:
    break;
}

languageConfig.builders.gcc.install = os.replacePMByDistro(
  languageConfig.builders.gcc.install
);

languageConfig.builders["g++"].install = os.replacePMByDistro(
  languageConfig.builders["g++"].install
);

module.exports = languageConfig;
