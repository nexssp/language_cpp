// additional operations for templates like copy extra libraries.
const config = {
  files: [],
  commands: ["vcpkg install rapidjson"],
  repos: ["https://github.com/Tencent/rapidjson.git"],
  descriptions: [
    "Rapid json has been installed. License information here: https://github.com/Tencent/rapidjson.git"
  ]
};

module.exports = config;
