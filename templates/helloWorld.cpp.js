// additional operations for templates like copy extra libraries.

function getInstaller() {
  switch (process.platform) {
    case "win32":
      return "vcpkg install rapidjson";
    case "linux":
      // This can be also done by checking the root process.getuid && process.getuid() === 0;
      return "is_user_root () { [ ${EUID:-$(id -u)} -eq 0 ]; }; if is_user_root; then apt install -y rapidjson-dev; else sudo apt install -y rapidjson-dev ; fi ;";
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
