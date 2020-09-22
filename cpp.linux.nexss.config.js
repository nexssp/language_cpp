let languageConfig = Object.assign({}, require("./cpp.win32.nexss.config"));
const os = require("@nexssp/os");
const sudo = os.sudo();
const {
  replaceCommandByDist,
  dist,
  version,
} = require(`${process.env.NEXSS_SRC_PATH}/lib/osys`);

const distName = os.name();
languageConfig.dist = distName;

const vcpkgInstall = `echo Installing package manager vcpkg..
git clone https://github.com/microsoft/vcpkg ${process.env.NEXSS_APPS_PATH}/vcpkg
${sudo}apt-get install curl unzip tar
${process.env.NEXSS_APPS_PATH}/vcpkg/bootstrap-vcpkg.sh
cd ${process.env.NEXSS_APPS_PATH}/vcpkg
${sudo}ln -s $(pwd)/vcpkg /usr/bin/vcpkg`;

languageConfig.builders = {
  gcc: {
    install: os.replacePMByDistro(`${sudo}apt install -y gcc
${vcpkgInstall}`),
    command: "g++",
    build: () => {
      return "g++";
    },
    args: `-std=c++17 -o <destinationFile> <file> && <destinationFile>`,
    help: ``,
  },
  "g++": {
    install: os.replacePMByDistro(`${sudo}apt install -y llvm
${vcpkgInstall}`),
    command: "g++",
    args: "-o <file>.exe && <file>.exe && rm <file>.exe",
    help: ``,
  },
};

switch (distName) {
  case os.distros.UBUNTU:
  case os.distros.DEBIAN:
    languageConfig.builders.gcc.install += `
${sudo}apt-get install build-essential g++`;
    languageConfig.builders["g++"].install += `
${sudo}apt-get install build-essential g++`;
    break;
  case os.distros.ORACLE:
    languageConfig.builders.gcc.install += `
${sudo}apt-get install gcc-c++`;
    languageConfig.builders["g++"].install += `
${sudo}apt-get install gcc-c++`;
  case os.distros.ARCH:
    languageConfig.builders.gcc.install += `
${sudo}apt-get install gcc-c++`;
    languageConfig.builders["g++"].install += `
${sudo}apt-get install gcc-c++`;
  default:
    break;
}

module.exports = languageConfig;
