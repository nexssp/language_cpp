// additional operations for templates like copy extra libraries.
const { vcpkgInstall } = require("../install/installVCPKG");
function getInstaller() {
  switch (process.platform) {
    case "win32":
      return "vcpkg install rapidjson";
    case "linux":
      switch (process.distro) {
        case process.distros.ARCH:
          return process.replacePMByDistro(
            "pacman -S --noconfirm -y rapidjson"
          );
        case process.distros.FEDORA:
          return process.replacePMByDistro("dnf install -y rapidjson-devel");

        case process.distros.AMAZON:
        case process.distros.AMAZON_AMI:
          return `${process.sudo}yum -y  groupinstall "Development Tools"
${vcpkgInstall}`;

        default:
          return process.replacePMByDistro("apt install -y rapidjson*");
      }

    case "darwin":
      return "brew install rapidjson-dev";
    default:
      console.error(`${process.platform} is not implemented.`);
      return ""
  }
}

const config = {
  files: [],
  commands: [getInstaller()],
  repos: ["https://github.com/Tencent/rapidjson.git"],
  descriptions: [
    "Rapid json has been installed. License information here: https://github.com/Tencent/rapidjson.git",
  ],
};

module.exports = config;
