let languageConfig = Object.assign({}, require("./cpp.win32.nexss.config"));
const sudo = process.sudo;
const distName = process.distro;
languageConfig.dist = distName;


languageConfig.builders = {
  gcc: {
    install: `pkg install -y clang`,
    command: "g++",
    build: () => {
      return "g++";
    },
    // args: `-std=c++17 -isystem ${process.env.NEXSS_APPS_PATH}/vcpkg/installed/${process.arch}-linux/include -o <destinationFile> <file> && <destinationFile>`,
    args: `-std=c++17 -o <destinationFile> <file> && <destinationFile>`,
    help: ``,
  },

};

module.exports = languageConfig;
