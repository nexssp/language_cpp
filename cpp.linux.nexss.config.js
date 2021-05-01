let languageConfig = Object.assign({}, require("./cpp.win32.nexss.config"));
const sudo = process.sudo;
const distName = process.distro;
languageConfig.dist = distName;

const { vcpkgInstall } = require("./install/installVCPKG");

languageConfig.builders = {
  gcc: {
    install: `${sudo}apt install -y gcc cmake
${vcpkgInstall}`,
    command: "g++",
    build: () => {
      return "g++";
    },
    args: `-std=c++17 -isystem ${process.env.NEXSS_APPS_PATH}/vcpkg/installed/${process.arch}-linux/include -o <destinationFile> <file> && <destinationFile>`,
    help: ``,
  },

  //   "g++": {
  //     install: `${sudo}apt install -y llvm
  // ${vcpkgInstall}`,
  //     command: "g++",
  //     args: "-o <file>.exe && <file>.exe && rm <file>.exe",
  //     help: ``,
  //   },
};

switch (distName) {
  case process.distros.AMAZON:
  case process.distros.AMAZON_AMI:
    languageConfig.builders.gcc.install = `${sudo}yum -y  groupinstall "Development Tools"
yum install -y gcc72-c++
${vcpkgInstall}`;
    break;
  case process.distros.CENTOS:
    // languageConfig.builders.gcc.install += ``;
    languageConfig.builders.gcc.args = `-o <destinationFile> <file> && <destinationFile>`;
    break;
  case process.distros.UBUNTU:
  case process.distros.DEBIAN:
    languageConfig.builders.gcc.install =
      `${sudo}apt update && apt-get install -y software-properties-common
${sudo}add-apt-repository ppa:ubuntu-toolchain-r/test -y
${sudo}apt-get update -y
${sudo}apt-get install -y build-essential g++-7 ` +
      languageConfig.builders.gcc.install;
    //     languageConfig.builders["g++"].install =
    //       `${sudo}apt-get update -y
    // ${sudo}apt-get install -y build-essential g++\n` +
    //       languageConfig.builders["g++"].install;
    break;
  case process.distros.ORACLE:
    languageConfig.builders.gcc.install =
      `${sudo}apt-get update -y
${sudo}apt-get install -y gcc-c++ cmake make ncurses-devel\n` +
      languageConfig.builders.gcc.install;
    //     languageConfig.builders["g++"].install += `
    // ${sudo}apt-get install -y gcc-c++`;
    break;
  case process.distros.ARCH:
    languageConfig.builders.gcc.install =
      `
${sudo}apt-get install -y gcc-c++\n` + languageConfig.builders.gcc.install;
    //     languageConfig.builders["g++"].install = `
    // ${sudo}apt-get install -y gcc-c++`;
    break;
  default:
    break;
}

languageConfig.builders.gcc.install = process.replacePMByDistro(
  languageConfig.builders.gcc.install
);

// languageConfig.builders["g++"].install = os.replacePMByDistro(
//   languageConfig.builders["g++"].install
// );

module.exports = languageConfig;
