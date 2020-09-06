let languageConfig = Object.assign({}, require("./cpp.win32.nexss.config"));

languageConfig.builders = {
  gcc: {
    install: "apt install gcc",
    command: "g++",
    build: () => {
      return "g++";
    },
    args: `-std=c++17 -o <destinationFile> <file> && <destinationFile>`,
    help: ``,
  },
  "g++": {
    install: "apt install llvm",
    command: "g++",
    args: "-o <file>.exe && <file>.exe && rm <file>.exe",
    help: ``,
  },
};

module.exports = languageConfig;
