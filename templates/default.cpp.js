// additional operations for templates like copy extra libraries.

function getInstaller() {
  const os = require("@nexssp/os"); // this is included in main nexss programmer cli: @nexssp/cli

  switch (process.platform) {
    case "win32":
      return "vcpkg install rapidjson";
    case "linux":
      const {
        dist,
        replaceCommandByDist,
      } = require(`${process.env.NEXSS_SRC_PATH}/lib/osys`);

      switch (dist()) {
        case os.distros.ARCH:
          return replaceCommandByDist("pacman -S --noconfirm -y rapidjson");
        case os.distros.FEDORA:
          return replaceCommandByDist("dnf install -y rapidjson-devel");
        default:
          return replaceCommandByDist("apt install -y rapidjson*");
      }

    case "darwin":
      return "brew install rapidjson-dev";
    default:
      console.error(`${process.platform} is not implemented.`);
      break;
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
