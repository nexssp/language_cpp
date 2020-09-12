let languageConfig = Object.assign({}, require("./cpp.win32.nexss.config"));
let sudo = "sudo ";
if (process.getuid && process.getuid() === 0) {
  sudo = "";
}

const {
  replaceCommandByDist,
  dist,
  version,
} = require(`${process.env.NEXSS_SRC_PATH}/lib/osys`);

const distName = dist();
languageConfig.dist = distName;

languageConfig.builders = {
  gcc: {
    install: replaceCommandByDist(`${sudo}apt install -y gcc`),
    command: "g++",
    build: () => {
      return "g++";
    },
    args: `-std=c++17 -o <destinationFile> <file> && <destinationFile>`,
    help: ``,
  },
  "g++": {
    install: replaceCommandByDist(`${sudo}apt install -y llvm`),
    command: "g++",
    args: "-o <file>.exe && <file>.exe && rm <file>.exe",
    help: ``,
  },
};

if (distName === "Ubuntu" || distName === "Debian") {
  languageConfig.builders.gcc.install += " build-essential";
  languageConfig.builders["g++"].install += " build-essential";
} else if (distName === "Oracle Linux Server") {
  languageConfig.builders.gcc.install += " gcc-c++";
  languageConfig.builders["g++"].install += " gcc-c++";
}

switch (
  distName
  // case "Oracle":
  // case "Oracle Linux Server":
  //   if (version) {
  //     //if here for older versions of nexssp
  //     const distVersion = version(); // *1 converts to number
  //     if (distVersion >= 8) {
  //       // TODO: recognize the slim version
  //       languageConfig.builders.gcc.install = `dnf update -y && ${sudo}dnf install -y php php-json php-imap`;
  //     } else {
  //       languageConfig.builders.gcc.install = `${sudo}yum update -y && ${sudo}yum install -y oracle-epel-release* && ${sudo}yum install -y php php-json php-imap`;
  //     }
  //   }
  //   break;
  // case "Alpine Linux":
  //   languageConfig.builders.gcc.install = `${sudo}apk add php php7-json php-imap`;
  //   break;
  // case "Arch Linux":
  //   languageConfig.builders.gcc.install = `${sudo}pacman -Sy --noconfirm php php-imap`;
  //   break;
  // case "Fedora":
  //   languageConfig.builders.gcc.install = `${sudo}dnf install -y php php-json php-imap`;
  //   break;
  // case "CentOS Linux":
  //   languageConfig.builders.gcc.install = `${sudo}yum install -y epel-release* && yum install -y php php-json php-imap`;
  //   break;
  // case "RHEL Linux":
  //   languageConfig.builders.gcc.install = `${sudo}yum install -y php php-json php-imap`;
  //   break;
) {
}

module.exports = languageConfig;
