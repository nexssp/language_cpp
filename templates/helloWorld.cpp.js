// additional operations for templates like copy extra libraries.

function getInstaller() {
  switch (process.platform) {
    case "win32":
      return "vcpkg install rapidjson";
    case "linux":
      return 'is_user_root () { [ ${EUID:-$(id -u)} -eq 0 ]; }; if is_user_root; then apt install rapidjson-dev; else echo "\\e[1m\\e[33mPlease run as root to install rapidjson-dev or install it by \nsudo apt install rapidjson-dev\\e[0m" ; exit 1 ; fi ;';
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
