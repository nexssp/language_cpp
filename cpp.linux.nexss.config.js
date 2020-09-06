let languageConfig = Object.assign({}, require("./cpp.win32.nexss.config"));
let sudo = "sudo ";
if (process.getuid && process.getuid() === 0) {
  sudo = "";
}
languageConfig.builders = {
  gcc: {
    install: `${sudo}apt install -y gcc`,
    command: "g++",
    build: () => {
      return "g++";
    },
    args: `-std=c++17 -o <destinationFile> <file> && <destinationFile>`,
    help: ``,
  },
  "g++": {
    install: `${sudo}apt install -y llvm`,
    command: "g++",
    args: "-o <file>.exe && <file>.exe && rm <file>.exe",
    help: ``,
  },
};

module.exports = languageConfig;
